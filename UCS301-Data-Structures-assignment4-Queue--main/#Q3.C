
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
void interleaveQueue()
{
    int queue[MAX];
    int result[MAX];
    int n, i, half, k = 0;

    printf("\n===== INTERLEAVE QUEUE =====\n");
    printf("Enter number of elements (even): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX || n % 2 != 0)
    {
        printf("Please enter a positive even number <= %d.\n", MAX);
        return;
    }

    printf("Enter queue elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    half = n / 2;

    for (i = 0; i < half; i++)
    {
        result[k++] = queue[i];
        result[k++] = queue[i + half];
    }

    printf("Interleaved Queue: ");
    for (i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");
}
