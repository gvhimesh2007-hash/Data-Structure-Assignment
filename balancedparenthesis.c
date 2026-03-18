#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Pop function
char pop() {
    if (top == -1) {
        return '\0';  // Indicates empty stack
    } else {
        return stack[top--];
    }
}

// Function to check balance
int isBalanced(char exp[]) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {

        // If opening bracket
        if (exp[i] == '(') {
            push(exp[i]);
        }

        // If closing bracket
        else if (exp[i] == ')') {
            if (top == -1) {
                return 0; // Not balanced
            }
            pop();
        }
    }

    // If stack is empty → balanced
    return (top == -1);
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (isBalanced(exp)) {
        printf("Balanced Expression\n");
    } else {
        printf("Not Balanced Expression\n");
    }

    return 0;
}