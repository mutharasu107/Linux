//write a data to the particular file

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdlib.h>

struct mydata_buf
{
   long data_type;
   char data_text[200];
};

int main()
{
   key_t key;
   int shm_id;
   char *ptr;
   struct shmid_ds data;
   char buf[40] = "Linus Torvalds\nSystem shared memory\n";
   key = ftok( "shmv", 72 );

   printf("pid : %d\n",getpid());
   
   shm_id = shmget( key, 1024, 0644 | IPC_CREAT );
   perror("shmget");

   ptr = ( char * ) shmat( shm_id, NULL, SHM_RND );
   perror("shmat()");
   
   strcpy( ptr, buf );

   shmdt(ptr);
   perror("shmdt()");
   sleep(10);


   //	int shmctl(int shmid, int cmd, struct shmid_ds *buf);
   if(shmctl( shm_id, IPC_RMID, &data ) == -1)
   {
      perror("shmctl()");
      exit(-1);
   }

   printf("write : data removed successfuly\n");
}
