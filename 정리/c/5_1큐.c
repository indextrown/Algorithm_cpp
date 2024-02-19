#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct      // 큐 타입
{
    element front;
    element rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message)
{
    printf("%s\n", message);
    exit(1);
}

void queue_print(QueueType *q)
{
    for (int i=0; i<MAX_QUEUE_SIZE; i++)
    {
        // 현재 인덱스가 front보다 작거나 rear보다 크다면 해당 인덱스는 큐에 속하지 않음
        if (i <= q->front || i > q->rear)
            printf(" | ");
        else
            printf("%d | ", q->data[i]);
    }
    printf("\n");
}

void init_queue(QueueType *q)
{
    q->front = -1;
    q->rear = -1;
}

int is_full(QueueType *q)
{
    return q->rear == MAX_QUEUE_SIZE-1;
}

int is_empty(QueueType *q)
{
    return q->front == q->rear;
}

void enqueue(QueueType *q, int value)
{
    if (is_full(q))
    {
        printf("포화상태");
        return;
    }
    q->data[++(q->rear)] = value;
}

int dequeue(QueueType *q)
{
    if (is_empty(q))
    {
        printf("공백상태");
        return -1;
    }
    return q->data[++(q->front)];
}


int main()
{
    QueueType queue;
    
    init_queue(&queue);

    enqueue(&queue, 10);
    queue_print(&queue);

    enqueue(&queue, 20);
    queue_print(&queue);

    enqueue(&queue, 30);
    queue_print(&queue);

    enqueue(&queue, 30);
    queue_print(&queue);

    

    return 0;
}