#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void s_int()
{
        write(STDOUT_FILENO,"i got signal from interrupt\n",28); 
}

void s_quit()
{
        write(STDOUT_FILENO,"I got signal form quit\n",23);
}

int main()
{
        int j=0;
        signal(SIGQUIT,s_quit);
        signal(SIGINT,s_int);
        for (j = 0; ; j++)
        {
                printf("%d\n", j);
                sleep(1);         // Loop slowly... 
        }
}
