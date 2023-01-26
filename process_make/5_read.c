#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
   if(numRead == -1)
   {
      perror("read()");
      exit(-1);
   }
   printf("fivth file read : %ld\n",numRead);
   close(fd);
}
