#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a node after a particular node
void insertAfterNode(struct Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to insert a node before a particular node
void insertBeforeNode(struct Node** head, struct Node* next_node, int data) {
    if (*head == next_node) {
        insertAtBeginning(head, data);
        return;
    }
    
    struct Node* temp = *head;
    while (temp != NULL && temp->next != next_node) {
        temp = temp->next;
    }
    if (temp != NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = next_node;
        temp->next = new_node;
    }
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("The given position is out of range\n");
        free(new_node);
        return;
    }
    
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to search a particular node
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to get a particular node
struct Node* getNode(struct Node* head, int position) {
    struct Node* current = head;
    int count = 1;
    while (current != NULL) {
        if (count == position) {
            return current;
        }
        count++;
        current = current->next;
    }
    return NULL;
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// Function to delete a node after a particular node
void deleteAfterNode(struct Node* prev_node) {
    if (prev_node == NULL || prev_node->next == NULL) {
        printf("The given node is not valid or there is no next node\n");
        return;
    }
    struct Node* temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Function to delete a node before a particular node
void deleteBeforeNode(struct Node** head, struct Node* next_node) {
    if (*head == NULL || *head == next_node) return;

    struct Node* temp = *head;
    if (temp->next == next_node) {
        *head = next_node;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != NULL && temp->next != next_node) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == next_node) {
        prev->next = next_node;
        free(temp);
    }
}

// Function to delete a particular node by key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtPosition(&head, 25, 3);
    printList(head);
    
    struct Node* foundNode = searchNode(head, 25);
    if (foundNode != NULL) {
        printf("\nNode with data 25 found.\n");
    } else {
        printf("\nNode with data 25 not found.\n");
    }

    struct Node* nodeAtPos = getNode(head, 2);
    if (nodeAtPos != NULL) {
        printf("\nNode at position 2: %d\n", nodeAtPos->data);
    } else {
        printf("\nNo node found at position 2\n");
    }

    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteNode(&head, 25);
    deleteAtPosition(&head, 2);
    printList(head);

    return 0;
}
