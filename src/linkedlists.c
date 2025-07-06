#include <stdlib.h>
#include <stdio.h>
#include <linkedlists.h>

void LL_append(node_t* head, int value);
void LL_print(node_t* head);
void LL_push(node_t** head, int value);

int main(){

    node_t * head = (node_t *) malloc(sizeof(node_t));
    head->val = 1;
    head->next = NULL;
    LL_print(head);
    LL_append(head, 2);
    LL_print(head);
    LL_push(&head, 3);
    LL_print(head);

    return 0;
}

void LL_print(node_t* head){
    node_t* itr = head;
    while (itr != NULL){
        printf("%d", itr->val);
        itr = itr->next;
        if (itr != NULL){
            printf(" -> ");
        }
    }
    printf("\n");
}

void LL_append(node_t* head, int value) {
    node_t* itr = head;

    while(itr->next != NULL){
        itr = itr->next;

    }

    itr->next = (node_t*) malloc(sizeof(node_t));
    itr->next->val = value;
    itr->next->next = NULL;

}

void LL_push(node_t** head, int value){
    node_t* new = (node_t*) malloc(sizeof(node_t));
    
    new->val = value;
    new->next = *head;
    *head = new;

}