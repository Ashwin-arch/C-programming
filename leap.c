#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1; // Leap year
            } else {
                return 0; // Not a leap year
            }
        } else {
            return 1; // Leap year
        }
    } else {
        return 0; // Not a leap year
    }
}

int main() {
    int startYear, endYear;

    // Input the range of years
    printf("Enter the start year: ");
    scanf("%d", &startYear);
    printf("Enter the end year: ");
    scanf("%d", &endYear);

    printf("Leap years between %d and %d are:\n", startYear, endYear);

    for (int year = startYear; year <= endYear; year++) {
        if (isLeapYear(year)) {
            printf("%d\n", year);
        }
    }

    return 0;
}
