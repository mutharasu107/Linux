#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
        int openFd,i,l_no=0,fl_no=0;              /* open file descriptor, line numer, file line number.*/
        char buf[BUF_SIZE];                       /* buffer size store file.*/
        ssize_t numRead;                          /* numer of read file.*/
        off_t fp=0,l_fp=0;                       /* file position and line position.*/

        l_no = atoi(argv[2]);                    /* atoi, atol, atoll - convert a string to an integer.*/
        openFd = open( argv[1], O_RDONLY);        /* open one file that file read only.*/
        if( openFd == -1 )                        /* condition checking if -1 means error.*/
        {
                perror("open()");
        }

        numRead = read( openFd, buf, BUF_SIZE );  /* read before opening that file.*/
        if(numRead == -1)
        {
                perror("read()");
        }
        
        fp = lseek( openFd, 0, SEEK_SET );        /* seek set for cursor move to stating place.*/
             perror("lssk()");
        
        for( i=0; i<numRead; i++)                 /* number of line reading.*/
        {
                l_fp++;
                if(buf[i] == '\n') 
                {
                        fl_no++;       
                }
                if(fl_no == (l_no ))
                {
                        fp = l_fp;
                }                         
        }
        
        lseek( openFd, fp, SEEK_CUR );
           perror("lseek()");

        numRead = read( openFd, buf, BUF_SIZE );
        write( STDOUT_FILENO, buf, numRead );
        close(openFd);
}
