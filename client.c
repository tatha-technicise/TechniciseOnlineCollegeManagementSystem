#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>

#define c_addr "192.168.0.15"
#define s_port 6220
#define c_port 6225
#define size 200

main()
{
struct sockaddr_in server,client;
char str1[200],str2[200];
int sd,srvlen;
printf(":CLIENT PROGRAM:");
bzero((char *)&server,sizeof(server));
server.sin_family=AF_INET;
server.sin_port=htons(s_port);
server.sin_addr.s_addr=inet_addr("127.0.0.1");
client.sin_family=AF_INET;
client.sin_port=htons(c_port);
client.sin_addr.s_addr=inet_addr(c_addr);
sd=socket(AF_INET,SOCK_STREAM,0);
bind(sd,(struct sockaddr*)&client,sizeof(client));
srvlen=sizeof(server);
connect(sd,(struct sockaddr*)&server,srvlen);
do
{
printf("\n Enter a message:");
scanf("%s",str1);
send(sd,str1,strlen(str1)+1,0);
memset(str2,0x0,size);
recv(sd,str2,size,0);
printf("\n MESSAGE RECEIVED:%s",str2);
}
while(strcmp(str1,"stop"));
close(sd);
}










