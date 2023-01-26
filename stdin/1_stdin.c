#include <stdio.h>
#include <unistd.h>

int main()
{
        printf("%d ", STDIN_FILENO);
        printf("%d ", STDOUT_FILENO);
        printf("%d ", STDERR_FILENO);
}
