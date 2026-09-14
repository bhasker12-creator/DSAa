#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int oneQueue[MAX];
int oqFront = 0, oqRear = -1, oqSize = 0;

void oqEnqueue(int value)
{
    oqRear = (oqRear + 1) % MAX;
    oneQueue[oqRear] = value;
    oqSize++;
}

int oqDequeue()
{
    int value = oneQueue[oqFront];

    oqFront = (oqFront + 1) % MAX;
    oqSize--;

    return value;
}

void stackOneQueuePush(int value)
{
    int oldSize, i, temp;

    oldSize = oqSize;

    oqEnqueue(value);

    for (i = 0; i < oldSize; i++)
    {
        temp = oqDequeue();
        oqEnqueue(temp);
    }

    printf("%d pushed into stack.\n", value);
}

void stackOneQueuePop()
{
    int value;

    if (oqSize == 0)
    {
        printf("Stack Underflow!\n");
        return;
    }

    value = oqDequeue();
    printf("%d popped from stack.\n", value);
}

void stackOneQueuePeek()
{
    if (oqSize == 0)
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element = %d\n", oneQueue[oqFront]);
}

void stackOneQueueDisplay()
{
    int i, index;

    if (oqSize == 0)
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements: ");

    index = oqFront;

    for (i = 0; i < oqSize; i++)
    {
        printf("%d ", oneQueue[index]);
        index = (index + 1) % MAX;
    }

    printf("\n");
}

void stackOneQueueMenu()
{
    int choice, value;

    while (1)
    {
        printf("\n===== STACK USING ONE QUEUE =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (oqSize == MAX)
            {
                printf("Stack Overflow!\n");
                break;
            }

            printf("Enter value: ");
            scanf("%d", &value);
            stackOneQueuePush(value);
            break;

        case 2:
            stackOneQueuePop();
            break;

        case 3:
            stackOneQueuePeek();
            break;

        case 4:
            stackOneQueueDisplay();
            break;

        case 5:
            return;

        default:
            printf("Invalid choice!\n");
        }
    }
}

