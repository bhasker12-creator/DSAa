#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void createArray(int arr[], int *size);
void displayArray(const int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void linearSearch(const int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    while (1) {
        printf("\n--- ARRAY OPERATIONS MENU ---");
        printf("\n1. CREATE");
        printf("\n2. DISPLAY");
        printf("\n3. INSERT");
        printf("\n4. DELETE");
        printf("\n5. LINEAR SEARCH");
        printf("\n6. EXIT");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                linearSearch(arr, size);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. CREATE: Initialize or overwrite the array
void createArray(int arr[], int *size) {
    printf("Enter the number of elements (Max %d): ", MAX_SIZE);
    scanf("%d", size);

    if (*size < 0 || *size > MAX_SIZE) {
        printf("Invalid size! Setting array size to 0.\n");
        *size = 0;
        return;
    }

    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully!\n");
}

// 2. DISPLAY: Print all existing array elements
void displayArray(const int arr[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Array elements: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// 3. INSERT: Add an element at a user-defined index
void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Error: Array Overflow. Cannot insert more elements.\n");
        return;
    }

    int element, position;
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter index position (0 to %d): ", *size);
    scanf("%d", &position);

    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements right to create space
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++; 
    printf("Element inserted successfully!\n");
}

// 4. DELETE: Remove an element from a specific index
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Error: Array Underflow. Nothing to delete.\n");
        return;
    }

    int position;
    printf("Enter index position to delete (0 to %d): ", *size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements left to close the gap
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; 
    printf("Element deleted successfully!\n");
}

// 5. LINEAR SEARCH: Scan sequentially to find a target value
void linearSearch(const int arr[], int size) {
    if (size == 0) {
        printf("Array is empty! Nothing to search.\n");
        return;
    }

    int target;
    int foundIndex = -1; // -1 represents "Not Found"

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Sequential loop checking every index
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            foundIndex = i;
            break; // Stop at first match found
        }
    }

    if (foundIndex != -1) {
        printf("Success! Element %d found at index position: %d\n", target, foundIndex);
    } else {
        printf("Element %d does not exist in the array.\n", target);
    }
}