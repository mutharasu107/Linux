/*************************************************************/
/*  NAME         : Mutharas R                                */
/*  DATA         : 29-10-2022                                */
/*  DESCRIPATION : Understanding about fork(),system call    */
/*************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int glovar = 6;                                 /* Declar global variable */
char buf[] = {"a write to stdout\n"};

int main()
{
        int var;                                /* auto var in stack */
        pid_t pid;

        var =88;
        
        if(write(STDOUT_FILENO,buf,sizeof(buf)-1) != (sizeof(buf)-1))
        {
                printf("write error\n");
        }
        
        if((pid == fork())<0)
        {
                printf("fork creating error\n");
        }

        else if(pid == 0)                       /* child process */
        {
                glovar++;                       /* modify variables */
                var++;
        }

        else
        {
                sleep(2);                       /* parent */
        }

        printf("pid = %ld,g_var = %d,var = %d\n",(long)getpid(),glovar,var);
        exit(0);
}
