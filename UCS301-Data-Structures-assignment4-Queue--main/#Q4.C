#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
void firstNonRepeating()
{
    char str[MAX];
    char queue[MAX];
    int frequency[256] = {0};
    int front = 0, rear = -1;
    int i;
    unsigned char ch;

    printf("\n===== FIRST NON-REPEATING CHARACTER =====\n");
    printf("Enter a string: ");
    scanf("%s", str);

    printf("First non-repeating characters: ");

    for (i = 0; str[i] != '\0'; i++)
    {
        ch = (unsigned char)str[i];
        frequency[ch]++;
        queue[++rear] = str[i];

        while (front <= rear &&
               frequency[(unsigned char)queue[front]] > 1)
        {
            front++;
        }

        if (front > rear)
            printf("-1 ");
        else
            printf("%c ", queue[front]);
    }

    printf("\n");
}