
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int circularQueue[MAX];
int cqFront = -1, cqRear = -1;

int cqIsEmpty()
{
    return cqFront == -1;
}

int cqIsFull()
{
    return (cqRear + 1) % MAX == cqFront;
}

void cqEnqueue(int value)
{
    if (cqIsFull())
    {
        printf("Circular Queue Overflow!\n");
        return;
    }

    if (cqIsEmpty())
        cqFront = cqRear = 0;
    else
        cqRear = (cqRear + 1) % MAX;

    circularQueue[cqRear] = value;
    printf("%d inserted into circular queue.\n", value);
}

void cqDequeue()
{
    if (cqIsEmpty())
    {
        printf("Circular Queue Underflow!\n");
        return;
    }

    printf("%d deleted from circular queue.\n", circularQueue[cqFront]);

    if (cqFront == cqRear)
        cqFront = cqRear = -1;
    else
        cqFront = (cqFront + 1) % MAX;
}

void cqPeek()
{
    if (cqIsEmpty())
        printf("Queue is empty!\n");
    else
        printf("Front element = %d\n", circularQueue[cqFront]);
}

void cqDisplay()
{
    int i;

    if (cqIsEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Circular Queue elements: ");

    i = cqFront;

    while (1)
    {
        printf("%d ", circularQueue[i]);

        if (i == cqRear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

void circularQueueMenu()
{
    int choice, value;

    while (1)
    {
        printf("\n===== CIRCULAR QUEUE =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. isEmpty\n");
        printf("4. isFull\n");
        printf("5. Display\n");
        printf("6. Peek\n");
        printf("7. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            cqEnqueue(value);
            break;

        case 2:
            cqDequeue();
            break;

        case 3:
            printf(cqIsEmpty() ? "Queue is Empty.\n" : "Queue is Not Empty.\n");
            break;

        case 4:
            printf(cqIsFull() ? "Queue is Full.\n" : "Queue is Not Full.\n");
            break;

        case 5:
            cqDisplay();
            break;

        case 6:
            cqPeek();
            break;

        case 7:
            return;

        default:
            printf("Invalid choice!\n");
        }
    }
}
