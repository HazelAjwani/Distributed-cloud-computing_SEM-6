#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int sockfd,len;
	struct sockaddr_in address;
	//structure "sockaddr_in" created with the variable "address" (to access the fields of struc)
	int result,count;
	//instr for client to server
	//str for server to client
	char str[80],instr[80];
	//syscall socket
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	//structure within a structure
	//loopback address (same for every machine)
	address.sin_port=9129; //same port number as server
	len=sizeof(address); //length of structure
	//syscall connect
	result=connect(sockfd,(struct sockaddr*)&address,len);
	if(result==-1)
		{
			printf("error\n");
			exit(1);
		}
	fflush(stdout); //flush out the console
	printf("/nenter string:");
	fgets(instr,80,stdin); //for input
	//syscall write
	write(sockfd,instr,strlen(instr)+1);
	//write from instr to sockfd of client so that can be sent to server (buffer to descriptor)
	//syscall read
	count=read(sockfd,str,20);//for output, 20bytes at a time
	printf("received data from server\n");
	printf("%s\n",str);
	close(sockfd);
	exit(0);
	}
	
