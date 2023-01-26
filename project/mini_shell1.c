#include <stdio.h> 	// printf(), fprintf(), getchar(), perror(), stderr
#include <unistd.h>	// chdir(), fork(), exec(), pid_t, getcwd()
#include <stdlib.h> 	// malloc(), realloc(), free(), exit(), execvp(), EXIT_SUCCESS, EXIT_FAILURE
#include <fcntl.h>      // filecreation modes

char PWD[1024];
//char PATH[1024];

void my_pwd();

int main()
{
   my_pwd();
}

void my_pwd(char **args)
{
   printf("%s\n",PWD);
}
