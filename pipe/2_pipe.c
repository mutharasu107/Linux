#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char *stdout_buf="Linus Torvalus\n",stdin_buf[25];

int main()
{
        int pipe_fd[2],fd;

        int stdout_fd,stdin_fd;

        pid_t pid;

        char *ptr=(char *)malloc(40);

        if(ptr==0)
        {
                printf("error creating malloc\n");
                exit(-1);
        }

        printf("size of ptr : %ld\n",sizeof(ptr));

        fd=pipe(pipe_fd);

        if(pid == -1)
        {
                printf("error creating pipe\n");
                exit(-1);       
        }

        pid = fork();

        if(pid == -1)
        {
                printf("error creating fork()\n");
                exit(-1);       
        }

        else if(pid == 0)
        {
                stdout_fd=read(pipe_fd[0],ptr,25);
                printf("data : %s\n",ptr);       
        }

        else if(pid > 0)
        {
                stdin_fd=write(pipe_fd[1],stdout_buf,(strlen(stdout_buf)-1));
                wait(NULL);
        }

        printf("stdin_fd  : %d\n",stdin_fd);
        printf("stdout_fd : %d\n",stdout_fd);
        free(ptr);
}
