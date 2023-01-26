#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

volatile sig_atomic_t unprocessedsig = 0;

void sighandler()
{
   int signo;
   if( signo == SIGINT)
   {
      unprocessedsig = 1;
   }
}

int main()
{
   struct sigaction act;

   printf("PID : %d\n",getpid());

   if(sigaction( SIGINT, &act, NULL) == -1)
   {
      perror("sigaction()");
   }

   while(1)
   {
      if(unprocessedsig)
      {
	 unprocessedsig = 0;
	 printf("SIGINT signal occured\n");
      }
   }
}
