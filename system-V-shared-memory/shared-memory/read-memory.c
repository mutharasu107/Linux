//read data to the particular file

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
   key_t key;
   int shm_id;
   char *ptr;
   char buf[40];
   key = ftok( "shmv", 72 );
   shm_id = shmget( key, 1024, 0 );
   perror("shmget");
   ptr = ( char * ) shmat( shm_id, NULL, 0 );
   perror("shmat()");
   strcpy( buf, ptr );
   printf("data : %s",ptr);
   shmdt(ptr);

}
