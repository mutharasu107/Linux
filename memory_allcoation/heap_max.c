#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
        int a;
        char* val;

        for(a=1; ;a++)
        {
                val=sbrk(80);
                if(val==(char *)-1)
                     break;
                printf("address : %p\n",val);
        }
        printf("%d 80-byte blocks allocated sbrk \n",a);
        printf("address : %p\n",val);
}
