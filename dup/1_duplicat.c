/* duplicate system call*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUF_SIZE 512

int main(int argc,char *argv[])
{
        char buf[BUF_SIZE];
        int src_fd,dup_fd;
        ssize_t src_write,src_read,dup_write,dup_read;
        
        src_fd=open(argv[1],O_RDWR | O_APPEND);
        if(src_fd == -1)
        {
                printf("error creating open file : %s\n",argv[1]);       
                exit(-1);     
        }
        
        dup_fd = dup(src_fd);
        if(dup_fd == -1)
        {
                printf("error creating duplicating file :%s\n",argv[1]);  
                exit(-1);     
        }

        src_write=write(src_fd,"src text\n",9);
        dup_write=write(dup_fd,"dup text\n",9);

        lseek(src_fd,0,SEEK_SET);

        src_read=read(src_fd,buf,BUF_SIZE);
        write(STDOUT_FILENO,BUF_SIZE,src_read);

        dup_read=read(dup_fd,buf,BUF_SIZE);
        write(STDOUT_FILENO,BUF_SIZE,dup_read);

        close(src_fd);
        close(dup_fd);
}
