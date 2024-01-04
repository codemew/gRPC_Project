#include <iostream>
#include <grpcpp/grpcpp.h>
#include "example.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using example1::Greeter;
using example1::HelloRequest;
using example1::HelloReply;
using example1::WaveformData;
using example1::ack;

class GreeterServiceImpl final : public Greeter::Service {
  Status SayHello(ServerContext* context, const HelloRequest* request, HelloReply* reply) override {
    //Received hello Request

    std::cout<<"Received "<<request->name()<< " Request"<<std::endl;
    std::string prefix("Hi Client .... ");
    std::cout<<"Response for "<<request->name()<< " Request"<<std::endl;

    reply->set_message(prefix + request->name());
    return Status::OK;
  }

  Status DrawWaveform(ServerContext* context, const WaveformData* request, ack* response) override
  {
    int32_t wavedata = request->wavedata();

    /* int32_t* waveform = &wavedata;

    for(int i = 0; i<3; i++)
    {
      for(int j = 0; j < 8; j++)
      {
        std::cout<< waveform[i][j]<<std::endl;
      }
    } */
    response->set_status(0);
    std::cout<< " WaveData : " << wavedata << std::endl;
    
    return Status::OK;
  }

};

void RunServer() {
  std::string server_address("127.0.0.1:50051");
  GreeterServiceImpl service;

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
