#include <stdio.h>
#include <ctype.h>  // for isalpha(), isdigit()
#include <string.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push element onto stack
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = c;
    }
}

// Pop element from stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0'; // Stack empty
}

// Peek top element of stack
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

// Function to return precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

// Check if character is operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    init(&s);
    int k = 0; // Index for postfix

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If operand (letter or digit), add to postfix
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If '(' push to stack
        else if (c == '(') {
            push(&s, c);
        }
        // If ')' pop and output until '('
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // Remove '('
        }
        // If operator
        else if (isOperator(c)) {
            whil

