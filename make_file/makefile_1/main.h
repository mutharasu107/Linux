#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define str "hello world\n"

void err_ex(int er_no)
{
   perror("main error");
   exit(er_no);
}
