//how clock real time using.
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
        clock_gettime( CLOCK_REALTIME, &st);

        for( i=0; i<1000000000; i++ );

        clock_gettime( CLOCK_REALTIME, &en);
        sleep( 1 );
        
        printf("st %ld  sec \n", st.tv_sec);
        printf("st %ld  nano sec\n", st.tv_nsec);

        printf("en %ld  sec \n", en.tv_sec);
        printf("en %ld  nano sec\n", en.tv_nsec);

        printf("%ld  sec \n", (en.tv_sec - st.tv_sec));
        printf("%ld  nano sec\n",(en.tv_nsec -  st.tv_nsec));

}
