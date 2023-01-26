#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 512

int main(int argc, char *argv[])
{
   int fd;
   ssize_t numRead;
   char buf[BUF_SIZE];

   fd = open( argv[1], O_RDONLY );
   if(fd == -1)
   {
      perror("open()");
      exit(-1);
   }

   numRead = read( fd, buf, BUF_SIZE );
   write( STDOUT_FILENO, buf, numRead );
   close(fd);
}
