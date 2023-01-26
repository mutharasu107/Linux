#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

#define BUF_SIZE 512

void s_interrupt()
{
        write(STDOUT_FILENO,"i got signal from terminate process\n",37);
}

int main(int argc,char *argv[])
{
        signal(SIGINT,s_interrupt);

        int fd,n;
        char *buf="Hi i am named pipe";
        mkfifo(argv[1],0004);
        fd=open(argv[1],O_WRONLY);
        if(fd==-1)
        {
                printf("error opening a file: %s\n",argv[1]);       
        }
        write(fd,buf,(strlen(buf))-1);
        close(fd);
}
