// get time in seconds.
// This program print out put is epoch number.
// out put : 1671453678.

#include <time.h>
#include <stdio.h>

int main()
{
        time_t tm;

        // time_t time(time_t *tloc);

        tm = time(NULL);

        printf("%ld\n", tm);
}
