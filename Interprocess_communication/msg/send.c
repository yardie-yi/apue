#include "proto.h"

void main()
{
    struct msg_st buf;

    key_t key;
    key = ftok(PATH, PROJ);
    int msg_id;
    msg_id = msgget(key, 0);
    if (msg_id < 0){
        perror("msgget eroor");
        exit(1);
    }

    strcpy(buf.name, "123");
    if (msgsnd(msg_id, &buf, sizeof(buf)-sizeof(long), 0) < 0) {
        perror("msgsend error");
        exit(1);
    }


    msgctl(key, IPC_RMID, NULL);
    puts("ok");

    exit(0);
}
