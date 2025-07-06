#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t* head);
node_t* create_node_beginning(int value);

#endif
