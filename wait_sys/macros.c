#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
   pid_t pid, wait_rv, status;

   pid = fork();

   if( pid == 0)
   {
      printf("child process pid : %d\n",getpid());
      sleep(10);
      exit(100);
   }

   else if(pid > 0)
   {
      printf("parent process pid : %d\n",getpid());
      wait_rv = waitpid( -1, &status, 0 );
      printf("after wait    \n");
      printf("wait_rv : %d\n",wait_rv);
      printf("status  : %d\n",status);
      printf("WIFEXITED(status) : %d\n",WIFEXITED(status));
      printf("WEXITSTATUS(status) : %d\n",WEXITSTATUS(status));
      printf("WIFSIGNALED(status) : %d\n",WIFSIGNALED(status));
      printf("WTERMSIG(status) : %d\n",WTERMSIG(status));
   }
}
