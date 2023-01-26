/***************************************************************************************/
/*      NAME    : R.Mutharasu                                                          */
/*      DATE    : 12-12-2022                                                           */
/*      PROGRAM : MP3 prgoram file read and write another file using command line      */
/***************************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUF 280557

int main(int argc, char *argv[])
{
        int fd,fd1,fd2,fd3;
        char arr[BUF];

        fd=open("./thunivu.mp3",O_RDONLY);
        if(fd == -1)
        {
                printf("error opening file\n");       
        }
        
        fd1=read(fd,arr,BUF);
        if(fd1 == -1)
        {
                printf("error creating read file\n");
        }

        fd2=creat(argv[1],S_IRWXU);
        if(fd2 == -1)
        {
                printf("error creating file\n");       
        }

        fd3=write(fd2,arr,BUF);
        if(fd3 == -1)
        {
                printf("error write file\n");
        }

        close(fd);
        close(fd1);
        close(fd2);
        close(fd3);
}
