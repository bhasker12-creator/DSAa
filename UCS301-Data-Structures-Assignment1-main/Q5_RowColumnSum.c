#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;
    int i, j, sum;

    // Ask user for the dimensions of the matrix
    printf("Enter the number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    // Guard against dimensions exceeding bounds
    if (rows > MAX_ROWS || cols > MAX_COLS || rows <= 0 || cols <= 0) {
        printf("Invalid dimensions entered.\n");
        return 1;
    }

    // Input matrix elements from user
    printf("\nEnter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate and print the sum of every row
    printf("\n--- Row Sums ---\n");
    for (i = 0; i < rows; i++) {
        sum = 0; // Reset sum for each new row
        for (j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        printf("Sum of Row %d = %d\n", i + 1, sum);
    }

    // Calculate and print the sum of every column
    printf("\n--- Column Sums ---\n");
    for (j = 0; j < cols; j++) {
        sum = 0; // Reset sum for each new column
        for (i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        printf("Sum of Column %d = %d\n", j + 1, sum);
    }

    return 0;
}
