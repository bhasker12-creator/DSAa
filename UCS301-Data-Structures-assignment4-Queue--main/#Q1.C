#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int simpleQueue[MAX];
int sqFront = -1, sqRear = -1;

int sqIsEmpty()
{
    return sqFront == -1;
}

int sqIsFull()
{
    return sqRear == MAX - 1;
}

void sqEnqueue(int value)
{
    if (sqIsFull())
    {
        printf("Queue Overflow!\n");
        return;
    }

    if (sqFront == -1)
        sqFront = 0;

    simpleQueue[++sqRear] = value;
    printf("%d inserted into queue.\n", value);
}

void sqDequeue()
{
    if (sqIsEmpty())
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("%d deleted from queue.\n", simpleQueue[sqFront]);

    if (sqFront == sqRear)
        sqFront = sqRear = -1;
    else
        sqFront++;
}

void sqPeek()
{
    if (sqIsEmpty())
        printf("Queue is empty!\n");
    else
        printf("Front element = %d\n", simpleQueue[sqFront]);
}

void sqDisplay()
{
    int i;

    if (sqIsEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (i = sqFront; i <= sqRear; i++)
        printf("%d ", simpleQueue[i]);

    printf("\n");
}

void simpleQueueMenu()
{
    int choice, value;

    while (1)
    {
        printf("\n===== SIMPLE QUEUE =====\n");
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
            sqEnqueue(value);
            break;

        case 2:
            sqDequeue();
            break;

        case 3:
            printf(sqIsEmpty() ? "Queue is Empty.\n" : "Queue is Not Empty.\n");
            break;

        case 4:
            printf(sqIsFull() ? "Queue is Full.\n" : "Queue is Not Full.\n");
            break;

        case 5:
            sqDisplay();
            break;

        case 6:
            sqPeek();
            break;

        case 7:
            return;

        default:
            printf("Invalid choice!\n");
        }
    }
}