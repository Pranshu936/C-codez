https://dpaste.org/zwdzs 
https://dpaste.org/zwdzs
About History New snippet
Python Expires in: 4 weeks, 1 day
Delete Now
Raw
Slim
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

// Define the stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element to the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
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
    
    return 0;
}
Copy Snippet
Edit Snippet
 Wordwrap
#include <stdio.h>
#include <stdlib.h>
​
#define MAX 100  // Maximum size of the stack
​
// Define the stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;
​
// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}
​
// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}
​
// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}
​
// Function to push an element to the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
    printf("Pushed %d to the stack\n", value);
}
​
// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}
​
// Function to get the top element of the stack without removing it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}
​
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
​
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
    
    return 0;
}
