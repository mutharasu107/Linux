#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

#define ONEGB (1<<30)
#define ONEMB (1<<20)

int main(int argc, char *argv[])
{
        pid_t pid;

        pid = fork();

        if(pid == -1)
        {
                printf("error creating fork");
        }

        else if(pid == 0)
        {
                printf("i am child process\n");

                int *ptr=mmap(NULL,ONEGB,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_PRIVATE | MAP_ANONYMOUS,0,0);

                if(ptr == MAP_FAILED)
                {
                        printf("error creating map file\n");       
                }

                printf("map file creating sucessfly");
                printf("ptr : %p\n",ptr);
        }
        
        else if(pid > 0)
        {
                printf("i am parent process\n");

                int *str=mmap(NULL,ONEMB,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_PRIVATE | MAP_ANONYMOUS,0,0);

                if(str == MAP_FAILED)
                {
                        printf("error creating map file\n");       
                }

                printf("map file creating sucessfly");
                printf("str : %p\n",str);
        }

        printf("pid : %d\n",getpid());
        getchar();
}
