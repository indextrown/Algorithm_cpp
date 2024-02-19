#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct
{
    element front;
    element rear;
    element *data;
} QueueType;   


void init_queue(QueueType *q, int size)
{
    q->front = q->rear = 0;
    q->data = (element *)malloc(size * sizeof(element));
    if (q->data == NULL)
    {
        exit(1);
    }
}

element is_empty(QueueType *q)
{
    return q->front == q->rear;
}

element is_full(QueueType *q, int size)
{
    // 원형큐는 자리 하나 비워둔다
    // rear가 배열의 끝에 도달하면 다시 배열의 처음으로 되돌아간다
    // 이때 q->front와 같으면 큐는 가득찼다고 판단
    
    // return (q->rear+1) % size == (q->front)*size;
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
        q->rear = (q->rear + 1) % size;
        q->data[q->rear] = value;
    }
}

element dequeue(QueueType *q, int size)
{
    if(is_empty(q))
    {
        return -1;
    }
    else
    {
        q->front = (q->front+1) % size;
        return q->data[q->front];
    }
}

element peek(QueueType *q, int size)
{
    if(is_empty(q))
    {
        return -1;
    }
    else
    {
        return q->data[(q->front+1) % size];
    }
}


element back(QueueType *q, int size)
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

void free_queue(QueueType *q)
{
    free(q->data);
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
            printf("%d\n", (q.rear - q.front + size) % size);
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
    free_queue(&q);

    return 0;
}

