#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        pid_t pid;
 
        pid = fork();
        
        if (pid  == -1)
        {
                perror("error occured in fork() system call\n");
//                exit(EXIT FAILURE);
        }
        
        else if (pid == 0) 
        {
                printf("child process id : %u\n",getpid());
                printf("parent process id : %u\n",getppid());
        }

        /*exec*/
        //excl("/bin/ls","/bin/ls","-l","/home",NULL);
        
        /*execp*/
        execlp("ls","ls","-l","/home/muthu",NULL);
        
        /*execv*/
        char * l_argv[] = {"/bin/ls","-l","/home",NULL};

        //exev("/bin/ls",l_argv);

        /*execvp*/
        printf("\n path\n");

        char * l_argvp[] = {"ls","-l",NULL};

        //execvp(l_argvp[0],l_argvp);
        exit(0);
}
          
