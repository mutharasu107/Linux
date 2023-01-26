#include "main.h"

int main(int argc, char* argv[])
{
   int fd;
   fd = open( argv[1], O_CREAT | O_RDWR, 0666);
   if(fd == -1)
   {
      err_ex(-2);
   }
}
