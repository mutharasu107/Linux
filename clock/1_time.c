//return time is epoch only.

#include <time.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
        int i;
        time_t st,en;           //st means(staring time), en means(ending time);

        //      time_t time(time_t *tloc);
        st = time(NULL);

        for( i=0; i<1000000; i++ );
        sleep( 1 );

        en = time(NULL);

        printf("%ld second used\n",( en-st ) );

}
