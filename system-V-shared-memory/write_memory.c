//System V shared memory
// writing data to the particular memory location.

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
   char buf[40] = "Linus Torvalde\nSystem V shared memory\n";

   key = ftok("shmv",72);

   //int shmget (ket_t key, size_t size, int shmflg);
   shm_id = shmget(key, 1024, 0644 | IPC_CREAT);
   if(shm_id == -1)
   {
      printf("Error shmget\n");
   }

   //	void *shmat(int shmid, const void *shmaddr, int shmflg);
   ptr = (char *) shmat(shm_id, NULL, SHM_RND);
   perror("shmat()");
   strcpy(ptr, buf);

   shmdt(ptr);
   perror("shmdt()");
}
