#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    int front;
    int rear;
    int count; // 요소 개수
    int *data;
} QueueType;

// 초기화
void init_queue(QueueType *q, int size)
{
    q->front = q->rear = q->count = 0;
    q->data = (int *)malloc(size * sizeof(int));
}

int is_empty(QueueType *q)
{
    return q->front == q->rear;
}

int is_full(QueueType *q, int size)
{
    return (q->rear+1) % size == q->front;
}

void enqueue(QueueType *q, int value, int size)
{
    if (is_full(q, size))
    {
        printf("-1\n");
    }
    else
    {
        q->count++;
        q->rear = (q->rear+1) % size;
        q->data[q->rear] = value;
    }
}

int dequeue(QueueType *q, int size)
{
    if (is_empty(q))
        return -1;
    q->count--;
    q->front = (q->front+1) % size;
    return q->data[q->front];
}


int peek(QueueType *q, int size)
{
    if (is_empty(q))
        return -1;
    return q->data[(q->front+1) % size];
}

int back(QueueType *q, int size)
{
    if (is_empty(q))
    {
        return -1;
    }
    else
    {
        return q->data[q->rear];
    }
}

int main()
{
    int size;
    int value;
    char command[10]; 
    scanf("%d", &size);

    QueueType q;
    init_queue(&q, size);

     for (int i=0; i<size; i++)
    {
        scanf("%s", command);
        if (strcmp(command, "push")==0)
        {
            scanf("%d", &value);
            enqueue(&q, value, size);
        }
        else if (strcmp(command, "pop")==0)
        {
            printf("%d\n", dequeue(&q, size));
        }
        else if (strcmp(command, "size")==0)
        {
            // printf("%d\n", (q.rear - q.front + size) % size);
            printf("%d\n", q.count);
        }
        else if (strcmp(command, "empty")==0)
        {
            printf("%d\n", is_empty(&q));
        }
        else if (strcmp(command, "front")==0)
        {
            printf("%d\n", peek(&q, size));
        }
        else if (strcmp(command, "back")==0)
        {
            printf("%d\n", back(&q, size));
        }
    }
    free(q.data);
    return 0;
}

