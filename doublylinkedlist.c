#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to traverse the list forward
void traverseForward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to traverse the list backward
void traverseBackward(struct Node *node) {
    while (node->next != NULL) {
        node = node->next;
    }
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

void insertAtBeginning(struct Node **headRef, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = *headRef;
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }
    *headRef = newNode;
}

void insertAtend(struct Node **headRef, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    struct Node *last = *headRef;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

void insertAfter(struct Node *prevNode, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

void deleteAtfirst(struct Node **headRef){
    struct Node *temp = *headRef;
    *headRef=(*headRef)->next;
    (*headRef)->prev=NULL;
}

void deleteAtend(struct Node **headRef){
    struct Node *temp=*headRef;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
}

void deleteAfter(struct Node *prevNode){
    struct Node *temp = prevNode->next;
    prevNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = prevNode;
    }

}

void swap(struct Node *a, struct Node *b){  
    int temp = a->data;  
    a->data = b->data;  
    b->data = temp;  
}

void bubbleSort(struct Node *head)  {  
    int swapped, i;  
    struct Node *ptr1;  
    struct Node *lptr = NULL;  
    do{  
        swapped = 0;  
        ptr1 = head;
        while (ptr1->next != lptr){  
            if (ptr1->data > ptr1->next->data){  
                swap(ptr1, ptr1->next);  
                swapped = 1;  
            }  
            ptr1 = ptr1->next;  
        }  
        lptr = ptr1;  
    }  
    while(swapped);  
}


int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = NULL;
    third->prev = second;

    insertAtBeginning(&head, 5);
    insertAtend(&head, 4);
    insertAfter(head, 6);
    deleteAtfirst(&head);
    deleteAtend(&head);
    deleteAfter(second);

    printf("Traverse forward:\n");
    traverseForward(head);

    printf("Traverse backward:\n");
    traverseBackward(head);
    bubbleSort(head);
    printf("sorted list is:-");
    traverseForward(head);

    return 0;
}
