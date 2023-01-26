#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct mymsg_buf
{
        long msg_type;
        char msg_text[200];
};

int main()
{
        int msq_id, i;
        ssize_t rec_byts;
        struct mymsg_buf my_dt1;

        //int msgget ( key_t key, int msgflg );
        msq_id = msgget ( 72, 0664 | IPC_CREAT );
                perror("megget");

        //ssize_t msgrcv( int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg );
        for(i = 1; i<6; i++)
        {
                rec_byts = msgrcv( msq_id, &my_dt1, 200, i, 1 );

                printf("msg id : %ld\n",my_dt1.msg_type);
                write( STDOUT_FILENO, my_dt1.msg_text,rec_byts);
        }

}
