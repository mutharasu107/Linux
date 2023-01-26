//System V shared memory. 
// read data to the particular memory location.

#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>

int main()
{
   key_t key;
   int shm_id;
   char *ptr;
   char buf[40];
   
   //ket_t ftok(const char *pathname, int proj_id);
   key = ftok("shmv",72);
   perror("ftok()");

   //int shmget (ket_t key, size_t size, int shmflg);
   shm_id = shmget( key, 1024, 0 );
   if(shm_id == -1)
   {
      printf("Error shmget\n");
   }

   //	void *shmat(int shmid, const void *shmaddr, int shmflg);
   ptr = (char *) shmat( shm_id, NULL, 0 );
   perror("shmat()");
   
   strcpy( buf, ptr );
   printf("data : %s", buf);

   //	int shmdt(consst void *shmaddr);
   shmdt(ptr);
}
