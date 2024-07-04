#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

struct Node* push(struct Node* top, int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
    return top;
}

int pop(struct Node* tp) {
    if (isEmpty(tp)) {
        printf("Stack Underflow\n");
        return -1; // Return an error value
    } else {
        struct Node* n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(struct Node* tp) {
    if (isEmpty(tp)) {
        printf("Stack is empty\n");
        return -1; // Return an error value
    } else {
        return tp->data;
    }
}

int main() {
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);

    linkedListTraversal(top);

    int element = pop(top);
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);

    int topElement = peek(top);
    if (topElement != -1) {
        printf("Top element is %d\n", topElement);
    }

    return 0;
}
