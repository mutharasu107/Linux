#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 512

int main(int argc,char *argv[])
{
    int fd,n;
    char buf[BUF_SIZE];
    mkfifo(argv[1],0004);
    fd = open(argv[1], O_RDONLY);
    if(fd==-1)
    {
          printf("erorr creating open file : %s\n",argv[1]);
    }
    while((n=read(fd,buf,BUF_SIZE))>0)
    {
          write(STDOUT_FILENO,buf,n);
    }
    close(fd);
}
