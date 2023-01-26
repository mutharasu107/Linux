#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
        int openFd, i, l_no =0, fl_no =0;
        ssize_t numRead;
        char buf[BUF_SIZE];
        off_t fp =0,l_fp =0;

        l_no = atoi(argv[2]);

        openFd = open( argv[1], O_RDONLY );
        if(openFd == -1)
        {
                perror("open()");       
        }
        
        numRead = read( openFd, buf, BUF_SIZE );
        if(numRead == -1)
        {       
                perror("read()");       
        }

        fp = lseek( openFd, 0, SEEK_SET );
        {       
                perror("lseek()");
        }

        for( i=0; i<numRead; i++)
        {
                l_fp++;
                if(buf[i] == '\n' )
                {
                        fl_no++;
                }
                if(fl_no == (l_no - 2))
                {
                        fp = l_fp;
                }
        }

        lseek( openFd, fp, SEEK_CUR );
        perror("lessk()");

        numRead = read( openFd, buf, BUF_SIZE);
        write( STDOUT_FILENO, buf, numRead);

        close(openFd);
}
