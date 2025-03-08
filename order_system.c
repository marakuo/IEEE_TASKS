#include <stdio.h>

// Function to calculate shipping cost
float calculateShipping(int overnight, float price) {
    float shippingCost = (price < 10) ? 2 : 3;
    if (overnight) {
        shippingCost += 5;
    }
    return shippingCost;
}

// Function to apply discount if more than 5 items
float discount(float subtotal, int itemCount) {
    if (itemCount > 5) {
        return subtotal * 0.8; // Apply 20% discount
    }
    return subtotal;
}


int main() {
    char items[100][50]; 
    float prices[100];   
    int itemCount = 0;   
    int overnight;      
    char choice;
    float shipping = 0, total = 0, subtotal = 0;

    printf("\nWelcome to the Online Order System!\n");

    // Collect item data
    do {
        printf("\nEnter item name: ");
        scanf(" %[^\n]", items[itemCount]); // Allows more than 1 word
        printf("Enter item price: $");
        scanf("%f", &prices[itemCount]);

        subtotal += prices[itemCount]; // Add price to subtotal
        itemCount++;

        printf("Do you want to add another item? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Check minimum order requirement
    if (itemCount < 2) {
        printf("\nError: You must order at least 2 items.\n");
        return 1;
    }

    // Ask for overnight shipping
    printf("\nDo you need overnight shipping? (1 = Yes, 0 = No): ");
    scanf("%d", &overnight);

    // Calculate total shipping cost
    for (int i = 0; i < itemCount; i++) {
        shipping += calculateShipping(overnight, prices[i]);
    }

    // Apply discount if eligible
    subtotal = discount(subtotal, itemCount);
    total = subtotal + shipping;


    // Display receipt
    printf("\n----------------------------------\n");
    printf("          ORDER Data         \n");
    printf("----------------------------------\n");
    printf("Number of Items: %d\n", itemCount);
    printf("Subtotal:       $%.2f\n", subtotal);
    printf("Shipping Cost:  $%.2f\n", shipping);
    printf("Total Cost:     $%.2f\n", total);
    printf("----------------------------------\n");
    printf(" Thank you for shopping with us!\n");
    printf("----------------------------------\n");

    return 0;
}
