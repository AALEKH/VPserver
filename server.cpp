#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>

using namespace std;

// void reflect(int x)
// {
//     int n;
//     int m;
//     char data[100];
//     cout<<"Entered reflect function"<<endl;

//     n=read(x,data, 100);
//     cout<<"Client sent "<<n<<endl;

//     if(n>0)
//     {
//         while(n>0)
//         {
//             m=write(x,data,n);
//             n=n-m;
//         }
//     cout<<"Successfully echoed back to client"<<endl;
//     }
// }

int main()
{
    sockaddr_in serv;
    bzero(&serv, sizeof(serv));
    serv.sin_family=AF_INET;
    serv.sin_port=htons(3345);
    inet_aton("127.0.0.1", &(serv.sin_addr));

    int servfd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    // int x;
    bind(servfd, (sockaddr*)(&serv), sizeof(serv));

    // cout<<"Bind returned"<<x<<endl; //this displays x as 0

    listen(servfd, 5);
    sockaddr cli;
    int connfd;
    pid_t id=-1;
    socklen_t siz=sizeof(cli);
    while(true)
    {
        if( (connfd=accept(servfd, &cli, &siz)) >=0 )
            continue;
        //      id=fork();

        // if(id==0)
        //      reflect(connfd);

        // else 
             // continue;
    }
}