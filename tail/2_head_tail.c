#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096                                   /* global define in BUF_SIZE 4096 bytes.*/

int main(int argc, char *argv[])                        /* input from command line arguments.*/
{
        int openFd, readFd, fl_num=0, l_num=0, l1_num=0;/* initalized from integer variables.*/
        char buf[BUF_SIZE];                             /* character storing buf size.*/
        ssize_t fd1;                                    /* read file initialized.*/
        off_t l_fp=0, fp=0,sfp=0,efp=0;                 /* lseek function varibale declared.*/

        l_num  = atoi(argv[2]);                         /* input 2 string convert to long integer.*/
        l1_num = atoi(argv[3]);                         /* input 3 string convert to long integer.*/

        openFd = open( argv[1], O_RDONLY );             /* opening the file given argv1[1] that file read only.*/  
        if( openFd == -1 )
        {
                perror("open()");
        }

        readFd = read( openFd, buf, BUF_SIZE );         /* read file from before open file that value store to buf and BUF_SIZE of bytes reading.*/
        if( readFd == -1 )
        {
                perror("read()");       
        }
        fp = lseek( openFd, 0, SEEK_SET );              /* change the position in set from first line.*/
                perror("lseek()");
        for( int i=0; i<readFd; i++ )                   /* toteley how many bytes counting.*/
        {
                l_fp++;                                 /* line file point increment.*/
                if( buf[i] == '\n')                     /* buffer storing character in to end of line .*/
                {
                        fl_num++;                       /* file line number increment.*/
                }
                if( fl_num == (l_num-2) )               /* user give first line number and file line number cheking .*/
                {
                        sfp = l_fp;                     /* line file position value store in to starting file position.*/
                }
                if( fl_num == (l1_num-1) )              /* user give last file number and file line number checking.*/
                {
                        efp = l_fp;                     /* line file position value store in to end of file position.*/
                }
        }
        
        lseek( openFd, sfp, SEEK_CUR );                 /* lseek using change the position moving to starting file position to cursor.*/
                perror("lseek()");

        fd1 = read( openFd, buf, (efp-sfp) );           /* read the bytes from end of file position minus(-) starting file position value.*/
        write( STDOUT_FILENO, buf, fd1 );               /* write the value from STDOUT_FILENO read the file descriptor value.*/

        close( openFd );                                /* close the file descriptor.*/
}
