/*****************************************************************/
/* NAME        : MUTHARASU R                                     */
/* DATAE       : 1-11-2022                                       */
/* DESCRIPTION : How creating fork for tree.                     */
/*****************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
        fork();         /* creating child process 1 */
        fork();         /* creating child process 2 */
        fork();         /* creating child process 3 */
        fork();         /* creating child process 4 */
        printf("Hello World\n");
}
/*
                                                      fork()
                                                        |
                                                        |
                                                     child(1)
                                                        |
                                                        |
                               ------------------------------------------------
                               |                                              |
                               |                                              |
                            child(2)                                       child(2)
                               |                                              |
                               |                                              |
                     --------------------                        ---------------------------
                     |                  |                        |                         |
                     |                  |                        |                         |
                  child(3)           child(3)                 child(3)                  child(3)
                     |                  |                        |                         |
                     |                  |                        |                         |
                ----------         -----------              ----------                -----------
                |        |         |         |              |        |                |         |
                |        |         |         |              |        |                |         |
             child(4) child(4)  child(4)  child(4)       child(4) child(4)         child(4)  child(4) 
*/                                                   
