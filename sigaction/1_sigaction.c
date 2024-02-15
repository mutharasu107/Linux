#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_handler (int sig);
	
int main()
{
	//declaration of structures.
	struct sigaction act;

	//sets sig_handler as a new action.
	act.sa_handler = &signal_handler;

	//Call sigaction()
	sigaction (2,&act, NULL);

	while (1)
	{
	   	printf("School of Linux\n");
    		sleep(2);
	}
}

void signal_handler (int sig)
{
     if(sig == 2)
     {
     	printf("\nSignal received %i\n", sig );
    	 exit(-1);
     }
     else
     {
	printf("\nsignal not recived %i\n", sig);
	exit(-2);
     }
}
