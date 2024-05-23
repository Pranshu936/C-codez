#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a node after a particular node
void insertAfterNode(struct Node** head, struct Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next->prev = new_node;
    prev_node->next = new_node;

    if (prev_node == *head && (*head)->prev == prev_node) {
        (*head)->prev = new_node;
    }
}

// Function to insert a node before a particular node
void insertBeforeNode(struct Node** head, struct Node* next_node, int data) {
    if (next_node == NULL) {
        printf("The given next node cannot be NULL\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    new_node->prev = next_node->prev;
    new_node->next = next_node;
    next_node->prev->next = new_node;
    next_node->prev = new_node;

    if (next_node == *head) {
        *head = new_node;
    }
}

// Function to search a particular node
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head;
    if (head == NULL) return NULL;

    do {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    } while (current != head);

    return NULL;
}

// Function to get a particular node
struct Node* getNode(struct Node* head, int position) {
    struct Node* current = head;
    int count = 1;

    if (head == NULL) return NULL;

    do {
        if (count == position) {
            return current;
        }
        count++;
        current = current->next;
    } while (current != head);

    return NULL;
}

// Function to delete a node before a particular node
void deleteBeforeNode(struct Node** head, struct Node* next_node) {
    if (next_node == NULL || next_node->prev == next_node) return;

    struct Node* temp = next_node->prev;

    if (temp == *head) {
        *head = next_node;
    }

    next_node->prev = temp->prev;
    temp->prev->next = next_node;

    free(temp);
}

// Function to delete a particular node
void deleteNode(struct Node** head, struct Node* del_node) {
    if (*head == NULL || del_node == NULL) return;

    if (*head == del_node) {
        *head = del_node->next;
    }

    del_node->prev->next = del_node->next;
    del_node->next->prev = del_node->prev;

    if (del_node == *head && del_node->next == del_node) {
        *head = NULL;
    }

    free(del_node);
}

// Function to print the circular doubly linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

int main() {
    struct Node* head = NULL;
    struct Node* temp;

    // Creating the circular doubly linked list
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 10;
    head = temp;
    head->next = head;
    head->prev = head;

    struct Node* node20 = (struct Node*)malloc(sizeof(struct Node));
    node20->data = 20;
    node20->next = head;
    node20->prev = head;
    head->next = node20;
    head->prev = node20;

    struct Node* node30 = (struct Node*)malloc(sizeof(struct Node));
    node30->data = 30;
    node30->next = head;
    node30->prev = node20;
    node20->next = node30;
    head->prev = node30;

    // Insert after node20
    insertAfterNode(&head, node20, 25);
    printList(head);

    // Insert before node20
    insertBeforeNode(&head, node20, 15);
    printList(head);

    // Search for a node with data 25
    struct Node* foundNode = searchNode(head, 25);
    if (foundNode != NULL) {
        printf("Node with data 25 found.\n");
    } else {
        printf("Node with data 25 not found.\n");
    }

    // Get node at position 3
    struct Node* nodeAtPos = getNode(head, 3);
    if (nodeAtPos != NULL) {
        printf("Node at position 3: %d\n", nodeAtPos->data);
    } else {
        printf("No node found at position 3\n");
    }

    // Delete node before node30
    deleteBeforeNode(&head, node30);
    printList(head);

    // Delete node with data 25
    struct Node* delNode = searchNode(head, 25);
    deleteNode(&head, delNode);
    printList(head);

    return 0;
}
