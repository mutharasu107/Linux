/*******************************************************************************************************/
/*      NAME        : R.Mutharasu.                                                                     */
/*      DATE        : 26-12-2022.                                                                      */
/*      TITTLE      : Recevir program using messange queue                                             */
/*      DESCRIPTION : sendeing to the many data using message id, key, using ftok and message control. */
/*******************************************************************************************************/
 
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 512
//      message queue struct
struct mymsg_buf
{
        long msg_type;
        char msg_text[BUF_SIZE];
};

int main()
{ 
        key_t key, key1, key2, key3, key4;
        int msg_id5, msg_id1,msg_id2, msg_id3, msg_id4;
        struct mymsg_buf msg;
        struct msqid_ds str;
        ssize_t numRead;
        int i, j;
        
        key = ftok ( "msgq", 72 );
        if( key == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }
        
        printf("client : system V IPC u_key %u\n",key);

        msg_id1 = msgget ( key, 0664 | IPC_CREAT );
        if ( msg_id1 == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        }      

        printf("client : message queue id : %d\n",msg_id1);

        key1 = ftok ( "msq1", 24 );
        if( key1 == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }
        printf("client : system V IPC u_key %u\n",key1);

        msg_id2 = msgget ( key1, 0664 | IPC_CREAT );
        if ( msg_id2 == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        }   
        printf("client : message queue id : %d\n",msg_id2);

        key2 = ftok ( "msq2", 34 );
        if( key1 == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }
        
        printf("client : system V IPC u_key2 %u\n",key2);

        msg_id3 = msgget ( key2, 0664 | IPC_CREAT );
        if ( msg_id3 == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        }
        printf("client : message queue id : %d\n",msg_id3);
   
        key3 = ftok ( "msq3", 44 );
        if( key3 == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }
        printf("client : system V IPC u_key3 %u\n",key3);

        msg_id4 = msgget ( key3, 0664 | IPC_CREAT );
        if ( msg_id4 == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        } 
        printf("client : message queue id : %d\n",msg_id4);
  
        key4 = ftok ( "msq4", 54 );
        if( key4 == -1 ) 
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        } 
        printf("client : system V IPC u_key4 %u\n",key4);

        msg_id5 = msgget ( key4, 0664 | IPC_CREAT );
        if ( msg_id5 == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        }  
        printf("client : message queue id : %d\n",msg_id5);
/*************************************************************************************************/
/*                                      METHOD-1                                                  */
/**************************************************************************************************/
/*      This method using loop write the value                                                    */
/*      method 1                                                                                  */

/*        for(j=1; j<6; j++) 
        {
                numRead = msgrcv (msg_id1++ , &msg, sizeof msg.msg_text, j, 1);

                write(STDOUT_FILENO, msg.msg_text, numRead);
        }
*/

/**************************************************************************************************/
/*                                       METHOD-2                                                 */
/**************************************************************************************************/
/*      method 2 using message sperate writing                                                    */

//      ssize_t msgrcv3 (int msqid, void *msgp, size_t msgsz, long msg type, int msgflg);
        scanf("%d",&i);
        if(i == msg_id1){        
        if( ( numRead = msgrcv (msg_id1, &msg, sizeof msg.msg_text, 1, 1 )) == -1)
        {
                perror("client : msgrcv failed");
                exit ( -1 );
        }
                
        else 
        {
                write(STDOUT_FILENO, msg.msg_text, numRead);
        }
        }
 
        if(i == msg_id2){        
        if( ( numRead = msgrcv (msg_id2, &msg, sizeof msg.msg_text, 2, 1 )) == -1)
        {
                perror("client : msgrcv failed");
                exit ( -1 );
        }
 
        else 
        {
                write(STDOUT_FILENO, msg.msg_text, numRead);
        }
        }

        if(i == msg_id3){        
        if( ( numRead = msgrcv (msg_id3, &msg, sizeof msg.msg_text, 3, 1 )) == -1)
        {
                perror("client : msgrcv failed");
                exit ( -1 );
        }
 
        else 
        {
                write(STDOUT_FILENO, msg.msg_text, numRead);
        }
        }

        if(i == msg_id4){        
        if( ( numRead = msgrcv (msg_id4, &msg, sizeof msg.msg_text, 4, 1 )) == -1)
        {
                perror("client : msgrcv failed");
                exit ( -1 );
        }
 
        else 
        {
                write(STDOUT_FILENO, msg.msg_text, numRead);
        }
        }

        if(i == msg_id5){        
        if( ( numRead = msgrcv (msg_id5, &msg, sizeof msg.msg_text, 5, 1 )) == -1)
        {
                perror("client : msgrcv failed");
                exit ( -1 );
        }
 
        else 
        {
                write(STDOUT_FILENO, msg.msg_text, numRead);
        }
        }

/***********************************************************************************************************/
}
