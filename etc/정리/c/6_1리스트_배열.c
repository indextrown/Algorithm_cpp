#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct 
{
    element array[MAX_LIST_SIZE]; // 배열 정의
    int size;                     // 리스트 저장된 항목 개수
} ArrayListType;

// 오류 처리
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 초기화
void init(ArrayListType *L)
{
    L->size=0;
}       
// 비었는지
int is_empty(ArrayListType *L)
{
    return L->size == 0;
}
// 꽝 찼는지 확인
int is_full(ArrayListType *L)
{
    return L->size == MAX_LIST_SIZE;
}
// 특정 위치 항목 가져옴
element get_entry(ArrayListType *L, int pos)
{
    if (pos < 0 || pos >= L->size)
        error("위치 오류");
    return L->array[pos];
}
// 리스트 출력
void print_list(ArrayListType *L)
{
    for (int i=0; i<L->size; i++)
        printf("%d->", L->array[i]);
    printf("\n");
}
// 마지막 위치 삽입
void insert_last(ArrayListType *L, element item)
{
    if (L->size > MAX_LIST_SIZE)
        error("리스트 오버플로우");
    L->array[(L->size)++] = item;
}
// 특정 위치에 삽입
void insert(ArrayListType *L, int pos, int item)
{
    if (!is_full(L) && (pos >= 0) && (pos <= L->size))
    {
        for (int i=L->size-1; i >= pos; i--)
        {
            L->array[i+1] = L->array[i];
        }
        L->array[pos] = item;
        L->size++;
    }
}
// 특정 위치 삭제
element delete(ArrayListType *L, int pos)
{
    element item;
    
    if (pos < 0 || pos >= L->size) //[0,1,2,3,4] -> 5없음
        error("위치오류");
    item = L->array[pos];
    for (int i= pos; i<L->size-1; i++)
        L->array[i] = L->array[i+1];
    L->size--;
    return item;
}


int main()
{
    ArrayListType list;
    init(&list);

    insert(&list, 0, 10); // 0번째 위치에 10 추가
    insert(&list, 1, 20); // 0번째 위치에 20 추가
    insert(&list, 2, 30); // 0번째 위치에 30 추가
    print_list(&list);
    delete(&list, 0); // 0번째 항목 삭제
    print_list(&list);

    printf("%d\n", get_entry(&list, 1)); // 인덱스 1의 항복 
    return 0;
}
