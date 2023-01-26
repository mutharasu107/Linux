#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
   int a;
   char *max;
   for(a=0;  ; ++a)
   {
      max = sbrk(80);
      if(max == (char *)-1 )
	 break;
   }
   printf("%d : 80 -bytes max size \n", a);
}
