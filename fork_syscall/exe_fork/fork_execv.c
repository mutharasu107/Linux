/**************************************************************************/
/* NAME         : Mutharasu R                                             */
/* DATE         : 22-10-2022                                              */
/* DESCRIPATION : using fork(),execv creating dir sl in that dir create   */
/*                file name called test in that talk is cheapshow me code.*/
/**************************************************************************/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
ssize_t size;
char buf[] = {"talk is cheap show me the code"};

int main()
{
        int fd,a;

        pid_t pid;
        
        pid = fork();

        if(pid == -1)
        {
                printf("error occured in fork()\n");
        }

        else if(pid == 0)
        {
                char* args[] = { "gcc", "test.c", "./a.out", NULL};
                execv("/bin/ls", "/binls", "-l", NULL);
                
  //              char* args[] = {"/bin/gcc", "fork.c", "./a.out", NULL};
  //              execv("/bin/gcc fork.c", args);

                printf("child process : %u\n",pid);
                printf("PID  : %u\n",getpid());
                printf("PPID : %u\n",getppid());
        }
    
        else if(pid > 0)
        {
                fd = open("./test",O_CREAT | O_RDONLY,0644);

                if(write(STDOUT_FILENO,buf,sizeof(buf))-1 != (sizeof(buf)-1))
                printf("parent process\n");
                printf("\nchild process id : %u\n",pid);
        }
}
