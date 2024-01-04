#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "example.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using calculator::Calculator;
using calculator::AddRequest;
using calculator::AddResponse;

class CalculatorServiceImpl final : public Calculator::Service {
 public:
  grpc::Status Add(grpc::ServerContext* context, const AddRequest* request,
                   grpc::ServerAsyncResponseWriter<AddResponse>* response_writer,
                   grpc::CompletionQueue* cq, grpc::ServerCompletionQueue* server_cq)  {
    new CallData(this, context, response_writer, cq, server_cq);
    return grpc::Status::OK;
  }

 private:
  class CallData {
   public:
    CallData(CalculatorServiceImpl* service, grpc::ServerContext* context,
             grpc::ServerAsyncResponseWriter<AddResponse>* response_writer,
             grpc::CompletionQueue* cq, grpc::ServerCompletionQueue* server_cq)
        : service_(service),
          context_(context),
          response_writer_(response_writer),
          cq_(cq),
          server_cq_(server_cq),
          status_(CREATE) {
      Proceed();
    }

    void Proceed() {
      if (status_ == CREATE) {
        status_ = PROCESS;
        service_->RequestAdd(&context_, &request_, response_writer_, cq_, server_cq_, cq_, this);
      } else if (status_ == PROCESS) {
        new CallData(service_, context_, response_writer_, cq_, server_cq_);
        AddResponse response;
        response.set_sum(request_.operand1() + request_.operand2());
        response_writer_->Finish(response, grpc::Status::OK, this);
        status_ = FINISH;
      } else if (status_ == FINISH) {
        delete this;
      } else {
        GPR_ASSERT(status_ == CANCEL);
        delete this;
      }
    }

   private:
    CalculatorServiceImpl* service_;
    grpc::ServerContext* context_;
    grpc::ServerAsyncResponseWriter<AddResponse>* response_writer_;
    grpc::CompletionQueue* cq_;
    grpc::ServerCompletionQueue* server_cq_;
    AddRequest request_;
    enum CallStatus { CREATE, PROCESS, FINISH, CANCEL };
    CallStatus status_;
  };
};


void RunServer() {
  std::string server_address("0.0.0.0:50051");
  CalculatorServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  server->Wait();
}

int main() {
  RunServer();
  return 0;
}
