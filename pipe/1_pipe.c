#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
        int pipe_fd[2],ret_fd;                          //two file discripeter
        char *stdout_buf=(char *)malloc(20);            //stroing heap area using malloc

        ret_fd=pipe(pipe_fd);                           //pipe value storing in to ret_fd
        if(ret_fd == -1)                                //condiction cheking
        {
                printf("error in pipe\n");
                exit(-1);       
        }

        write(pipe_fd[1],"Linus Torvalus\n",14);        //pipe 1 means writing 
        write(pipe_fd[1],"Richard Stallmen\n",16);      //pipe 1 means writing

        read(pipe_fd[0],stdout_buf,14);                 //pipe 0 means read and stroing in to stdout_buf file
        printf("buf : %s\n",stdout_buf);                //print character in to stdout_buf
        
        read(pipe_fd[0],stdout_buf,16);                 //pipe 0 means read and stroing in to stdout_buf file
        printf("buf : %s\n",stdout_buf);                //print character in to stdout_buf
        
//        free(stdout_buf);                               //free memory allocation

//        close(ret_fd);                                  //close the file discriptor
        printf("pid : %d\n",getpid());

        getchar();
}
