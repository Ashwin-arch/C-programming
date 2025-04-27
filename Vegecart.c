#include <stdio.h>

int main() {
    int choice, quantity;
    float total = 0;
    do {
        printf("\n*** Vegetable Cart ***\n");
        printf("1. Tomato (₹20/kg)\n2. Potato (₹25/kg)\n3. Onion (₹30/kg)\n4. Carrot (₹40/kg)\n5. Checkout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter quantity (kg): ");
                scanf("%d", &quantity);
                total += quantity * 20;
                break;
            case 2:
                printf("Enter quantity (kg): ");
                scanf("%d", &quantity);
                total += quantity * 25;
                break;
            case 3:
                printf("Enter quantity (kg): ");
                scanf("%d", &quantity);
                total += quantity * 30;
                break;
            case 4:
                printf("Enter quantity (kg): ");
                scanf("%d", &quantity);
                total += quantity * 40;
                break;
            case 5:
                printf("Checking out...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    printf("\nTotal Amount: ₹%.2f\n", total);
    printf("Thank you for shopping!\n");

    return 0;
}
