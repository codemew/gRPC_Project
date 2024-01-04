#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "example.grpc.pb.h"

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;
using calculator::Calculator;
using calculator::AddRequest;
using calculator::AddResponse;

class CalculatorClient {
 public:
  explicit CalculatorClient(std::shared_ptr<Channel> channel)
      : stub_(Calculator::NewStub(channel)) {}

  void Add(int operand1, int operand2) {
    AddRequest request;
    request.set_operand1(operand1);
    request.set_operand2(operand2);

    AsyncClientCall* call = new AsyncClientCall;
    call->response_reader = stub_->AsyncAdd(&call->context, request, &cq_);
    call->response_reader->Finish(&call->response, &call->status, (void*)call);
  }

  void AsyncCompleteRpc() {
    void* got_tag;
    bool ok = false;

    while (cq_.Next(&got_tag, &ok)) {
      AsyncClientCall* call = static_cast<AsyncClientCall*>(got_tag);
      GPR_ASSERT(ok);
      if (call->status.ok()) {
        std::cout << "Sum: " << call->response.sum() << std::endl;
      } else {
        std::cerr << "RPC failed" << std::endl;
      }
      delete call;
    }
  }

 private:
  struct AsyncClientCall {
    AddResponse response;
    grpc::ClientContext context;
    Status status;
    std::unique_ptr<ClientAsyncResponseReader<AddResponse>> response_reader;
  };

  std::unique_ptr<Calculator::Stub> stub_;
  CompletionQueue cq_;
};

int main() {
  CalculatorClient calculator(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

  calculator.Add(10, 20);

  calculator.AsyncCompleteRpc();

  return 0;
}
