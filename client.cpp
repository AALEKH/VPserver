#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
// #include <netdb.h> 
#include <arpa/inet.h>
#include <netinet/ip.h> 
using namespace std;

int main()
{
    int clifd;
    clifd=socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in serv;
    bzero(&serv, sizeof(serv));
    serv.sin_family=AF_INET;
    serv.sin_port=htons(3345);
    inet_aton("127.0.0.1", &(serv.sin_addr));

    connect(clifd, (sockaddr*)(&serv), sizeof(serv));
    int n,m;
    char data[100];
    char recvd[100];
    while(true) {
        fgets(data, 100,stdin );
        cout<<"You have written "<<data<<endl;

        if(n>0)
        {
            while(n>0)
            {  
                 m=write(clifd,data,n);
                 n=n-m;
            }
        }

        n=read(clifd, recvd, 100);
        cout<<"Server echoed back "<<n<<endl;

        if(n>0)
        {
            while(n>0)
            {
                m=fputs(data,stdout);
                fflush(stdout);
                n=n-m;
            }
        }
    }
}