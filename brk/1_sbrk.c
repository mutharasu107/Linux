#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
   void *ptr = sbrk(0);
   printf("prrogram break  %p\n",ptr);
}
