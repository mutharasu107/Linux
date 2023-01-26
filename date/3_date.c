// get time in seconds.
// This program asctime.

#include <time.h>
#include <stdio.h>

int main()
{
        time_t tm;
        struct tm *my_tm;
        char *tm_str;

        //time_t time(time_t *tloc);
        tm = time( NULL );

        my_tm = localtime( &tm );

        //        char *ctime(const time_t *timep);
        tm_str = asctime ( my_tm );        
        printf(" Date : %s", tm_str);
}
