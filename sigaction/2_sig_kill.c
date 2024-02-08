#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void main()
{
    int sig;
    int id;
    
    while (1)
    {
       	printf("Enter PID\n");
    	scanf ("%i", &id );
    	
	printf("Enter signal\n");
    	scanf ("%i", &sig);	

	if(sig == 9)
	{
	   kill (id, sig );
	}
	printf("Send signal %i to %i\n", sig,id);
    }

}
