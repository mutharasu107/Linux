#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 1024

int main()
{
        char buf[BUF_SIZE];
        ssize_t numRead;

        numRead = read( 0, buf, 1024 );
        write( STDOUT_FILENO, buf, numRead );        
}
