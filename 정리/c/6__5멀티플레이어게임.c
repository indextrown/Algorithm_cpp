#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef int element;
//typedef char element[100];
typedef struct
{
    char data[100];
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, char *value)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    strcpy(node->data, value);
    if (head == NULL)
    {
        head = node;
        node->link = head;
    }
    else
    {
        node->link = head->link;
        head->link = node;
    }
    return head;
}



void print_list(ListNode *head)
{
    ListNode *p;
    if (head==NULL) return; // 빈리스트면 함수종료
    p=head->link;
    do {
        printf("%d->", p->data);// 현재노드의 데이터 출력
        p = p->link;// 다음 노드로 이동
    } while (p!=head->link);// 처음 노드로 돌아올 때까지 반복
}


int main()
{
    ListNode *head = NULL;

    head = insert_first(head, "A");
    head = insert_first(head, "B");
    head = insert_first(head, "C");

    ListNode *p = head;
    for (int i=0; i<100; i++)
    {
        printf("%s\n", p->data);
        p=p->link;
    }

    return 0;
}


