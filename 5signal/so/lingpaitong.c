#include "lingpaitong.h"
#include <signal.h>
static int init = 0;
typedef void (*sighandler_t)(int);
static sighandler_t alarm_save;
struct ptf {
    int cps;
    int brust;
    int token;
    int pos;
};

struct ptf *ptf_array[MAX] = {NULL};

static void sighandler(int s)
{
    alarm(1);
    for(int i = 0; i < MAX; i++) {
        if (ptf_array[i] != NULL) {
            ptf_array[i]->token += ptf_array[i]->cps;
            if (ptf_array[i]->token >= ptf_array[i]->brust)
                ptf_array[i]->token = ptf_array[i]->brust;
        }
    }
}

static int get_ptf(void)
{
    for(int i = 0; i < MAX; i++) {
        if (ptf_array[i] == NULL)
            return i;
    }
    return -1;
}

void module_unload(void)
{
    signal(SIGALRM, alarm_save);
    alarm(0);
}

void module_load(void)
{
    alarm_save = signal(SIGALRM, sighandler);
    alarm(1);
    atexit(module_unload);
}

ptf *init_ptf(int cps, int brust)
{
    int pos = get_ptf();
    if (pos < 0) {
        return NULL;
    }
    struct ptf *me;
    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;
    me->cps = cps;
    me->brust = brust;
    me->token = 0;
    me->pos = pos;
    ptf_array[pos] = me;
    
    if(!init) {
        module_load();
        init = 1;
    }

    return me;
}

int destory_ptf(ptf *del_ptf)
{
    struct ptf *me = del_ptf;
    ptf_array[me->pos] = NULL;
    free(me);
}


int fetch_ptf(ptf *in_ptf, int get_num)
{
    if (get_num <= 0) {
        return -1;
    }

    struct ptf *me = in_ptf;

    while(me->token <= 0)
        pause();

    int num;
    me->token >= get_num ? num = get_num : me->token;

    me->token -= num;

    return num;
}

int return_ptf(ptf *in_ptf, int return_num)
{
    if (return_num <= 0)
        return -1;

    struct ptf *me = in_ptf;

    me->token += return_num;
    if (me->token > me->brust)
        me->token = me->brust;

    return return_num;
}
