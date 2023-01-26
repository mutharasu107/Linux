#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
        int getpid_data  = 0;
        int getppid_data = 0;
        
        int data = 0;
        data = fork();
        data = fork();
        data = fork();
        data = fork();

        printf("i am child process\n");
}
