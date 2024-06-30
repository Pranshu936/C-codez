#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Initial capacity of the stack
#define INITIAL_CAPACITY 10 
#define MAX 100

// Define the stack structure
typedef struct {
    char *items;
    int top;
    int capacity;
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->capacity = INITIAL_CAPACITY;
    s->top = -1;
    s->items = (char *)malloc(s->capacity * sizeof(char));
    if (s->items == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to resize the stack
void resize(Stack *s) {
    s->capacity *= 2;
    s->items = (char *)realloc(s->items, s->capacity * sizeof(char));
    if (s->items == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
}

// Function to push an element to the stack
void push(Stack *s, char value) {
    if (s->top == s->capacity - 1) {
        resize(s);
    }
    s->items[++(s->top)] = value;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Function to get the top element of the stack without removing it
char peek(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->items[s->top];
}

// Function to check precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initialize(&s);
    int i = 0, j = 0;
    char ch;
    
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // Pop '(' from the stack
        } else {
            while (!isEmpty(&s) && precedence(ch) <= precedence(peek(&s))) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    
    postfix[j] = '\0';
    free(s.items);  // Free the allocated memory
}

// Main function to demonstrate infix to postfix conversion
int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
