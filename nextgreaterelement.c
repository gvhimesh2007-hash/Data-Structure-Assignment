#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
int pop() {
    return stack[top--];
}

// Check empty
int isEmpty() {
    return top == -1;
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5;
    int i, next;

    // Push first element
    push(arr[0]);

    for (i = 1; i < n; i++) {
        next = arr[i];

        // Compare with stack elements
        while (!isEmpty() && next > stack[top]) {
            printf("%d → %d\n", pop(), next);
        }

        push(next);
    }

    // Remaining elements
    while (!isEmpty()) {
        printf("%d → -1\n", pop());
    }

    return 0;
}