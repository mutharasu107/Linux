#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define ONE_GB (1<<30)

int main()
{
   printf("_SC_PAGESIZE %ld\n",sysconf(_SC_PAGESIZE));
   printf("PID : %d\n",getpid());
   getchar();
   int *ptr = (int *) malloc(ONE_GB);
   printf("%p\n",ptr);
   getchar();
   free(ptr);
   getchar();
}
