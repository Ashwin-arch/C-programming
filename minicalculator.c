#include <stdio.h>

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int main() {
    int choice;
    float num1, num2, result;

    do {
        printf("\n*** Mini Calculator ***\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
        }

        switch (choice) {
            case 1: result = add(num1, num2); printf("Result: %.2f\n", result); break;
            case 2: result = subtract(num1, num2); printf("Result: %.2f\n", result); break;
            case 3: result = multiply(num1, num2); printf("Result: %.2f\n", result); break;
            case 4: result = divide(num1, num2); printf("Result: %.2f\n", result); break;
            case 5: printf("Exiting calculator...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
