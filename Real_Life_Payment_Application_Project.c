
// header files
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// =====================
// CARD & ACCOUNT STRUCTS
// =====================
typedef struct {
    char holder_name[20];
    char PAN[17]; // 16 digits + null terminator
    int EXP_year;
    int EXP_month;
} Card;

typedef struct {
    char PAN[17];
    double balance;
    double max_payment;
    bool isvalid;
} Account;

// =====================
// TRANSACTION STRUCT
// =====================
typedef struct {
    char PAN[17];
    double amount;
    bool status; // Approved or Declined
} Transaction;

// =====================
// STACK WITH ARRAY
// =====================
#define MAX_TRANSACTIONS 100
typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int top;
} TransactionStack;

void initStack(TransactionStack *s) { s->top = -1; }
bool isEmpty(TransactionStack *s) { return s->top == -1; }
bool isFull(TransactionStack *s) { return s->top == MAX_TRANSACTIONS - 1; }

bool push(TransactionStack *s, Transaction t) {
    if (isFull(s)) {
        printf("Transaction stack is full!\n");
        return false;
    }
    s->transactions[++(s->top)] = t;
    return true;
}

bool pop(TransactionStack *s, Transaction *t) {
    if (isEmpty(s)) {
        printf("No transactions to undo!\n");
        return false;
    }
    *t = s->transactions[(s->top)--];
    return true;
}

void displayStack(TransactionStack *s) {
    printf("\n=== Transaction History (Array Stack) ===\n");
    if (isEmpty(s)) {
        printf("No transactions recorded.\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("PAN: %s | Amount: %.2f | Status: %s\n",
               s->transactions[i].PAN,
               s->transactions[i].amount,
               s->transactions[i].status ? "Approved" : "Declined");
    }
}

// =====================
// STACK WITH LINKED LIST
// =====================
typedef struct TransactionNode {
    Transaction data;
    struct TransactionNode *next;
} TransactionNode;

typedef struct {
    TransactionNode *top;
} TransactionLinkedStack;

void initLinkedStack(TransactionLinkedStack *s) { s->top = NULL; }
bool isLinkedEmpty(TransactionLinkedStack *s) { return s->top == NULL; }

void pushLinked(TransactionLinkedStack *s, Transaction t) {
    TransactionNode *newNode = (TransactionNode*)malloc(sizeof(TransactionNode));
    newNode->data = t;
    newNode->next = s->top;
    s->top = newNode;
}

bool popLinked(TransactionLinkedStack *s, Transaction *t) {
    if (isLinkedEmpty(s)) {
        printf("No transactions to undo!\n");
        return false;
    }
    TransactionNode *temp = s->top;
    *t = temp->data;
    s->top = temp->next;
    free(temp);
    return true;
}

void displayLinkedStack(TransactionLinkedStack *s) {
    printf("\n=== Transaction History (Linked List Stack) ===\n");
    if (isLinkedEmpty(s)) {
        printf("No transactions recorded.\n");
        return;
    }
    TransactionNode *curr = s->top;
    while (curr != NULL) {
        printf("PAN: %s | Amount: %.2f | Status: %s\n",
               curr->data.PAN,
               curr->data.amount,
               curr->data.status ? "Approved" : "Declined");
        curr = curr->next;
    }
}

// =====================
// HELPER FUNCTIONS
// =====================
void card_data(Card* user_card) {
    printf("Enter the holder name: ");
    scanf("%19s", user_card->holder_name);

    printf("Enter the PAN (16 digits): ");
    scanf("%16s", user_card->PAN);

    printf("Enter the expiration year (YYYY): ");
    scanf("%d", &user_card->EXP_year);

    printf("Enter the expiration month (MM): ");
    scanf("%d", &user_card->EXP_month);
}

bool is_valid_account(Card* user_card) {
    int current_month, current_year;
    printf("Enter the current month (MM) and current year (YYYY): ");
    scanf("%d %d", &current_month, &current_year);

    if (user_card->EXP_year < current_year) return true;
    if (user_card->EXP_year == current_year && user_card->EXP_month < current_month) return true;
    return false;
}

void updating_balance(Account* account, double amount) {
    account->balance -= amount;
    printf("Balance updated successfully. New balance: %.2f\n", account->balance);
}

bool transaction_validation(Account* account, double amount) {
    if (!account->isvalid) {
        printf("Invalid transaction process => account is not valid\n");
        return false;
    }
    if (amount > account->balance) {
        printf("Invalid transaction process => amount exceeds the balance\n");
        return false;
    }
    if (amount > account->max_payment) {
        printf("Invalid transaction process => amount exceeds the max payment\n");
        return false;
    }
    updating_balance(account, amount);
    return true;
}

void displayTransactionResult(bool isApproved) {
    if (isApproved) printf("Transaction Approved\n");
    else printf("Transaction Declined\n");
}

void display_account_info(Account* account) {
    printf("\nAccount Information:\n");
    printf("PAN: %s\n", account->PAN);
    printf("Balance: %.2f\n", account->balance);
    printf("Max Payment Limit: %.2f\n", account->max_payment);
    printf("Account Status: %s\n", account->isvalid ? "Valid" : "Invalid");
}

