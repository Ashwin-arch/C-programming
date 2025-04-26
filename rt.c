#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in the array
int findMax(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to check for duplicates using the pigeonhole principle
int hasDuplicates(int arr[], int size) {
    int max = findMax(arr, size);
    int *holes = (int *)calloc(max + 1, sizeof(int));

    for(int i = 0; i < size; i++) {
        if(holes[arr[i]] != 0) {
            free(holes);
            return 1; // Duplicate found
        }
        holes[arr[i]]++;
    }

    free(holes);
    return 0; // No duplicates
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    if(hasDuplicates(arr, size)) {
        printf("Array has duplicates.\n");
    } else {
        printf("Array has no duplicates.\n");
    }

    return 0;
}
