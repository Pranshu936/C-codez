#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10  // Initial capacity of the stack

// Define the stack structure
typedef struct {
    int *items;
    int top;
    int capacity;
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->capacity = INITIAL_CAPACITY;
    s->top = -1;
    s->items = (int *)malloc(s->capacity * sizeof(int));
    if (s->items == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

// Function to resize the stack
void resize(Stack *s) {
    s->capacity *= 2;
    s->items = (int *)realloc(s->items, s->capacity * sizeof(int));
    if (s->items == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
}

// Function to push an element to the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        resize(s);
    }
    s->items[++(s->top)] = value;
    printf("Pushed %d to the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Function to get the top element of the stack without removing it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

// Function to display the elements of the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}

// Function to free the allocated memory for the stack
void freeStack(Stack *s) {
    free(s->items);
}

// Main function to demonstrate stack operations
int main() {
    Stack s;
    initialize(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    printf("Top element is %d\n", peek(&s));
    
    printf("Popped element is %d\n", pop(&s));
    
    display(&s);
    
    freeStack(&s);  // Free the allocated memory
    return 0;
}
