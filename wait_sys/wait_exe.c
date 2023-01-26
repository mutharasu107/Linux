#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
        pid_t pid;

        pid = fork();

        if(pid == -1)
        {
                printf("error occered in fork\n");
        }
        
        else if(pid > 0)
        {
                printf("i am parent process\n");
                wait(NULL);
//                sleep(5);
        }

        else if(pid == 0)
        {
                printf("i am child process\n");
        }

        printf("pid  : %d\n",getpid());
        printf("ppid : %d\n",getppid());
}
