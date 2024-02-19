#include <stdio.h>
#include <stdlib.h>
#define SIZE 3


typedef struct
{
    int front;      // 앞쪽 index
    int rear;       // 뒤쪽 index
    int data[SIZE]; // 데이터 배열
} Queue;

// 한칸은 무조건 비워야 하기 떄문에 모두 채우면 오류 발생
// 공백상태는 front == rear 이기 때문에 원형큐가 한바퀴 돌고 오면 front=rear를 공백으로 판단할지 포화로 판단할 지 모르기 떄문에
// 포화상태를 임의로 front, rear를 각각 한칸 떨어져서 관리
// 임시해결 -1을 0으로 하면됨
void init(Queue *q)
{
    q->front = q->rear = -1;
}

int is_full(Queue *q)
{
    return (q->rear + 1) % SIZE == q->front;
}

int is_empty(Queue *q)
{
    return q->front == q->rear;
}

void enqueue(Queue *q, int item)
{
    if (is_full(q))
    {
        printf("queue is full");
        exit(1);
    }
    q->rear = (q->rear + 1) % SIZE;
    q->data[q->rear] = item;
}

int dequeue(Queue *q)
{
    if (is_empty(q))
    {
        printf("queue is empty");
        exit(1);
    }
    q->front = (q->front + 1) % SIZE;
    return q->data[q->front];
}


int main()
{
    Queue q;
    init(&q);

    // 포인터를 쓸때는 주소값을 넘겨줘야함
    enqueue(&q, 5);
    enqueue(&q, 4);
    enqueue(&q, 3);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    enqueue(&q, 2);
    enqueue(&q, 1);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    return 0;
}


