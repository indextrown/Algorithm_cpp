#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;  // 자기 참조 구조체, 링크필드는 ListNode를 가리키는 포인터로 정의
} ListNode;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
}

// 헤드 포인터를 반환하기 떄문에 타입 중요
ListNode *insert_front(ListNode *head, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head; // 변경된 헤드 포인터 반환
}


ListNode *delete_first(ListNode *head)
{
    ListNode *removed;
    if (head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode *delete(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head)
{
    for (ListNode *p = head; p!=NULL; p=p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}
int main()
{
    ListNode *head = NULL;

    for (int i=0; i<5; i++)
    {
        head = insert_front(head, i);
        print_list(head);
    }
    for (int i=0; i<5; i++)
    {
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}