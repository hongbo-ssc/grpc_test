
#include <iostream>
#include <vector>
#include <thread>

#include <grpc/grpc.h>
#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/credentials.h>

#include "./protoc-code/base.grpc.pb.h"
#include "./protoc-code/base.pb.h"

using hello::HelloService;
using hello::Name;
using hello::Hello;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerWriter;
using grpc::ServerReaderWriter;
using grpc::Status;

using namespace std;


vector<Name> names;
class HelloImpl final : public HelloService::Service {
    public:
     Status sayHelloAndSleep (ServerContext* context,ServerReaderWriter<Hello,Name>* stream) override {
        Name name;
        while (stream->Read(&name))
        {
            names.push_back(name);
        }
        
        for (const Name &n : names)
        {
            Hello hello;
            hello.set_hello("hello ");
            hello.set_name(n.name());

            this_thread::sleep_for(std::chrono::milliseconds(1000));

            stream->Write(hello);
        }

        return Status::OK;
    }
};


void RunServer()
{
    string server_addr("0.0.0.0:50051");
    HelloImpl service;
    ServerBuilder builder;
    builder.AddListeningPort(server_addr,grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    unique_ptr<Server> server(builder.BuildAndStart());
    cout<<"Server listening on "<<server_addr<<endl;
    server->Wait();
}

int main(int argc,char** argv)
{
    RunServer();
    return 0;
}