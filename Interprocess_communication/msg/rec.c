#include "proto.h"


void main()
{

    struct msg_st buf;

    key_t  key;
    key = ftok(PATH, PROJ);
    int msg_id;
    msg_id = msgget(key, IPC_CREAT|0600);
    if (msg_id < 0){
        perror("msgget() error");
        exit(1);
    }
    while(1) {
        if (msgrcv(msg_id, &buf, sizeof(buf) - sizeof(long), 0, 0) < 0) {
            perror("msgrcv error");
            exit(1);
        }
        puts(buf.name);
    }

    msgctl(key, IPC_RMID, NULL);
    exit(0);
}
