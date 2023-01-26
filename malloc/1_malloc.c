#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define ONE_GB (1<<30)

int main()
{
   printf("PID : %d\n",getpid());
   getchar();
   malloc(ONE_GB);
   getchar();
}
