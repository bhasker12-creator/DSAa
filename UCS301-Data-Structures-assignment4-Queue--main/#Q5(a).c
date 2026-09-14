#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int q1[MAX], q2[MAX];
int q1Front = 0, q1Rear = -1;
int q2Front = 0, q2Rear = -1;

void q1Enqueue(int value)
{
    q1[++q1Rear] = value;
}

int q1Dequeue()
{
    return q1[q1Front++];
}

void q2Enqueue(int value)
{
    q2[++q2Rear] = value;
}

int q2Dequeue()
{
    return q2[q2Front++];
}

int stackTwoQueuesEmpty()
{
    return q1Front > q1Rear;
}

void stackTwoQueuesPush(int value)
{
    int temp;

    q2Enqueue(value);

    while (q1Front <= q1Rear)
    {
        temp = q1Dequeue();
        q2Enqueue(temp);
    }

    q1Front = 0;
    q1Rear = -1;

    while (q2Front <= q2Rear)
    {
        temp = q2Dequeue();
        q1Enqueue(temp);
    }

    q2Front = 0;
    q2Rear = -1;

    printf("%d pushed into stack.\n", value);
}

void stackTwoQueuesPop()
{
    int value;

    if (stackTwoQueuesEmpty())
    {
        printf("Stack Underflow!\n");
        return;
    }

    value = q1Dequeue();
    printf("%d popped from stack.\n", value);
}

void stackTwoQueuesPeek()
{
    if (stackTwoQueuesEmpty())
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element = %d\n", q1[q1Front]);
}

void stackTwoQueuesDisplay()
{
    int i;

    if (stackTwoQueuesEmpty())
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements: ");
    for (i = q1Front; i <= q1Rear; i++)
        printf("%d ", q1[i]);

    printf("\n");
}

void stackTwoQueuesMenu()
{
    int choice, value;

    while (1)
    {
        printf("\n===== STACK USING TWO QUEUES =====\n");
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
            printf("Enter value: ");
            scanf("%d", &value);
            stackTwoQueuesPush(value);
            break;

        case 2:
            stackTwoQueuesPop();
            break;

        case 3:
            stackTwoQueuesPeek();
            break;

        case 4:
            stackTwoQueuesDisplay();
            break;

        case 5:
            return;

        default:
            printf("Invalid choice!\n");
        }
    }
}
