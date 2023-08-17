// Write a program for print /etc/passwd file user name only.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>      
#include <unistd.h>
#include <error.h>
#include <errno.h>

int main()
{

        int fd;
        long filesize;
        size_t read_size;
        struct stat statbuf;
        char *buffer, *temp;
        char username[250], *usernamep;

//open /etc/passwd file
        fd = open("/etc/passwd", O_RDONLY);
        if(fd < 0) {
                        perror("open:");
                        return ENOENT;
                }

//get the filesize of /etc/passwd
        if(fstat(fd, &statbuf)){
                        perror("stat");
                        goto fstat_fail;
                }
        filesize = statbuf.st_size;
//alloate memory to save contents of passwd file
        buffer = (char *) calloc(1,filesize+1);

        if(buffer == NULL) {
                        perror("malloc");
                        goto malloc_fail;
                }

//read passwd file and store the data in allocated memory
        read_size = read(fd, buffer, filesize);
//        printf("statbuf.st_size %ld, read_size %ld\n", filesize, read_size);

        if(read_size != filesize)
        {
                perror("read");
                goto read_fail;
        }

        buffer[read_size] = '\0';
//        printf("%s\n", buffer);
//filter the contents to get the usernames and print it on console
        temp = buffer;
        while (*temp != '\0') {
                usernamep = &username[0];
                while(*temp != ':') {
                                *usernamep++ = *temp++;
                        }
                        *usernamep = '\0';
                        printf("%s\n",username);
                
                while(*temp != '\n')
                        temp++;
                temp++;
                }
//release the allocated memory
        free(buffer);
//close the file
        close(fd);
        return 0;

read_fail:
        free(buffer);
malloc_fail:
fstat_fail:
        close(fd);
        return -1;
}
