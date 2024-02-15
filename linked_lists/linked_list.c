#include <stdio.h>

typedef struct Node{
    int value;
    struct Node * next;
} Node_t;

void print_list(Node_t * head){
    Node_t * current = head;
    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }
}

void push(Node_t ** head, int value){
    Node_t * new_node;
    new_node = (Node_t *) malloc(sizeof(Node_t));

    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

int pop(Node_t ** head){
    int retval = -1;
    Node_t * next_node = NULL;

    if (*head == NULL){
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->value;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_last(Node_t * head){
    int retval = 0;
    
    if (head->next == NULL){
        retval = head->value;
        free(head);
        return retval;
    }

    Node_t * current = head;
    while (current->next->next != NULL){
        current = current->next;
    }

    retval = current->next->value;
    free(current->next);
    current->next = NULL;
    return retval;
}

int remove_by_index(Node_t ** head, int n){
    int i = 0;
    int retval = -1;
    Node_t * current = *head;
    Node_t * temp_node = NULL;

    if (n == 0){
        return pop(head);
    }

    for (i = 0; i < n-1; i++){
        if (current->next == NULL){
            return retval;
        }
        
        current = current->next;
    }

    if (current->next == NULL){
        return retval;
    }
    
    temp_node = current->next;
    retval = temp_node->value;
    current->next = temp_node->next;
    free(temp_node);
    
    return retval;
}

int remove_by_value(Node_t ** head, int val) {
    int retval = -1;
    
    if (*head == NULL){
        return retval;
    }

    Node_t * previous = *head;
    Node_t * current = *head;
    
    while (current->value != val){
        previous = current;
        current = current->next;
    }

    if (current->next == NULL){
        return retval;
    }

    previous->next = current->next;
    retval = current->value;
    free(current);

    return retval;
}

int main(){
    Node_t * head = NULL;
    head = (Node_t *) malloc(sizeof(Node_t));

    if (head = NULL){
        return 1;
    }
    
    head->value = 1;
    head->next = (Node_t *) malloc(sizeof(Node_t));
    head->next->value = 2;
    head->next->next = NULL;
    push(head, 0);
    
    free(head->next->next);
    free(head->next);
    free(head);
}