#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define ONEGB (1<<30)

int main()
{
        int a=1;
        printf("pid : %d",getpid());
        for(;;)
        {
                if(malloc(ONEGB)==NULL)
                {       
                        printf("out of memory : %d\n",a);
                        sleep(20);
                        return 0;
                }
                printf("get %d GB\n",a++);
                
        }
}
