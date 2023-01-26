// file control using server side writing time wait for clint side reading the data
// Now client side

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        struct flock lock;
        int fd;
        char ch;
        
        lock.l_type   = F_RDLCK;
        lock.l_whence = SEEK_SET;       // Bytes from the beginning of the file.
        lock.l_start  = 0;              // starting offset for lock.
        lock.l_len    = 0;              // number of bytes to lock 0 until end off file.
        lock.l_pid    = getpid();       // get the pid off the process.     

        if( ( fd = open ( argv[1], O_RDONLY )) == -1 ) 
        {
                perror("open()");
                exit( -1 );
        }   
        
        // F_GETFL               Return (as the function result) the file access mode and the file status flags; arg is ignored.
        if( fcntl( fd, F_GETFL, &lock) <0 ) 

        {
                perror(" fcntl() ");
                exit( -1 );
        }

        if( lock.l_type != F_UNLCK ) 
                printf("file is write lock\n");

        lock.l_type = F_RDLCK;
        if( fcntl ( fd, F_SETLK, &lock ) < 0 )
        {
                perror("fcntl()");
                exit( -1 );
        }

        while( read ( fd, &ch, 1) > 0 )
                write( STDOUT_FILENO, &ch, 1 );

        //      release the lock.

        lock.l_type = F_UNLCK;
        if( fcntl(fd, F_SETLK, &lock) < 0)
        {
                perror("fcntl()");
                exit( -1 );
        } 

        close( fd );
}
