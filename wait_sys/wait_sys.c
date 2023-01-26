#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        pid_t pid;
        int x = 10;
        
        pid = fork();
        
        if(pid == -1)
        {
                printf("error in fork\n");       
        }

        else if(pid == 0)
        {
                printf("child process\n");
                x++;
                sleep(20);
        }

        else if(pid > 0)
        {
                printf("parent process\n");
                wait(NULL);
                printf("after wait\n");
                x = 100;
        }

        printf("pid = : %d\n",getpid());
        printf("ppid = : %d\n",getppid());
        printf("x = : %d\n",x);
}
