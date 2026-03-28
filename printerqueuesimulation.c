#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];  
int front = -1, rear = -1;

void enqueue(char doc[]) {
    if (rear == MAX - 1) {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1) front = 0;

    rear++;
    strcpy(queue[rear], doc);

    printf("Document added: %s\n", doc);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("No documents to print\n");
        return;
    }

    printf("Printing document: %s\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("No pending documents\n");
        return;
    }

    printf("Pending documents:\n");
    for (int i = front; i <= rear; i++) {
        printf("%s\n", queue[i]);
    }
}

int main() {
    int choice;
    char doc[50];

    while (1) {
        printf("\n1. Add Document\n2. Print Document\n3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter document name: ");
                scanf("%s", doc);
                enqueue(doc);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}