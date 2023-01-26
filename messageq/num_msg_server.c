/******************************************************************f************************************/
/*      NAME        : R.Mutharasu.                                                                     */
/*      DATE        : 26-12-2022.                                                                      */
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

#define BUF_SIZE 4096

//      message queue struct
struct mymsg_buf
{
        long msg_type;                  //       /* message type, must be > 0 */
        char msg_text[200];             //      /* message data */
};

int main()
{
        key_t key, key1, key2, key3, key4;
        int msg_id5, msg_id1, msg_id2, msg_id3, msg_id4;
        struct msqid_ds muthu;  
        
        char str1[] = " msg1 Linus Torvalus \n";
        char str2[] = " msg2 Dennis Ritchie \n";
        char str3[] = " msg3 School of linux \n";
        char str4[] = " \n msg4 Dharmapuri \n";
        char str5[] = " msg5 Mutharasu \n";
        
        struct mymsg_buf msg1;
        struct mymsg_buf msg2;
        struct mymsg_buf msg3;
        struct mymsg_buf msg4;
        struct mymsg_buf msg5;

        int msg_len = strlen(str1);
        
        msg1.msg_type = 1;
        msg2.msg_type = 2;
        msg3.msg_type = 3;
        msg4.msg_type = 4;
        msg5.msg_type = 5;

        key = ftok ( "msgq", 72 );      //      create a IPC first key.
        if( key == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }
        
        printf("server : system V IPC u_key %u\n",key);

        //      int msgget (key_t key, int msgflg);
        msg_id1 = msgget ( key, 0664 | IPC_CREAT );      //      get a System V message queue identifier.
        if ( msg_id1 == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        }      

        printf("server : message queue id : %d\n",msg_id1);

        key1 = ftok ( "msq1", 24 );      //      create a IPC second key.
        if( key1 == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }
        
        printf("server : system V IPC u_key1 %u\n",key1);

        msg_id2 = msgget ( key1, 0664 | IPC_CREAT );      //      get a System V message queue identifier.
        if ( msg_id1 == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        } 
        printf("server : message queue id : %d\n",msg_id2);
         
        key2 = ftok ( "msq2", 34 );      //      create a IPC second key.
        if( key2 == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }
        
        printf("server : system V IPC u_key2 %u\n",key2);

        msg_id3 = msgget ( key2, 0664 | IPC_CREAT );      //      get a System V message queue identifier.
        if ( msg_id3 == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        }  
        printf("server : message queue id : %d\n",msg_id3);

        key3 = ftok ( "msq3", 44 );      //      create a IPC second key.
        if( key3 == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }
        printf("server : system V IPC u_key3 %u\n",key3);

        msg_id4 = msgget ( key3, 0664 | IPC_CREAT );      //      get a System V message queue identifier.
        if ( msg_id4 == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        }  
        printf("server : message queue id : %d\n",msg_id4);

        key4 = ftok ( "msq4", 54 );      //      create a IPC second key.
        if( key4 == -1 )
        {
                perror("server : ftok() failed to create unique key\n");
                exit( -1 );
        }  
        printf("server : system V IPC u_key4 %u\n",key4);

        msg_id5 = msgget ( key4, 0664 | IPC_CREAT );      //      get a System V message queue identifier.
        if ( msg_id5 == -1 )
        {
                perror("server msgget failed to create msg queue id\n");
                exit( -1 );
        }  
        printf("server : message queue id : %d\n",msg_id5);

        strncpy ( msg1.msg_text, str1, msg_len );       //      copy a string, char *strncpy(char *dest, const char *src, size_t n);
        strncpy ( msg2.msg_text, str2, msg_len );
        strncpy ( msg3.msg_text, str3, msg_len );
        strncpy ( msg4.msg_text, str4, msg_len );
        strncpy ( msg5.msg_text, str5, msg_len );

        //      send message.
       //      int msgsnd (int msqid, const void *msgp, size_t msgsz, int mgflg );
        if( msgsnd ( msg_id1, &msg1, msg_len, 1 ) == -1 )
        {
                perror("server : failed to send message\n");
                exit( -1 );
        }
        
        if( msgsnd ( msg_id2, &msg2, msg_len, 1 ) == -1 )
        {
                perror("server : failed to send message\n");
                exit( -1 );
        }

        if( msgsnd ( msg_id3, &msg3, msg_len, 1 ) == -1 )
        {
                perror("server : failed to send message\n");
                exit( -1 );
        }
        if( msgsnd ( msg_id4, &msg4, msg_len, 1 ) == -1 )
        {
                perror("server : failed to send message\n");
                exit( -1 );
        }
        if( msgsnd ( msg_id5, &msg5, msg_len, 1 ) == -1 )
        {
                perror("server : failed to send message\n");
                exit( -1 );
        }
        printf("server : message send successfly\n");      
        printf("server : waiting (20 sec) for clint......\n");

        sleep(20);

        printf("server : Removing message queue\n");

        //      int msgctl ( int msqid, int cmd, struct msqid_ds *buf);

        if(msgctl ( msg_id1, IPC_RMID, &muthu ) == -1)
        {
                perror("server : message ctrl\n");
                exit ( -1 );
        }

        if(msgctl ( msg_id2, IPC_RMID, &muthu ) == -1)
        {
                perror("server : message ctrl\n");
                exit ( -1 );
        }

        if(msgctl ( msg_id3, IPC_RMID, &muthu ) == -1)
        {
                perror("server : message ctrl\n");
                exit ( -1 );
        }
        if(msgctl ( msg_id4, IPC_RMID, &muthu ) == -1)
        {
                perror("server : message ctrl\n");
                exit ( -1 );
        }
        if(msgctl ( msg_id5, IPC_RMID, &muthu ) == -1)
        {
                perror("server : message ctrl\n");
                exit ( -1 );
        }
        printf("server : message queue removed successfuly\n");
}
