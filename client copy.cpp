#include <iostream>
#include <grpcpp/grpcpp.h>
#include "example.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using example1::Greeter;
using example1::HelloRequest;
using example1::HelloReply;
using example1::WaveformData;
using example1::ack;

class GreeterClient {
public:
  GreeterClient(std::shared_ptr<Channel> channel) : stub_(Greeter::NewStub(channel)) {}

  std::string SayHello(const std::string& name) {
    HelloRequest request;
    request.set_name(name);

    HelloReply reply;
    ClientContext context;

    Status status = stub_->SayHello(&context, request, &reply);

    if (status.ok()) {
      return reply.message();
    } else {
      std::cerr << "RPC failed: " << status.error_code() << ": " << status.error_message() << std::endl;
      return "RPC failed";
    }
  }



  int32_t DrawWaveform(const int32_t wavedata) {
    WaveformData request;
    request.set_wavedata(wavedata);

    ack reply;
    ClientContext context;

    Status status = stub_->DrawWaveform(&context, request, &reply);

    if (status.ok()) {
      return reply.status();
    } else {
      std::cerr << "RPC failed: " << status.error_code() << ": " << status.error_message() << std::endl;
      return 1;
    }
  }


private:
  std::unique_ptr<Greeter::Stub> stub_;
};

int main() {
  GreeterClient client(grpc::CreateChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials()));
  std::string user("Hello, Server");
  std::string response = client.SayHello(user);
  std::cout<< "Sending waveform Data....... Received Response : " << client.DrawWaveform(12)<<std::endl;
  std::cout << "Greeter received: " << response << std::endl;
  return 0;
}
