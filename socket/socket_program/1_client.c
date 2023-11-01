// 1_socket client

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>
#include <error.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdlib.h>
#include <pthread.h>

void *snd(); // for message send
void *rcv(); // for message receive

int sock_fd1, sock_fd2;
unsigned char snd_msg[100], rcv_msg[100];

int main(int argc, char *argv[])
{
        char str[1024];
        ssize_t recv_ms;
        int send_thread, recv_thread;
        pid_t pid = fork();

	pthread_t thread1, thread2;
        
        struct sockaddr_in socketaddr;
        memset(&socketaddr, 0, sizeof(struct sockaddr_in));

        socketaddr.sin_family = AF_INET;
 
        // int socket(int domain, int type, int protocol);
        sock_fd1 = socket(AF_INET, SOCK_STREAM, 0 );
        perror("socket()");

        socketaddr.sin_port   = htons(atoi(argv[1])); /* port number */
        unsigned int ip = inet_pton(AF_INET,argv[2],&socketaddr.sin_addr); /* ip address store to     the structure as a network byte order */
        
        // int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
        connect(sock_fd1, (struct sockaddr *)&socketaddr, sizeof(socketaddr));
        perror("connect()");

        send(sock_fd1, "Client 1 : Online", 20, 0);
        
        while(1)
        {
               if(pid == 0)
               {
                   recv_thread = pthread_create(&thread1, NULL, rcv, NULL); /* for receive function*/
               }
                
               else if(pid > 0)
               {
		         send_thread = pthread_create(&thread2, NULL, snd, NULL); /* for sending function */
               }
               if(strcmp(snd_msg,"exit")==0) /* exit from the loop*/
                         exit (0);
        }
        
        close(sock_fd1);
}

void *snd()
{
                scanf("%[^\n]%*c",snd_msg);
                send(sock_fd1, snd_msg, strlen(snd_msg)+1,0); /* send a messsage */
}

void *rcv()
{
        recv(sock_fd1,rcv_msg,100,0);  /* receive the message */
        printf("%s\n",rcv_msg);
}
