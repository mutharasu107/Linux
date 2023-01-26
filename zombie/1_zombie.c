#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
        pid_t pid;

        int x = 10;

        pid = fork();

        if(pid == -1)
        {
                printf("error creating fork\n");
        }

        else if(pid == 0)
        {
                printf("this is child process\n");
                x++;
        }

        else if(pid > 0)
        {
                printf("this is parent process\n");
                sleep(60);
                printf("after wait\n");
                x = 100;
        }
        printf("pid   : %d\n",getpid());
        printf("ppid  : %d\n",getppid());
        printf("x     : %d\n",x);
}
