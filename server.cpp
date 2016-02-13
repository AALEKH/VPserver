#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>

//For Vpack objects
#include <velocypack/vpack.h>

using namespace std;

struct vstream {
    uint32_t length;
    uint32_t chunkx;
    uint64_t messageId;
    std::vector<arangodb::velocypack::Builder> vpack;
};

struct uint31_t {
    int x: 31;
};

struct uint1_t {
    int x: 1;
};

uint31_t extract_31t(vstream v) {
    uint31_t t31 = v.chunkx >> 1;
    return t31;
}

uint1_t extract_1t(vstream v) {
    uint1_t t1 = v.chunkx & 0x1;
    return uint1_t;
}

int main()
{
    sockaddr_in serv;
    bzero(&serv, sizeof(serv));
    serv.sin_family=AF_INET;
    serv.sin_port=htons(3345);
    inet_aton("127.0.0.1", &(serv.sin_addr));

    int servfd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bind(servfd, (sockaddr*)(&serv), sizeof(serv));

    listen(servfd, 5);
    sockaddr cli;
    int connfd;
    pid_t id=-1;
    socklen_t siz=sizeof(cli);
    while(true)
    {
        if( (connfd=accept(servfd, &cli, &siz)) >=0 )
            continue;
    }
}