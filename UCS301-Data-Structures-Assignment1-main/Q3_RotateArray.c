#include <stdio.h>

// Helper function to reverse a section of the array between start and end indices
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to left-rotate the array by K positions
void leftRotate(int arr[], int n, int k) {
    k = k % n; // Handle cases where K >= N
    if (k == 0) return;

    reverse(arr, 0, k - 1);     // Reverse first K elements
    reverse(arr, k, n - 1);     // Reverse remaining elements
    reverse(arr, 0, n - 1);     // Reverse the entire array
}

// Function to right-rotate the array by K positions
void rightRotate(int arr[], int n, int k) {
    k = k % n; // Handle cases where K >= N
    if (k == 0) return;

    reverse(arr, n - k, n - 1); // Reverse last K elements
    reverse(arr, 0, n - k - 1); // Reverse remaining elements
    reverse(arr, 0, n - 1);     // Reverse the entire array
}

// Helper function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int k = 3;

    printf("Original Array: ");
    printArray(arr1, n);

    // Test Left Rotation
    leftRotate(arr1, n, k);
    printf("Left Rotated by %d: ", k);
    printArray(arr1, n);

    // Resetting array for Right Rotation test
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    
    // Test Right Rotation
    rightRotate(arr2, n, k);
    printf("Right Rotated by %d: ", k);
    printArray(arr2, n);

    return 0;
}
