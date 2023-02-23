#ifndef _PROTO_H_
#define _PROTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#define BUFSIZE 32

#define PATH "/home/yardie/Desktop/apue/Interprocess_communication/msg"

#define PROJ 'a'

struct msg_st
{
    long mtype;
    char name[BUFSIZE];
};


#endif
