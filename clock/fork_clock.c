/* fork using child process how many time will running checking */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>

int main()
{
        int clock_tck_per_sec;
        pid_t pid;
        long i,j;
        struct tms st;
        clock_t dub;

        pid = fork();
        //      long sysconf(int name);
        clock_tck_per_sec = sysconf(_SC_CLK_TCK);       //The number of clock ticks per second.

        if( pid == -1 )
        {
                perror("fork()"); 
        }

        else if( pid == 0 )
        {
                for(i=0, j=0; i<1000000; i++)           
                    j+=i;
                    exit(0);
        }

        else if( pid > 0 )
        { 
                printf("process was dubbed %f seconds ago.\n\n",((double) dub)/clock_tck_per_sec);
                printf("          utime                 stime\n");
                printf("parent     %f         %f\n",((double) st.tms_utime)/clock_tck_per_sec,((double) st.tms_stime)/clock_tck_per_sec);
                printf("child      %f         %f\n",((double) st.tms_cutime)/clock_tck_per_sec,((double) st.tms_cstime)/clock_tck_per_sec);
        }
}
