/*
1. Recruit Warriors:
   - Add a new warrior to the front, back, or any spot in your team lineup.
   - Every warrior has a power level (integer).

2.  Lead the Team:
   - Sometimes warriors fall. Remove the first, last, or any warrior in the line.

3.  View Your Army:

4.  Team Intel:
   - Count how many warriors remain.
   - Search for a warrior by their power level.

5.  Play It Like a Game:
   - Choose from the menu (1-10) to command your squad.

==================================================================
*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each warrior (node)
struct Warrior {
    int power;
    struct Warrior* next;
};

struct Warrior* head = NULL;

// Function to create a new warrior
struct Warrior* createWarrior(int power) {
    struct Warrior* newWarrior = (struct Warrior*)malloc(sizeof(struct Warrior));
    newWarrior->power = power;
    newWarrior->next = NULL;
    return newWarrior;
}

// Recruit warrior at front
void recruitFront(int power) {
    struct Warrior* newWarrior = createWarrior(power);
    newWarrior->next = head;
    head = newWarrior;
    printf("\n Warrior with power %d joins from the front!\n", power);
}

// Recruit warrior at end
void recruitEnd(int power) {
    struct Warrior* newWarrior = createWarrior(power);
    if (head == NULL) {
        head = newWarrior;
    } else {
        struct Warrior* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newWarrior;
    }
    printf("\n Warrior with power %d joins from the back!\n", power);
}

// Recruit warrior at a specific position
void recruitAtPosition(int power, int pos) {
    if (pos == 1) {
        recruitFront(power);
        return;
    }
    struct Warrior* newWarrior = createWarrior(power);
    struct Warrior* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\n Position too far! Adding at the end instead.\n");
        recruitEnd(power);
        return;
    }
    newWarrior->next = temp->next;
    temp->next = newWarrior;
    printf("\n Warrior with power %d joins at position %d!\n", power, pos);
}

// Remove warrior from front
void removeFront() {
    if (head == NULL) {
        printf("\n No warriors left to remove!\n");
        return;
    }
    struct Warrior* temp = head;
    head = head->next;
    printf("\n Warrior with power %d falls in battle (front).\n", temp->power);
    free(temp);
}

// Remove warrior from end
void removeEnd() {
    if (head == NULL) {
        printf("\n No warriors left to remove!\n");
        return;
    }
    if (head->next == NULL) {
        printf("\n Warrior with power %d falls in battle (last one).\n", head->power);
        free(head);
        head = NULL;
        return;
    }
    struct Warrior* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    printf("\n Warrior with power %d falls in battle (end).\n", temp->next->power);
    free(temp->next);
    temp->next = NULL;
}

// Remove warrior at position
void removeAtPosition(int pos) {
    if (head == NULL) {
        printf("\n No warriors to remove!\n");
        return;
    }
    if (pos == 1) {
        removeFront();
        return;
    }
    struct Warrior* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("\n Invalid position!\n");
        return;
    }
    struct Warrior* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("\n Warrior with power %d has fallen from position %d.\n", toDelete->power, pos);
    free(toDelete);
}

// Show the warrior lineup
void displayWarriors() {
    if (head == NULL) {
        printf("\n️ Your squad is empty...\n");
        return;
    }
    struct Warrior* temp = head;
    printf("\n Team Lineup: ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->power);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count warriors
void countWarriors() {
    int count = 0;
    struct Warrior* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("\n You have %d warrior(s) standing strong!\n", count);
}

// Search for a warrior
void searchWarrior(int power) {
    struct Warrior* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->power == power) {
            printf("\n Warrior with power %d found at position %d!\n", power, pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("\n Warrior with power %d is not in the lineup.\n", power);
}

int main() {
    int choice, power, pos;

    do {
        printf("\n\n=============================");
        printf("\n  WARRIOR COMMAND MENU  ");
        printf("\n=============================");
        printf("\n1. Recruit at Front");
        printf("\n2. Recruit at End");
        printf("\n3. Recruit at Position");
        printf("\n4. Remove from Front");
        printf("\n5. Remove from End");
        printf("\n6. Remove at Position");
        printf("\n7. View Team");
        printf("\n8. Count Warriors");
        printf("\n9. Search Warrior");
        printf("\n10. Exit Game");
        printf("\nChoose your command: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter power of warrior: ");
                scanf("%d", &power);
                recruitFront(power);
                break;
            case 2:
                printf("Enter power of warrior: ");
                scanf("%d", &power);
                recruitEnd(power);
                break;
            case 3:
                printf("Enter power of warrior: ");
                scanf("%d", &power);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                recruitAtPosition(power, pos);
                break;
            case 4:
                removeFront();
                break;
            case 5:
                removeEnd();
                break;
            case 6:
                printf("Enter position to remove: ");
                scanf("%d", &pos);
                removeAtPosition(pos);
                break;
            case 7:
                displayWarriors();
                break;
            case 8:
                countWarriors();
                break;
            case 9:
                printf("Enter warrior power to search: ");
                scanf("%d", &power);
                searchWarrior(power);
                break;
            case 10:
                printf("\n Retreating from the battlefield... Until next time, Commander!\n");
                break;
            default:
                printf("\n Invalid choice. Choose wisely, Commander.\n");
        }
    } while (choice != 10);

    return 0;
}
