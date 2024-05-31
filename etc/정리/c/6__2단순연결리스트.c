#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
}ListNode;

// 오류 처리
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 첫번째 삽입
ListNode *insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// 리스트 헤드를 반환하거나 삽입한 노드 반환 ->
// 삽입함수
ListNode *insert(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

// 첫 노드 삭제
ListNode *delete_first(ListNode *head)
{
    ListNode *removed;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

// 특정 노드 삭제
ListNode *delete(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    head = removed->link;
    free(removed);
    return head;
}

ListNode *reverse(ListNode *head)
{
    ListNode *p, *q, *r;
    p = head;  // 역순으로 만들 리스트
    q = NULL;  // 역순으로 만들 노드
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;

}

void print_list(ListNode *head)
{
    for (ListNode *p = head; p != NULL; p=p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}


int main()
{
//    // 동적 할당을 위한 포인터
//    ListNode *head = NULL;
//    head = (ListNode *)malloc(sizeof(ListNode));
//
//    // first node
//    head -> data = 10;
//    head -> link = NULL;
//
//    // second node
//    ListNode *secondNode;
//    secondNode = (ListNode *)malloc(sizeof(ListNode));
//    secondNode->data = 20;
//    secondNode->link = NULL;
//
//    // firstnode -> secondnode연결
//    head->link = secondNode;
//    printf("%d %d\n", head->data, head->link->data);
//
    ListNode *head = NULL;
    for (int i=0; i<5; i++)
    {
        head = insert_first(head, i);
        print_list(head);
    }

    for (int i=0; i<5; i++)
    {
        head = delete_first(head);
        print_list(head);
    }
    for (int i=0; i<5; i++)
    {
        head = insert_first(head, i);
        print_list(head);
    }
    ListNode *head2 = reverse(head);
    print_list(head2);



    return 0;
}
