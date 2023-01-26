#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_VALUE 100

int main()
{
        pid_t pid;
        int a=0,b=0;

        pid = fork();

        if(pid == -1)
        {
                printf("error creating fork\n");
        }

        else if(pid == 0)
        {
                for(a=1; a<=MAX_VALUE; a++)
                {
                        printf("i am child process : %d\n",a);
                }
                printf("***** Child process done *****\n");
        }
        
        else if(pid > 0)
        {
                for(b=1; b<=MAX_VALUE; b++)
                {
                        printf("i am parent process : %d\n",b);
                }
                printf("***** Parent process done *****\n");
        }
}
