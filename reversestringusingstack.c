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
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    // Push all characters into stack
    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    // Pop characters to reverse string
    printf("Reversed string: ");
    for (i = 0; i < len; i++) {
        printf("%c", pop());
    }

    return 0;
}