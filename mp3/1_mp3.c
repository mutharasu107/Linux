/***********************************************************************************************/
/*NAME          : R.Mutharasu                                                                  */
/*DATE          : 10-12-2022                                                                   */
/*PROGRAM       : MP3 rename pogram using file i/o                                             */
/***********************************************************************************************/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
        int fd,fd1,fd2,fd3;
        char arr[241926];

        fd=open("./mysong.mp3",O_RDONLY);
        if(fd == -1)
        {
                printf("error opening file\n");       
        }
        else
        {
                printf("file open\n");       
        }

        fd1=read(fd,arr,241926);
        if(fd1 == -1)
        {
                printf("error creating read file\n");
        }
        else
        {
                printf("file read\n");
        }

        fd2=creat("./muthu.mp3",S_IRWXU);
        if(fd2 == -1)
        {
                printf("error creating file\n");       
        }
        else
        {
                printf("file creat\n");
        }

        fd3=write(fd2,arr,241926);
        if(fd3 == -1)
        {
                printf("error write file\n");
        }
        else 
        {       
                printf("file write\n");       
        }

        close(fd);
        close(fd1);
        close(fd2);
        close(fd3);
}
