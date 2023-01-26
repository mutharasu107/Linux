/**************************************************************************/
/* NAME         : Mutharasu R                                             */
/* DATE         : 22-10-2022                                              */
/* DESCRIPATION : fork() system call                                      */
/**************************************************************************/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
        pid_t pid;

        pid = fork();

        if(pid == -1)
        {
                printf("error occured in fork() system call\n");
        }

        else if(pid == 0)
        {
                printf("child process : %u\n",pid);
                execl("/bin/ls","/bin/ls","-l",NULL); /* The  exec()  family of functions replaces the current process image with a new process image */
                printf("PID  : %u\n",getpid());
                printf("PPID : %u\n",getppid());
        }

        else if(pid > 0)
        {
                printf("parent process\n");
                printf("child process id : %u\n",pid);
        }
}
