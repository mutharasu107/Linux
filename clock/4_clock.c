//how clock will using clock per second.
//man 3 clock.

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>

int main()
{
        int i;
        struct tms st;
        struct tms en;

        //      clock_t times( struct tms *buf );
        times( &st );

        for( i=0; i<100000000; i++ );

        times( &en );
        
        printf("user : %ld\n", st.tms_utime);
        printf("syst : %ld\n", st.tms_stime);
        
        printf("user : %ld\n", en.tms_utime);
        printf("syst : %ld\n", en.tms_stime);

}
