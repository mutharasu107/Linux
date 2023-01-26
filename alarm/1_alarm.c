#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

void s_alarm()
{
   write(STDOUT_FILENO, "I got signal from alarm\n",24);
}

int main()
{
   int i;
   signal(SIGALRM,s_alarm);
   alarm(2);
   for(i=0; ; i++)
   {
      printf("%d : In side main function\n",i);
      sleep(1);
   }
}
