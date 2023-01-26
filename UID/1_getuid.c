#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
        uid_t uid;
        
        uid = getuid();
        printf("UID : %d\n",uid);
}
