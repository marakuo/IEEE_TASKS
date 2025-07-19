
// header files
#include <stdio.h>
#include <string.h>
#include <stdbool.h> // true & false

// related to the card
typedef struct {
    char holder_name[20];
    char PAN[17]; // 16 number + null terminator (from the user )
    int EXP_year;
    int EXP_month;
} Card;

// related to the account
typedef struct {
    char PAN[17]; // 16 number + null terminator (related to the data_base of the account )
    double balance;
    double max_payment;
    bool isvalid;
} Account;



// function to get card_holder data
void card_data(Card* user_card) {
    printf("Enter the holder name: ");
    scanf("%19s", user_card->holder_name); // limit input to prevent buffer overflow

    printf("Enter the PAN (16 digits): ");
    scanf("%16s", user_card->PAN); // limit to 16 characters

    printf("Enter the expiration year (YYYY): ");
    scanf("%d", &user_card->EXP_year);

    printf("Enter the expiration month (MM): ");
    scanf("%d", &user_card->EXP_month);
}

// function to check if card is expired
bool is_valid_account(Card* user_card) {
    int current_month, current_year;
    printf("Enter the current month (MM) and current year (YYYY): ");
    scanf("%d %d", &current_month, &current_year);

    // check expiration
    if (user_card->EXP_year < current_year) return true;
    if (user_card->EXP_year == current_year && user_card->EXP_month < current_month) return true;
    return false;
}

// function to update account balance
void updating_balance(Account* account, double amount) {
    account->balance -= amount; // remove the amount taken
    printf("Balance updated successfully. New balance: %.2f\n", account->balance);
}

// function to validate and process transaction
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
    // if all check pass then update the balance (removing the amount)
    updating_balance(account, amount);
    return true;
}

// function to display transaction result
void displayTransactionResult(bool isApproved) {
    if (isApproved) {
        printf("Transaction Approved\n");
    } else {
        printf("Transaction Declined\n");
    }
}

// function to display account information
void display_account_info(Account* account) {
    printf("\nAccount Information:\n");
    printf("PAN: %s\n", account->PAN);
    printf("Balance: %.2f\n", account->balance);
    printf("Max Payment Limit: %.2f\n", account->max_payment);
    printf("Account Status: %s\n", account->isvalid ? "Valid" : "Invalid");
}
// function to display the  receipts
void generate_receipt(Card* card, Account* account, double amount, bool isApproved) {
    printf("\n========== TRANSACTION RECEIPT ==========\n");
    printf("Card Holder: %s\n", card->holder_name);
    printf("PAN: %s\n", card->PAN);
    printf("Transaction Amount: $%.2f\n", amount);
    printf("----------------------------------------\n");
    printf("Previous Balance: $%.2f\n", account->balance + amount); // add back the amount to show previous balance
    printf("New Balance: $%.2f\n", account->balance);
    printf("Max Payment Limit: $%.2f\n", account->max_payment);
    printf("----------------------------------------\n");
    printf("Status: %s\n", isApproved ? "APPROVED" : "DECLINED");
    printf("Date: %s", __DATE__);  // macro to display date
    printf("\n========== THANK YOU ==========\n");
}




int main() {
    Card user_card;

    // Bank database (can be changed)
    Account accounts[] = {
        {"1234567890123456", 1000.0, 2000.0, true},   // valid account with enough balance
        {"9876543210987654", 500.0, 1000.0, true},    // valid account with limited balance
        {"1111222233334444", 0.0, 500.0, false},      // invalid account
        {"6666555544443333", 50.0, 50.0, true},       // balance = max payment
        {"9999888877776666", 10000.0, 15000.0, true}, // large balance account
        {"5555666677778888", 200.0, 300.0, true}      // additional test account
    };

    // get card details
    card_data(&user_card);

    int num_of_accounts = sizeof(accounts) / sizeof(accounts[0]); // calculate the num of accounts

    // check if the card is expired
    if (is_valid_account(&user_card)) {
        printf("Declined: Expired card\n");
        return 0;
    }

    // find the account using PAN
    Account *userAccount = NULL; // to be checked if the account is not found , safety
    for (int i = 0; i < num_of_accounts; i++) {
        if (strcmp(accounts[i].PAN, user_card.PAN) == 0) {
            userAccount = &accounts[i];
            break;
        }
    }

    // check if account was found
    if (userAccount == NULL) {
        printf("Declined: Account not found\n");
        return 0;
    }

    // display account information
    display_account_info(userAccount);

    // get transaction amount
    double amount;
    printf("\nEnter transaction amount: ");
    scanf("%lf", &amount);

    // process the transaction
    bool isApproved = transaction_validation(userAccount, amount);
    displayTransactionResult(isApproved);


    // generate receipt
    generate_receipt(&user_card, userAccount, amount, isApproved);


    return 0;
}
