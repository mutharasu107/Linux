// file control using server side writing time wait for clint side. 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define str "School of linux\nDharmapuri"

int main(int argc, char *argv[])
{
        struct flock lock;
        int fd, i;
        
        lock.l_type   = F_WRLCK;
        lock.l_whence = SEEK_SET;       // Bytes from the beginning of the file.
        lock.l_start  = 0;              // Starting offset for lock.
        lock.l_len    = 0;              // number of bytes to lock 0 until end off file.
        lock.l_pid    = getpid();       // get the pid off the process.     

        if( ( fd = open ( argv[1], O_CREAT | O_RDWR, 0666 )) == -1 ) 
        {
                perror("open()");
                exit( -1 );
        }   

        //      int fcntl (int fd, int cmd,......./*arg*/ );
        if( fcntl( fd, F_SETLK, &lock) <0 )
        {
                perror(" fcntl() ");
                exit( -1 );
        }

        if( ( write( fd, str, strlen (str) ) ) < 0 )
        {
                perror("write()");
                exit( -1 );
        }

        fprintf( stderr, "process %d has writen a data\n",lock.l_pid);

        for( i=0; i<10; i++)
        {
                printf("PID : %d writing data to the file\n",getpid());

                sleep( 1 );
        }

        lock.l_type = F_UNLCK;
        
        //      int fcntl (int fd, cmd, ......./* arg */);
        if( fcntl ( fd, F_SETLK, &lock ) < 0)
        {       
                perror(" fcntl() ");
                exit(-1);
        }

        close ( fd );
}
