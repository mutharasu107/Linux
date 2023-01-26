/******************************************************************f************************************/
/*      NAME        : R.Mutharasu.                                                                     */
/*      DATE        : 22-12-2022.                                                                      */
/*      TITTLE      : Sender program using messange queue.                                             */
/*      DESCRIPTION : sendeing to the many data using message id, key, using ftok and message control. */
/*******************************************************************************************************/
 
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
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
        int msg_id, msg_len;
        struct msqid_ds muthu;  
        struct mymsg_buf msg;
        char str1[] = " msg1 Linus Torvalds\n Dennis Ritchie\n Linux\n Dharmapuri\n";

        key = ftok ( "msgq", 72 );
        if( key == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }
        
        printf("server : system V IPC u_key %u\n",key);

        //      creating msg queue id.
        //      int msgget (key_t key, int msgflg);
        msg_id = msgget ( key, 0664 | IPC_CREAT );
        if ( msg_id == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        }      

        printf("server : message queue id : %d\n",msg_id);

        msg_len  = strlen ( str1 );
//        msg_len1 = strlen ( str2 );

        strncpy ( msg.msg_text, str1, msg_len );
//        strncpy ( msg.msg_text, str2, msg_len1 );

        msg.msg_type = 1;

        //      send message.
        //      int msgsnd (int msqid, const void *msgp, size_t msgsz, int mgflg );

        if( msgsnd ( msg_id, &msg, msg_len, 0) == -1 )
        {
                perror("server : failed to send message\n");
                exit( -1 );
        }
        
        printf("server : message send successfly\n");      
        printf("server : waiting (10 sec) for clint......\n");

        sleep(10);

        printf("server : Removing message queue\n");

        //      int msgctl ( int msqid, int cmd, struct msqid_ds *buf);

        if(msgctl (msg_id, IPC_RMID,&muthu) == -1)
        {
                perror("server : message ctrl\n");
                exit ( -1 );
        }

        printf("time of last message send   : %ld\n", muthu.msg_stime);
        printf("last modification by msgctl : %ld\n", muthu.msg_ctime);
        printf("pid of the sender           : %d\n", muthu.msg_lspid);

        printf("server : message queue removed successfuly\n");
}
