#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define ONEGB (1<<30)

int main()
{
   int count = 1;
   for( ; ; )
   {
      if(malloc(ONEGB) == NULL)
      {
	 printf("out of memory : %d\n",count);
	 return 0;
      }
//      getchar();
      printf("got %d  GB \n",count++);
   }
}
