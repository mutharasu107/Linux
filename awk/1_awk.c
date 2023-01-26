#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
        int openFd, l_no, l_num=0, pat=0, l_no1=0;
        ssize_t numRead;
        char buf[BUF_SIZE];
        off_t fp=0, l_fp=0;

        l_no  = atoi(argv[2]);
        l_no1 = atoi(argv[3]);
 
        openFd = open ( argv[1], O_RDONLY );
        if( openFd == -1 )
        {
                perror("open()");
        }

        numRead = read ( openFd, buf, BUF_SIZE );
        if( numRead == -1)
        {
                perror("read()");
        }

        fp = lseek( openFd, 0, SEEK_SET );
                perror("lseek()");
       
        pat = mawk("-F", ":", "'{printf $l_no1}'", l_no);
        for(int i =0; i<numRead; i++)
        {
                l_fp++;
                if((buf[i]) == '\n')
                {
                        l_num++;
                }
                
        }
}
