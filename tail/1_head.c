#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096                             /* define the global from buf_size 4096 bytes.*/

int main(int argc, char *argv[])                  /* give the input form command line.*/
{
        int openFd,i,l_no=0,fl_no=0;              /* open file descriptor, line numer, file line number.*/
        char buf[BUF_SIZE];                       /* buffer size store file.*/
        ssize_t numRead;                          /* numer of read file.*/
        off_t fp=0,l_fp=0;                        /* file position and line position.*/

        l_no = atoi(argv[2]);                     /* atoi, atol, atoll - convert a string to an integer.*/
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
             perror("lseek()");
        
        for( i=0; i<numRead; i++)                 /* number of line reading.*/
        {
                l_fp++;                           /* line file point increment.*/
                if(buf[i] == '\n')                /* counting the character up to new line it selp.*/
                {
                        fl_no++;                  /* file line number increment.*/
                }
                if(fl_no == (l_no - 2))           /* condition cheking file line number and user give line number user give line 2 minius.*/
                {
                        fp = l_fp;                /* line file point give to the file point variable.*/
                }                         
        }
        
        lseek( openFd, fp, SEEK_CUR );            /* position changing off file of set.*/
           perror("lseek()");

        numRead = read( openFd, buf, BUF_SIZE );  /* read the byte from buf_size of the byte reading.*/
        write( STDOUT_FILENO, buf, numRead );     /* write to standard out how many byte read and store to the numRead variable.*/
        close(openFd);                            /* close the file descriptor.*/
}
