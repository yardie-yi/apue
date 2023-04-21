#ifndef _LINGPAITONG_H_
#define _LINGPAITONG_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX 10
typedef void ptf;

ptf *init_ptf(int cps, int brust);

int fetch_ptf(ptf *in_ptf, int get_num);

int return_ptf(ptf *in_ptf, int return_num);

int destory_ptf(ptf *del_ptf);

#endif
