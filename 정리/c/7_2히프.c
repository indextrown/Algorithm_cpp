#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

// 각 요소를 구조체로 정의
typedef struct
{
    int key;
} element;

typedef struct
{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 생성 함수
HeapType *create()
{
    return (HeapType *)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType *heap)
{
    heap->heap_size = 0;
}

// 삽입 함수
void insert_max_hea(HeapType *heap, element item)
{
    int i;
    // 힙 크기를 증가시키고, i에 새로운 원소의 인덱스를 할당
    i = ++(heap->heap_size);

    // 부모 노드와 비교하면서 힙의 규칙을 만족할 때까지 위치를 조정
    while((i != 1) && (item.key > heap->heap[i/2].key))
    {
        heap->heap[i] = heap->heap[i/2]; // 부모 노드의 값을 현재 위치로 이동
        i /= 2;                          // 부모 노드로 이동
    }
    // 최종적으로 새로운 원소를 삽입
    heap->heap[i] = item;
}




// 삭제 함수
element delete_max_heap(HeapType *heap)
{
    int parent, child;
    element item, temp;

    item = heap->heap[1];
    temp = heap->heap[(heap->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= heap->heap_size)
    {
        if ((child < heap->heap_size) && (heap->heap[child].key) < heap->heap[child+1].key)
            child++;
        if (temp.key >= heap->heap[child].key) break;
        heap->heap[parent] = heap->heap[child];
        parent = child;
        child *=2;
    }
    heap->heap[parent] = temp;
    return item;
}

int main()
{
    element e1 = {10}, e2 = {5}, e3 = {30};
    element e4, e5, e6;
    HeapType *heap;

    heap = create(); // 히프 생성
    init(heap);      // 초기화

    // 삽입
    insert_max_hea(heap, e1);
    insert_max_hea(heap, e2);
    insert_max_hea(heap, e3);

    // 삭제
    e4 = delete_max_heap(heap);
    printf("<%d>", e4.key);

    e5 = delete_max_heap(heap);
    printf("<%d>", e5.key);

    e6 = delete_max_heap(heap);
    printf("<%d>", e6.key);

}
