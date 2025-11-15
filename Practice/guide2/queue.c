#include<stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

int is_empty(struct Node* head);

void enqueue(struct Node** head, int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    (*new_node).value = value;
    (*new_node).next = NULL;

   if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* current = *head;
    while ((*current).next != NULL) {
        current = (*current).next;
    }
    (*current).next = new_node;
}

int dequeue(struct Node** head){
    
    if (is_empty(*head)==1) {
        return -1;
    }

    struct Node* temp = *head;
    int value = (*temp).value;
    *head = (*temp).next;
    free(temp);
    return value;
}

int is_empty(struct Node* head){
    if (head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void freeQueue(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    
    while(current != NULL) {
        next = (*current).next; 
        free(current);          
        current = next;         
    }
    
    *head = NULL; // Reinicio la queue
}

void print(struct Node* head) {
    struct Node* current = head;
    
    if (current == NULL) {
        printf("Queue vacía\n");
        return;
    }
    
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", (*current).value);
        current = (*current).next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    enqueue(&head, 5);
    enqueue(&head, 10);
    enqueue(&head, 15);
    print(head);
    dequeue(&head);
    print(head);
    freeQueue(&head);
    print(head);

    return 0;
}