#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        uid_t uid = 0;t_uid = 1001;
        
        uid = getuid();
        printf("before set UID : %d\n",uid);

        if(setuid(t_uid) == -1)
        {
                printf("error in setuid\n");
        }
        else
        {
                printf("Sucessfuly changed\n");
        }
        
        uid = getuid();
        printf("after set UID : %d\n",uid);
}
