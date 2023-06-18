#include "list.h"

LIST_H * list_creat(int size)
{
    LIST_H *new;
    new = malloc(sizeof(*new));
    if(new == NULL)
            return NULL;
    new->size = size;
    new->prev = new.head;
    new->next = new.head;

    return new;
}

int list_insert(LIST_H *, strcut node )
{
    
}
int list_delete(LIST_H *, void *key)
int list_featch(LIST_H *, void *key, void *data)
int list_find(LIST_H *, void *key)
int list_show(LIST_H *)
void list_destroy(LIST_H *list)
{
    LIST_H *cur, *next;
    for(cur = list->next; cur->next != list; cur = next)
    {
            next = cur->next;
            free(cur->data);
            free(cur);
    }
    free(list);
}

