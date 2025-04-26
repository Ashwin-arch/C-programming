#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount();
void viewAccount();
void depositMoney();
void withdrawMoney();

int main() {
    int choice;
    do {
        printf("\n*** Simple Banking System ***\n");
        printf("1. Create Account\n2. View Account\n3. Deposit Money\n4. Withdraw Money\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createAccount(); break;
            case 2: viewAccount(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}

void createAccount() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "ab");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter Name: ");
    getchar();
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0';
    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("Account created successfully!\n");
}

void viewAccount() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");
    int accNum, found = 0;

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Account Number to View: ");
    scanf("%d", &accNum);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accountNumber == accNum) {
            printf("Account Found!\n");
            printf("Name: %s\nBalance: %.2f\n", acc.name, acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }

    fclose(fp);
}

void depositMoney() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb+");
    int accNum, found = 0;
    float amount;

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Account Number to Deposit: ");
    scanf("%d", &accNum);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            acc.balance += amount;

            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("Amount deposited successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }

    fclose(fp);
}

void withdrawMoney() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb+");
    int accNum, found = 0;
    float amount;

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Account Number to Withdraw: ");
    scanf("%d", &accNum);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > acc.balance) {
                printf("Insufficient balance!\n");
            } else {
                acc.balance -= amount;

                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);

                printf("Amount withdrawn successfully!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }

    fclose(fp);
}
