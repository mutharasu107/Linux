#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[] )
{
        int pipefd[2];

        pid_t pid;

        char buf;

        if(argc != 2 )
        {
                printf("stderrc usage : %s <string>\n",argv[0]);
                exit(EXIT_FAILURE);
        }

        if(pipe(pipefd) ==-1)
        {
                printf("eror crearing pipe\n");
                exit(EXIT_FAILURE);
        }

        pid = fork();

       if(pid == -1)
       {
                printf("error creating fork\n");
                exit(EXIT_FAILURE);
       }

       else if(pid == 0)
       {
                close(pipefd[1]);
                while(read(pipefd[0],&buf,1) > 0)
                        write(STDOUT_FILENO,&buf,-1);
                write(STDOUT_FILENO,"\n",1);
                close(pipefd[0]);
       }
        
       else if(pid > 0)
       {       
                close(pipefd[0]);
                write(pipefd[1],argv[1],strlen(argv[1]));
                close(pipefd[1]);

                wait(NULL);
       }
                
}
