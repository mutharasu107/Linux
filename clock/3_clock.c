//how clock will using clock per second.

#include <time.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
        int i;
        clock_t st,en;           //st means(staring time), en means(ending time);

        //      clock_t clock(void);
        st = clock();

        for( i=0; i<1000000; i++ );

        en = clock();

        double sec = (double)(en-st)/CLOCKS_PER_SEC;
        printf("%lf second used \n", sec);
        printf("%ld clock used\n",( en-st ) );

}
