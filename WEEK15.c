// Implement Queue Code
#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int front = -1, rear = -1;

// enqueue
void enqueue(int x) {
    if (rear == N - 1) {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        rear++;
        queue[rear] = x;
    }
}

// dequeue
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow condition\n");
    }
    else if (front == rear) {
        printf("Dequeued: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
    }
}

// display
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// peek
void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Front element: %d\n", queue[front]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

///////////////////////////////////////
//Circular Queue Implementation 
#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int front = -1, rear = -1;

// enqueue circular case
void enqueue(int x) {
    if ((rear + 1) % N == front) {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

// dequeue circular
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow condition\n");
    }
    else if (front == rear) {
        printf("Dequeued: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

// display circular
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        int i = front;
        printf("Circular Queue elements: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]); // print last element
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

