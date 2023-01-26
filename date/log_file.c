
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LOG(msg,i) { \
     char line[20];\
     sprintf(line,"%d",i);\
     char str1[1000],str2[1000];\
     strcpy(str1,line);\
     strcpy(str2,msg);\
     strcat(str1,str2);\
     logFd=open("test.txt",O_CREAT|O_RDWR|O_APPEND,S_IRWXU);\
     write(logFd,str1,strlen(str1));\
     }  


int main(int argc, char *argv[])
{    
  int fd,logFd,line=0;
 
  
  fd=open("A.txt",O_CREAT|O_RDWR,S_IRWXU);
  LOG (" Write Success\n",__LINE__);
  LOG (" Open Success\n",__LINE__);
  
  LOG (" Read Success\n",__LINE__);
  
  LOG (" Write Success\n",__LINE__);

  LOG (" lseek Success\n",__LINE__);

  printf("Kindly check log file\n");
  close(logFd);
  
}
