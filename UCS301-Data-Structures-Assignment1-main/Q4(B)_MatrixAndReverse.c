#include <stdio.h>

#define R1 2
#define C1 3
#define R2 3
#define C2 2

void multiplyMatrices(int first[R1][C1], int second[R2][C2], int result[R1][C2]) {
    // Initialize elements of result matrix to 0
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;
        }
    }

    // Multiply matrices
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < C1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

int main() {
    int A[R1][C1] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int B[R2][C2] = {
        {7, 8},
        {9, 1},
        {2, 3}
    };

    int C[R1][C2]; // To store the product

    multiplyMatrices(A, B, C);

    printf("Resultant Matrix after multiplication:\n");
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
