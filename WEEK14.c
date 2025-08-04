//Implement Stack Code  (USING ARRAYS)
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
//Implement Stack Code  (USING LINKED LISTS)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
     struct node *link;

};
struct node *top = NULL;


int  isEmpty() {
    return (top == NULL);

}
// push function
void push(int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->link = top;
    top = new_node;

}
// function to display from LIFO
void display() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = top;
    if (isEmpty()) {
        printf("Stack is empty\n");
    }
    else {
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }


}
// peek function
void peek() {
    if (isEmpty()) {
        printf("The Stack is empty");
    }else {
        printf("The the top element is %d", top->data);
    }
}

// pop function
void pop() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = top;
    if (isEmpty()) {
        printf("Stack is empty");
    }
    else {
        printf("The top element is %d", top->data);
        top = top->link;
        free(temp);
    }
}


int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
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
                peek();
            break;
            case 4:
                display();
            break;
            case 5:
                printf("Exiting program.\n");
            exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


//________________________________________________//




