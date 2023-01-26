// get time in seconds.
// This program localtime using struct.

#include <time.h>
#include <stdio.h>

int main()
{
        time_t tm;
        struct tm *my_tm;

        // time_t time(time_t *tloc);
        tm = time(NULL);

        //struct tm *localtime(const time_t *timep);
        my_tm = localtime(&tm);

        printf("TIME : %d-",my_tm->tm_hour-12);          /* Hours (0-23) */
        printf("%d-",my_tm->tm_min);            /* Minutes (0-59) */
        printf("%d\n",my_tm->tm_sec);            /* Seconds (0-60) */
        printf("DATE : %d-",my_tm->tm_mday);           /* Day of the month (1-31) */
        printf("%d-",my_tm->tm_mon+1);          /* Month (0-11) */
        printf("%d\n",my_tm->tm_year+1900);     /* year - 1900 */
        printf("DAY OF THE WEEK : %d\n",my_tm->tm_wday);          /* Day of the week (0-6, Sunday = 0) */
        printf("DAY OF THE YEAR : %d\n",my_tm->tm_yday);          /* Day of the year (0-365, 1 jan = 0) */
}
