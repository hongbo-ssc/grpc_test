// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: base.proto
#ifndef GRPC_base_2eproto__INCLUDED
#define GRPC_base_2eproto__INCLUDED

#include "base.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace hello {

class HelloService final {
 public:
  static constexpr char const* service_full_name() {
    return "hello.HelloService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::hello::Name, ::hello::Hello>> sayHelloAndSleep(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::hello::Name, ::hello::Hello>>(sayHelloAndSleepRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::hello::Name, ::hello::Hello>> AsyncsayHelloAndSleep(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::hello::Name, ::hello::Hello>>(AsyncsayHelloAndSleepRaw(context, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::hello::Name, ::hello::Hello>> PrepareAsyncsayHelloAndSleep(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::hello::Name, ::hello::Hello>>(PrepareAsyncsayHelloAndSleepRaw(context, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void sayHelloAndSleep(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::hello::Name,::hello::Hello>* reactor) = 0;
      #else
      virtual void sayHelloAndSleep(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::hello::Name,::hello::Hello>* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientReaderWriterInterface< ::hello::Name, ::hello::Hello>* sayHelloAndSleepRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::hello::Name, ::hello::Hello>* AsyncsayHelloAndSleepRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::hello::Name, ::hello::Hello>* PrepareAsyncsayHelloAndSleepRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReaderWriter< ::hello::Name, ::hello::Hello>> sayHelloAndSleep(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::hello::Name, ::hello::Hello>>(sayHelloAndSleepRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::hello::Name, ::hello::Hello>> AsyncsayHelloAndSleep(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::hello::Name, ::hello::Hello>>(AsyncsayHelloAndSleepRaw(context, cq, tag));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::hello::Name, ::hello::Hello>> PrepareAsyncsayHelloAndSleep(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::hello::Name, ::hello::Hello>>(PrepareAsyncsayHelloAndSleepRaw(context, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void sayHelloAndSleep(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::hello::Name,::hello::Hello>* reactor) override;
      #else
      void sayHelloAndSleep(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::hello::Name,::hello::Hello>* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientReaderWriter< ::hello::Name, ::hello::Hello>* sayHelloAndSleepRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::hello::Name, ::hello::Hello>* AsyncsayHelloAndSleepRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReaderWriter< ::hello::Name, ::hello::Hello>* PrepareAsyncsayHelloAndSleepRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_sayHelloAndSleep_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status sayHelloAndSleep(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::hello::Hello, ::hello::Name>* stream);
  };
  template <class BaseClass>
  class WithAsyncMethod_sayHelloAndSleep : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_sayHelloAndSleep() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_sayHelloAndSleep() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sayHelloAndSleep(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::hello::Hello, ::hello::Name>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestsayHelloAndSleep(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::hello::Hello, ::hello::Name>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_sayHelloAndSleep<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_sayHelloAndSleep : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_sayHelloAndSleep() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc::internal::CallbackBidiHandler< ::hello::Name, ::hello::Hello>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context) { return this->sayHelloAndSleep(context); }));
    }
    ~ExperimentalWithCallbackMethod_sayHelloAndSleep() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sayHelloAndSleep(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::hello::Hello, ::hello::Name>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerBidiReactor< ::hello::Name, ::hello::Hello>* sayHelloAndSleep(
      ::grpc::CallbackServerContext* /*context*/)
    #else
    virtual ::grpc::experimental::ServerBidiReactor< ::hello::Name, ::hello::Hello>* sayHelloAndSleep(
      ::grpc::experimental::CallbackServerContext* /*context*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_sayHelloAndSleep<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_sayHelloAndSleep<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_sayHelloAndSleep : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_sayHelloAndSleep() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_sayHelloAndSleep() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sayHelloAndSleep(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::hello::Hello, ::hello::Name>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_sayHelloAndSleep : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_sayHelloAndSleep() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_sayHelloAndSleep() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sayHelloAndSleep(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::hello::Hello, ::hello::Name>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestsayHelloAndSleep(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_sayHelloAndSleep : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_sayHelloAndSleep() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackBidiHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context) { return this->sayHelloAndSleep(context); }));
    }
    ~ExperimentalWithRawCallbackMethod_sayHelloAndSleep() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sayHelloAndSleep(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::hello::Hello, ::hello::Name>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerBidiReactor< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* sayHelloAndSleep(
      ::grpc::CallbackServerContext* /*context*/)
    #else
    virtual ::grpc::experimental::ServerBidiReactor< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* sayHelloAndSleep(
      ::grpc::experimental::CallbackServerContext* /*context*/)
    #endif
      { return nullptr; }
  };
  typedef Service StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef Service StreamedService;
};

}  // namespace hello


#endif  // GRPC_base_2eproto__INCLUDED
