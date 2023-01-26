#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct mymsg_buf
{
        long msg_type;
        char msg_text[200];
};

int main()
{
        int msgid;
        char str1[]="msg1: Linus Torvalds\n";
        char str2[]="msg2: school of linux\n";
        char str3[]="msg3: Dharmapuri\n";
        char str4[]="msg4: Dennis Ritchie\n";
        char str5[]="msg5: Muthu\n";
        struct mymsg_buf my_dt1;
        struct mymsg_buf my_dt2;
        struct mymsg_buf my_dt3;
        struct mymsg_buf my_dt4;
        struct mymsg_buf my_dt5;
        int msg_len = strlen(str1);
        my_dt1.msg_type = 1;
        my_dt2.msg_type = 2;
        my_dt3.msg_type = 3;
        my_dt4.msg_type = 4;
        my_dt5.msg_type = 5;
        strncpy( my_dt1.msg_text, str1, msg_len );
        strncpy( my_dt2.msg_text, str2, msg_len );
        strncpy( my_dt3.msg_text, str3, msg_len );
        strncpy( my_dt4.msg_text, str4, msg_len );
        strncpy( my_dt5.msg_text, str5, msg_len );

        //int msgget ( key_t key, int msgflg );
        msgid = msgget ( 72, 0664 | IPC_CREAT );
                perror("megget");

        //int msgnd ( int msqid, const void *msgp, size_t msgsz, int  msgflg );
        msgsnd ( msgid, &my_dt1, msg_len, 1);
                perror("msgsnd");
        
        msgsnd ( msgid, &my_dt2, msg_len, 1);
                perror("msgsnd");

        msgsnd ( msgid, &my_dt3, msg_len, 1);
                perror("msgsnd");

        msgsnd ( msgid, &my_dt4, msg_len, 1);
                perror("msgsnd");

        msgsnd ( msgid, &my_dt5, msg_len, 1);
                perror("msgsnd");
}
