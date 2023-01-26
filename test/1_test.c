#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 50

int main(int argc, char *argv[])
{
        int openFd, l_no=0, l_num=0;
        ssize_t numRead;
        off_t fp=0, l_fp=0,a=0;
        char buf[BUF_SIZE];

        openFd = open( argv[1], O_RDONLY );
        if( openFd == -1 )
        {
                perror("open()");
        }

        numRead = read ( openFd, buf, BUF_SIZE);
        if( numRead == -1)
        {
                perror("read()");
        }
        
        fp = lseek ( openFd, 0, SEEK_SET);
                perror("lseek()");

        lseek ( openFd, 5, SEEK_CUR);
        l_num = read( openFd, buf, BUF_SIZE );
        write ( STDOUT_FILENO, buf, l_num);
}
