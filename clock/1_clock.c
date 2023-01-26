/* CELEBT12

   This example provides the amount of processor time
   used by instructions and the system for the parent and child
   processes.

 */
#define _POSIX_SOURCE
#include <sys/times.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  long i, j;
  struct tms t;
  clock_t dub;
  int tics_per_second;

  tics_per_second = sysconf(_SC_CLK_TCK);

  if (fork() == 0) {
    for (i=0, j=0; i<1000000; i++)
       j += i;
    exit(0);
  }

  else if ( fork() == -1)
  {
        perror("fork()");
  }
  
  else if ( fork() > 0 ) {
  printf("process was dubbed %f seconds ago.\n\n",
           ((double) dub)/tics_per_second);
    printf("            utime           stime\n");
    printf("parent:    %f        %f\n",
           ((double) t.tms_utime)/tics_per_second,
           ((double) t.tms_stime)/tics_per_second);
    printf("child:     %f        %f\n",
           ((double) t.tms_cutime)/tics_per_second,
           ((double) t.tms_cstime)/tics_per_second);
  }
}
