#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
   printf("PID : %d\n",getpid());
   void *ptr = sbrk(0);
   printf("prrogram break  %p\n",ptr);
   printf("sizeof(char) : %ld\n",sizeof(char));
   ptr = (void *)((char*)ptr + 1);
   printf("after inc %p\n",ptr);
   brk(ptr);
   void *ptr1 = sbrk(0);
   printf("program break add : %p\n",ptr1);
   getchar();
}
