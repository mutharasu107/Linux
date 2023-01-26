/**********************************************************************/
/* NAME   : Mutharasu R                                               */
/* DATE   : 30-10-2022                                                */
/* TITTLE : Create a fork & call fun name called child process,parent */
/*          process and program ,multiplication and addition.         */
/**********************************************************************/


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void child_proc(void);
void parent_proc(void);
int  a=4,b=3,var;     /* declar global its showing in entire program */

int main()
{
        pid_t pid;
        
        pid = fork();

        if(pid < 0)
        {
                printf("erroe creating child process\n");
        }

        else if(pid == 0)       /* child process creating */
        {
                child_proc();
        }

        else if(pid > 0)        /* parent process creating */
        {
                parent_proc();
        }
}

void child_proc()
{
        var = a+b;
        printf("Adding two numbers : %d\n",var);
}

void parent_proc()
{
        var = a*b;
        printf("Multiplication two numbers : %d\n",var);
}
