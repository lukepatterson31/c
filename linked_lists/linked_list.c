#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node * next;
} Node_t;

void print_list(Node_t * head)
{
    Node_t * current = head;
    while(current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void push(Node_t * head, int value)
{
    Node_t * current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = (Node_t *) malloc(sizeof(Node_t));
    current->next->value = value;
    current->next->next = NULL;
}

int main()
{
    Node_t * head = NULL;
    head = (Node_t *) malloc(sizeof(Node_t));
    if(head = NULL)
    {
        return 1;
    }
    head->value = 1;
    head->next = (Node_t *) malloc(sizeof(Node_t));
    head->next->value = 2;
    head->next->next = NULL;
    push(head, 3);
    
    free(head->next->next);
    free(head->next);
    free(head);
}