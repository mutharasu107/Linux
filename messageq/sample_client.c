/*******************************************************************************************************/
/*      NAME        : R.Mutharasu.                                                                     */
/*      DATE        : 22-12-2022.                                                                      */
/*      TITTLE      : Recevir program using messange queue                                             */
/*      DESCRIPTION : sendeing to the many data using message id, key, using ftok and message control. */
/*******************************************************************************************************/
 
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//      message queue struct
struct mymsg_buf
{
        long msg_type;
        char msg_text[200];
};

int main()
{
        key_t key;
        int msg_id;
        struct mymsg_buf msg;
        ssize_t numRead;

        key = ftok ( "msgq", 72 );
        if( key == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }
        
        printf("client : system V IPC u_key %u\n",key);

        msg_id = msgget ( key, 0664 | IPC_CREAT );
        if ( msg_id == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        }      

        printf("client : message queue id : %d\n",msg_id);

        //      ssize_t msgrcv (int msqid, void *msgp, size_t msgsz, long msg typ, int msgflg);

        if( ( numRead = msgrcv (msg_id, &msg, sizeof msg.msg_text, 1, 0 )) == -1)
        {
                perror("client : msgrcv failed");
                exit ( -1 );
        }

        else 
        {
                write(STDOUT_FILENO, msg.msg_text, numRead);
        }
        
        if( ( numRead = msgrcv (msg_id, &msg, sizeof msg.msg_text, 1, 0 )) == -1)
        {
                perror("client : msgrcv failed");
                exit ( -1 );
        }

        else 
        {
                write(STDOUT_FILENO, msg.msg_text, numRead);
        }
        
}
