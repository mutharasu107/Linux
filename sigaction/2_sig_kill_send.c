#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int sig;
    int id;
    
    while (1)
    {
       	printf("Enter PID\n");
    	scanf ("%i", &id );
    	
	printf("Enter the kill signal number\n");
    	scanf ("%i", &sig);	

	if(sig == 9)
	{
	   kill (id, sig);
	   exit(-1);
	}
	else
	{
	   printf("This number is not kill signal number\n");
	   exit(-1);
	}
    }

}
