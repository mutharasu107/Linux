#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
        int pipe_fd[2],pid;

        if(pipe(pipe_fd)==-1)
        {
                printf("error creating pipe file\n");       
        }

        pid = fork();
        
        switch(fork())
        {
                case -1:
                        printf("error creating fork");
                case 0:
                        close(pipe_fd[0]);
                        if(pipe_fd[1] != STDOUT_FILENO)
                        {
                                if(dup2(pipe_fd[1],STDOUT_FILENO)==-1)
                                {
                                        printf("error creating dup\n");
                                }
                                close(pipe_fd[1]);
                        }
                                 
                        execlp("ls","ls",(char *)NULL);
                       
                 default :
                        break;
        }
        switch(fork())
        {
                case -1:
                        printf("error creating fork");
                case 0:
                        close(pipe_fd[1]);
                        if(pipe_fd[0] != STDIN_FILENO)
                        {
                                if(dup2(pipe_fd[0],STDIN_FILENO)==-1)
                                {
                                        printf("error creating dup\n");
                                }
                                close(pipe_fd[0]);
                                
                                execlp("wc","wc","-l",(char *)NULL);
                                      
                default :
                       break;
        }
        close(pipe_fd[1]);
        close(pipe_fd[0]);
}        
