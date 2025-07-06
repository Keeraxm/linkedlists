#include <stdlib.h>
#include <stdio.h>
#include <linkedlists.h>

int main(){
    return 0;
}


node_t* LL_create(int value){
    node_t * head = (node_t *) malloc(sizeof(node_t));
    head->val = value;
    head->next = NULL;
    return head;
}

void LL_print(node_t* head){
    node_t* itr = head;

    // traverse the list.
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

    // traverse the list to last index.
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

int LL_pop(node_t** head){
    node_t* next_node = NULL;
    int return_value = -1;

    // incase of empty/non-initialized list.
    if (*head == NULL){
        return -1;
    }

    next_node = (*head)->next;
    return_value = (*head)->val;
    free(*head);
    *head = next_node;
    return return_value;
}

int LL_delete_index(node_t** head, int index){
    node_t* itr = *head;
    node_t* prev_node = NULL;
    int return_value = -1;

    // remove head if index 0.
    if (index == 0) {
        return LL_pop(head);
    }

    // traverse the list and save index-1 node.
    for(int i = 0; i < index; i++){
        if(i == index-1){
            prev_node = itr;
        }
        itr = itr->next;
    }

    prev_node->next = itr->next;
    return_value = itr->val;
    free(itr);
    return return_value;

}

int LL_delete_last(node_t** head){
    node_t* itr = *head;
    int return_value = -1;
    
    // if list contains only 1 item.
    if ((*head)->next == NULL){
        return LL_pop(head);
    }

    // traverse the list to 2nd-to-last index.
    while(itr->next->next != NULL){
        itr = itr->next;
    }

    return_value = itr->next->val;
    free(itr->next->next);
    itr->next = NULL;
    return return_value;
}

int LL_delete_value(node_t** head, int value){
    node_t* itr = *head;
    node_t* del_node = NULL;
    int return_value = -1;

    // if value is at head, remove head.
    if ((*head)->val == value){
        return LL_pop(head);
    }

    // traverse the list
    while(itr->next->val != value){
        itr = itr->next;

        // if value doesn't exist.
        if ((itr->next->next == NULL) && (itr->next->val != value)){
            return -1;
        }
    }

    del_node = itr->next;
    return_value = del_node->val;

    itr->next=del_node->next;
    free(del_node);
    return return_value;
}