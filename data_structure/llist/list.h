#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>

struct node {
    void *data;
    struct node *prev;
    struct node *next;
};

typedef struct node_head {
    int size;
    struct node head;
}LIST_H;

LIST_H * list_creat(int size);
int list_insert(LIST_H *);
int list_delete(LIST_H *, void *key);
int list_featch(LIST_H *, void *key, void *data);
int list_find(LIST_H *, void *key);
int list_show(LIST_H *);
void list_destroy(LIST_H *);

#endif
