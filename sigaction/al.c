#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

static void sighandler(int signo)
{
    switch (signo) 
    {
            case SIGTSTP:
     	       		printf("\nsignal captured stop the program\n");
           		break;
    }
}

int main(void)
{
    struct sigaction psa;
    psa.sa_handler = sighandler;
    sigaction(SIGTSTP, &psa, NULL);
    while(1) 
    {
       printf("school of linux\n");
       sleep(2);
    }
    return 0;
}
