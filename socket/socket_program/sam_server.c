// 1_socket server

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

void *snd(); // sending message
void *rcv(); // recveing message

void *client_handle();

int sock_fd1, sock_fd2, ret_val;
unsigned char recv_msg[100], snd_msg[100];

ssize_t send_ms;
int send_thread, recv_thread;
pthread_t thread1, thread2;

int main(int argc, char *argv[])
{
        // man page of socket structure in ip
        struct sockaddr_in socketaddr;

        socketaddr.sin_family = AF_INET;// IPv4 Internet protocols  
         
        // int socket(int domain, int type, int protocol);
        sock_fd1 = socket(AF_INET, SOCK_STREAM, 0 );
        perror("socket()");
                
        //  uint16_t htons(uint16_t hostshort);
        socketaddr.sin_port   = htons(atoi(argv[1])); /* port number convert to byte oreder*/
        
        //        int inet_pton(int af, const char *src, void *dst);
        unsigned int ip = inet_pton(AF_INET,argv[2],&socketaddr.sin_addr); /* ip address store to the structure as a network byte order */
        
        // int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
        bind(sock_fd1, (struct sockaddr *)&socketaddr, sizeof(socketaddr));
        perror("bind()");

        // int listen(int sockfd, int backlog);
        listen(sock_fd1, 5);
        perror("lis     ten()");
        
        // int accept4(int sockfd, struct sockaddr *addr, socklen_t *addrlen, int flags);
        sock_fd2 = accept(sock_fd1, NULL, NULL);
        perror("accept()");
        
        while(1)
        {        
        
               pid_t child_pid = fork();

               if(child_pid == -1)
               {
                         perror("fork()");
               }
        
               else if(child_pid == 0)
               {
                         pthread_create( &thread1, NULL,&client_handle, NULL);
               }
        
               else
               {
                         // int close(int fd);
                         close(sock_fd1);
                         close(sock_fd2);
               }
               // ssize_t recv(int sockfd, void *buf, size_t len, int flags);
               recv(sock_fd2, recv_msg, 100, 0);
               printf("%s\n", recv_msg);
        }
}

void *client_handle()
{
        while(1)
        {
         
/*          // int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
          send_thread = pthread_create( &thread1, NULL, snd, NULL);                                
           
          // int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
          recv_thread = pthread_create( &thread2, NULL, rcv, NULL);  */    
          
          scanf("%[^\n]%*c",snd_msg);
          send(sock_fd2, snd_msg, strlen(snd_msg)+1,0); /* send the messages */

          recv(sock_fd2, recv_msg, 100, 0); /* receve message */
          ret_val = strcmp(recv_msg, "exit");
          if(ret_val == 0)
          {
                while(1);
          }
          else 
          {        
                printf("%s\n", recv_msg);
          }         
       }
}
