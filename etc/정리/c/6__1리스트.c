#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element; // 항목 정의
typedef struct
{
    int size;                            // 저장된 항목들의 개수
    element array[MAX_LIST_SIZE];    // 배열 정의
} ArrayType;

// 오류 처리
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 초기화
void initial(ArrayType *L)
{
    L->size = 0;
}

// 리스트가 비어있으면 1 아니면 0반환
int is_empty(ArrayType *L)
{
    return L->size == 0;
}

// 리스트가 꽉차있으면 1 아니면 0반환
int is_full(ArrayType *L)
{
    return L->size == MAX_LIST_SIZE;
}

// 지정된 위치 항목 검색
int get_entry(ArrayType *L, int position)
{
    if (is_full(L))
        error("위치 오류");
    return L-> array[position];
}

// 리스트 마지막 삽입
void insert_last(ArrayType *L, int value)
{
    if (L->size >= MAX_LIST_SIZE)
        error("리스트 오버플로우");
    L->array[L->size++] = value;
}

// 항목 삽입 연산
void insert(ArrayType *L, int position, int value)
{
    // 삽입을 위해서는 리스트 크기와 같아도 된다
    if (!(is_full(L)) && position >= 0 && position <= L->size)
    {
        for (int i=L->size-1; i>=position; i--)
            L->array[i+1] = L->array[i];
        L->array[position] = value;
        L->size++;
    }
}

// 항목 삭제 연산
int delete(ArrayType *L, int pos)
{
    element item;
    if (pos < 0 || pos >= L->size)
        error("위치 오류");
    item = L->array[pos];
    for (int i=pos; i<L->size-1; i++)
        L->array[i] = L->array[i+1];
    L->size--;
    return item;
}



// 리스트 출력
void print_lst(ArrayType *L)
{
    for (int i=0; i<L->size; i++)
        printf("%d->", L->array[i]);
    printf("\n");
}




int main()
{
    ArrayType list;
    insert_last(&list, 10);
    insert_last(&list, 20);
    insert_last(&list, 30);

    insert_last(&list, 40);
    delete(&list, 0);
    print_lst(&list);
    printf("get entry연산은 인덱스를 사용해 바로 접근하므로 O(1)\n");
    printf("삽입, 삭제 연산은 다른 항목들을 이동하는 경우가 많으므로 최악의 경우 O(n)\n");
    return 0;
}



