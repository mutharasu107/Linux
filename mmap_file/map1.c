#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#define ONEMB (1<<30)

int main(int argc, char* argv[])
{
        int *ptr = mmap(NULL,3,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_PRIVATE | MAP_ANONYMOUS,0,0);

        if(ptr == MAP_FAILED)   
        {
                printf("error map file\n");
        }

        printf("map file sucessfuly\n");

        printf("pid: %d\n",getpid());
        
        getchar();
}
