#include <iostream>
#include <memory>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <thread>
#include <vector>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include "./protoc-code/base.grpc.pb.h"

using std::cout;
using std::endl;
using std::string;

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientWriter;
using grpc::ClientReaderWriter;
using grpc::Status;

using hello::HelloService;
using hello::Name;
using hello::Hello;

class BaseClient{
public:
    BaseClient(std::shared_ptr<Channel> channel):stub_(HelloService::NewStub(channel)){}
    void sendData()
    {
        ClientContext context;
        std::shared_ptr<ClientReaderWriter<Name,Hello>> stream(stub_->getData(&context));
        Name name;
        name.set_name("thread 1");
        stream->Write(name);
        stream->WritesDone();
        
        Data recv_data;
        while(stream->Read(&recv_data))
        {
            std::cout<<"data "<<recv_data.data()<<" send success"<<std::endl;
        }

        Status status=stream->Finish();
        if(!status.ok())
        {
            std::cout<<"getData rpc failed"<<std::endl;
        }
    }
};

int main(int argc,char** argv)
{
    ReduceClient client1(grpc::CreateChannel("localhost:50051",grpc::InsecureChannelCredentials()));
    client1.sendData();
    return 0;
}
