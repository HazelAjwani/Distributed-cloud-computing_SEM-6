#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h> //for threads

void *server_thread(void *arg)
{
	int client_sockfd;
	char instr[80],name[80];
	int count=0;
	client_sockfd=(intptr_t)arg; //newly created sockfd by accept
	count=read(client_sockfd,instr,20);
	instr[count]='\0';
	printf("input from client %s\n",instr);
	strcpy(name,"Thank you");
	strcat(name,instr);
	strcpy(instr,name);
	write(client_sockfd,instr,strlen(instr)+1);
	close(client_sockfd);
	pthread_exit(NULL);
}
int main()
{
	int server_sockfd,client_sockfd,server_len,client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	pthread_t t;
	server_sockfd=socket(AF_INET,SOCK_STREAM,0);
	server_address.sin_family=AF_INET;
	server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	//structure within a structure
	//loopback address (same for every machine)
	server_address.sin_port=9129;
	server_len=sizeof(server_address); //length of structure
	//syscall bind
	if(bind(server_sockfd,(struct sockaddr*)&server_address,server_len)==-1)
		{
			printf("server error");
			exit(1);
		}
	printf("server waiting....\n"); //wait if success
	//syscall listen
	listen(server_sockfd,5);
	while(1)
	{
		client_len=sizeof(client_address);
		client_sockfd=accept(server_sockfd,(struct sockaddr*)&client_address,&client_len);
		//returns a newly created socket desc to which the properties of the old descriptor are passed
		//2 descriptors...one back to listen and other for data transfer
		printf("created new client thread %d",client_sockfd);
		pthread_create(&t,NULL,server_thread,(void *)(intptr_t)client_sockfd);
		//get back the thread id 
		//regular (NULL) or daemon thread
		//3rd paramter is function to be converted to thread
		//4th is the argument list passed to the third parameter
		//sockfd passed to third parameter..and so the thread attached to socket
	}
	return 0;
}
