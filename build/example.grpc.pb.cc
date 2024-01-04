// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: example.proto

#include "example.pb.h"
#include "example.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace calculator {

static const char* Calculator_method_names[] = {
  "/calculator.Calculator/Add",
};

std::unique_ptr< Calculator::Stub> Calculator::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Calculator::Stub> stub(new Calculator::Stub(channel));
  return stub;
}

Calculator::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Add_(Calculator_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Calculator::Stub::Add(::grpc::ClientContext* context, const ::calculator::AddRequest& request, ::calculator::AddResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Add_, context, request, response);
}

void Calculator::Stub::experimental_async::Add(::grpc::ClientContext* context, const ::calculator::AddRequest* request, ::calculator::AddResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Add_, context, request, response, std::move(f));
}

void Calculator::Stub::experimental_async::Add(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::calculator::AddResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Add_, context, request, response, std::move(f));
}

void Calculator::Stub::experimental_async::Add(::grpc::ClientContext* context, const ::calculator::AddRequest* request, ::calculator::AddResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Add_, context, request, response, reactor);
}

void Calculator::Stub::experimental_async::Add(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::calculator::AddResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Add_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::calculator::AddResponse>* Calculator::Stub::AsyncAddRaw(::grpc::ClientContext* context, const ::calculator::AddRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::calculator::AddResponse>::Create(channel_.get(), cq, rpcmethod_Add_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::calculator::AddResponse>* Calculator::Stub::PrepareAsyncAddRaw(::grpc::ClientContext* context, const ::calculator::AddRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::calculator::AddResponse>::Create(channel_.get(), cq, rpcmethod_Add_, context, request, false);
}

Calculator::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Calculator_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Calculator::Service, ::calculator::AddRequest, ::calculator::AddResponse>(
          std::mem_fn(&Calculator::Service::Add), this)));
}

Calculator::Service::~Service() {
}

::grpc::Status Calculator::Service::Add(::grpc::ServerContext* context, const ::calculator::AddRequest* request, ::calculator::AddResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace calculator

