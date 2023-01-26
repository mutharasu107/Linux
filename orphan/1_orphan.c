#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
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
                printf("child process\n");
                x++;
                sleep(10);
                printf("pid  : %d\n",getpid());
                printf("ppid : %d\n",getppid());
                printf("x  : %d\n",x);
                printf("end of child process\n");
        }

        else if(pid > 0)
        {
                printf("parent process\n");
                x = 100;
        }
        printf("pid  : %d\n",getpid());
        printf("ppid : %d\n",getppid());
        printf("x  : %d\n",x);
}
