#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

typedef struct node {
    int val;
    struct node * next;
} node_t;


node_t* LL_create();
void LL_append(node_t* head, int value);
void LL_print(node_t* head);
void LL_push(node_t** head, int value);
int LL_pop(node_t** head);
int LL_delete_index(node_t** head, int index);
int LL_delete_last(node_t** head);
int LL_delete_value(node_t** head, int value);

#endif
