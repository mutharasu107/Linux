#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
        while(1){
        fork();
        }
        printf("print\n");
}
