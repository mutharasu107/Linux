//how clock monotonic.
//man 3 clock.

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>

int main()
{
        int i;
        struct timespec st;
        struct timespec en;

        //      int clock_gettime (clock id_t clk_id, struct_time, spec *tp);
        clock_gettime( CLOCK_MONOTONIC, &st);

        for( i=0; i<100000000; i++ );

        clock_gettime( CLOCK_MONOTONIC, &en);
        
        printf("%ld  sec \n", st.tv_sec);
        printf("%ld  nano sec\n", st.tv_nsec);

        printf("%ld  sec \n", en.tv_sec);
        printf("%ld  nano sec\n", en.tv_nsec);

        printf("%ld  sec \n", (en.tv_sec - st.tv_sec));
        printf("%ld  nano sec\n",(en.tv_nsec -  st.tv_nsec));

}
