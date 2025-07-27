// linked lists task 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
// function to print the linked list elements
void printlist(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;

    }
    printf("\n");
}
// insertion before the head
struct node * add_before_head (struct node *head, int data) {
    struct node  *temp;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->link = head;
    return temp;


}


int main() {
    // Creating 5 nodes
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* next = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* forth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));

    // Linking data
    head->data = 1;
    head->link = next;

    next->data = 2;
    next->link = third;

    third->data = 3;
    third->link = forth;

    forth->data = 4;
    forth->link = fifth;

    fifth->data = 5;
    fifth->link = NULL;

    // Calling the count function
    // before
    printf("before insertion\n");
    printlist(head);
    printf("after insertion\n");
    head = add_before_head(head, 10);
    printlist(head);

    return 0;
}
