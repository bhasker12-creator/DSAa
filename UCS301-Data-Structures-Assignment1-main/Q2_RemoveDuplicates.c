#include <stdio.h>

int main() {
    int arr[100];
    int size;
    int i, j, k;

    // Step 1: Get array size from user
    printf("Enter number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // Step 2: Read array elements from user
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Core logic to remove duplicate elements
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            // Check if current element matches any subsequent element
            if (arr[i] == arr[j]) {
                // Shift all subsequent elements one position left
                for (k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                
                // Reduce the size of the array
                size--;
                
                // Decrement j to ensure the newly shifted element is also checked
                j--; 
            }
        }
    }

    // Step 4: Display the modified unique array
    printf("\nArray elements after removing duplicates:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
