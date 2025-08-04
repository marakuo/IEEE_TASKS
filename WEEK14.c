//Implement Stack Code
#include <stdio.h>

int stack[100];
int top = -1;
int max_size = 0;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == max_size - 1);
}

void push(int data) {
    if (isFull()) {
        printf("Stack is full => overflow\n");
    } else {
        top++;
        stack[top] = data;
        printf("Pushed data => %d\n", data);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty => underflow\n");
        return -1;
    } else {
        int popped_value = stack[top];
        top--;
        printf("Popped value is %d\n", popped_value);
        return popped_value;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display_stack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    printf("Enter max stack size (1–100): ");
    scanf("%d", &max_size);
    if (max_size > 100 || max_size <= 0) {
        printf("Invalid size. Must be between 1 and 100.\n");
        return 1;
    }

    int choice, value;
    do {
        printf("\nChoose operation:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display_stack();
                break;
            case 4:
                printf("Top element is: %d\n", peek());
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}


///______________________________________________________________________///



