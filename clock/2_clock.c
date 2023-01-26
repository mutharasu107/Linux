//how clock will jenerate.

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

        printf("%ld clock used\n",( en-st ) );

}