void generate_receipt(Card* card, Account* account, double amount, bool isApproved) {
    printf("\n========== TRANSACTION RECEIPT ==========\n");
    printf("Card Holder: %s\n", card->holder_name);
    printf("PAN: %s\n", card->PAN);
    printf("Transaction Amount: $%.2f\n", amount);
    printf("----------------------------------------\n");
    printf("Previous Balance: $%.2f\n", account->balance + amount);
    printf("New Balance: $%.2f\n", account->balance);
    printf("Max Payment Limit: $%.2f\n", account->max_payment);
    printf("----------------------------------------\n");
    printf("Status: %s\n", isApproved ? "APPROVED" : "DECLINED");
    printf("Date: %s\n", __DATE__);
    printf("========================================\n");
}

// =====================
// MAIN PROGRAM
// =====================
int main() {
    Card user_card;

    Account accounts[] = {
        {"1234567890123456", 1000.0, 2000.0, true},
        {"9876543210987654", 500.0, 1000.0, true},
        {"1111222233334444", 0.0, 500.0, false},
        {"6666555544443333", 50.0, 50.0, true},
        {"9999888877776666", 10000.0, 15000.0, true},
        {"5555666677778888", 200.0, 300.0, true}
    };
    int num_of_accounts = sizeof(accounts) / sizeof(accounts[0]);

    // Init both stacks
    TransactionStack arrayHistory;
    initStack(&arrayHistory);
    TransactionLinkedStack linkedHistory;
    initLinkedStack(&linkedHistory);

    // Input card
    card_data(&user_card);

    // Expiration check
    if (is_valid_account(&user_card)) {
        printf("Declined: Expired card\n");
        return 0;
    }

    // Find account
    Account *userAccount = NULL;
    for (int i = 0; i < num_of_accounts; i++) {
        if (strcmp(accounts[i].PAN, user_card.PAN) == 0) {
            userAccount = &accounts[i];
            break;
        }
    }
    if (userAccount == NULL) {
        printf("Declined: Account not found\n");
        return 0;
    }

    // Show account info
    display_account_info(userAccount);

    // Transaction input
    double amount;
    printf("\nEnter transaction amount: ");
    scanf("%lf", &amount);

    // Validate
    bool isApproved = transaction_validation(userAccount, amount);
    displayTransactionResult(isApproved);
    generate_receipt(&user_card, userAccount, amount, isApproved);

    // Save transaction
    Transaction t;
    strcpy(t.PAN, user_card.PAN);
    t.amount = amount;
    t.status = isApproved;

    push(&arrayHistory, t);
    pushLinked(&linkedHistory, t);

    // Show history
    displayStack(&arrayHistory);
    displayLinkedStack(&linkedHistory);

    // Undo option
    char choice;
    printf("\nDo you want to undo last transaction? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y') {
        Transaction undone;
        if (pop(&arrayHistory, &undone)) {
            userAccount->balance += undone.amount;
            printf("ArrayStack Undo: PAN=%s, Amount=%.2f\n", undone.PAN, undone.amount);
        }
        if (popLinked(&linkedHistory, &undone)) {
            userAccount->balance += undone.amount;
            printf("LinkedStack Undo: PAN=%s, Amount=%.2f\n", undone.PAN, undone.amount);
        }
    }

    // Final info
    display_account_info(userAccount);

    return 0;
}

//==============//
// OUTPUT //
//==============//
C:\Users\workstation\CLionProjects\untitled6\cmake-build-debug\untitled6.exe
Enter the holder name:malak

Enter the PAN (16 digits):1234567891234567

Enter the expiration year (YYYY):2027

Enter the expiration month (MM):1

Enter the current month (MM) and current year (YYYY):1 2025

Declined: Account not found

Process finished with exit code 0


    ////////////////////////////////
    C:\Users\workstation\CLionProjects\untitled6\cmake-build-debug\untitled6.exe
Enter the holder name:HEN

Enter the PAN (16 digits):1234567890123456

Enter the expiration year (YYYY):2020

Enter the expiration month (MM):2

Enter the current month (MM) and current year (YYYY):2 2019


Account Information:
PAN: 1234567890123456
Balance: 1000.00
Max Payment Limit: 2000.00
Account Status: Valid

Enter transaction amount:1000

Balance updated successfully. New balance: 0.00
Transaction Approved

========== TRANSACTION RECEIPT ==========
Card Holder: HEN
PAN: 1234567890123456
Transaction Amount: $1000.00
----------------------------------------
Previous Balance: $1000.00
New Balance: $0.00
Max Payment Limit: $2000.00
----------------------------------------
Status: APPROVED
Date: Aug 24 2025
========================================

=== Transaction History (Array Stack) ===
PAN: 1234567890123456 | Amount: 1000.00 | Status: Approved

=== Transaction History (Linked List Stack) ===
PAN: 1234567890123456 | Amount: 1000.00 | Status: Approved

Do you want to undo last transaction? (y/n):



