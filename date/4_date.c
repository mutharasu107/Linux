// get time in seconds.
// This program ctime using this syntax equivalent of asctime.

#include <time.h>
#include <stdio.h>

int main()
{
        time_t tm;
        char *tm_str;

        //time_t time(time_t *tloc);
        tm = time( NULL );

        //        char *ctime(const time_t *timep);
        tm_str = ctime ( &tm );          //ctime(t) is equivalent to asctime (localtime(t));
        printf(" Date : %s", tm_str);
}
