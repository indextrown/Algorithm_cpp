#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node
{
    element data;
    struct Node *left, *right;
} Node;

//Node n1 = {1, NULL, NULL};
//Node n2 = {4, &n1, NULL};
//Node n3 = {16, NULL, NULL};
//Node n4 = {25, NULL, NULL};
//Node n5 = {20, &n3, &n4};
//Node n6 = {15, &n2, &n5};
//Node *root = &n6;
//https://m.blog.naver.com/rlakk11/60159303809

Node n1 = {7, NULL, NULL};
Node n2 = {8, NULL, NULL};
Node n3 = {9, NULL, NULL};
Node n4 = {10, NULL, NULL};
Node n5 = {11, NULL, NULL};
Node n6 = {3, &n1, &n2};
Node n7 = {4, &n3, &n4};
Node n8 = {1, &n6, &n7};
Node n9 = {5, &n5, NULL};
Node n10 = {6, NULL, NULL};
Node n11 = {2, &n9, &n10};
Node n12 = {0, &n8, &n11};
Node *root = &n12;

// 전위 순회
void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 후위순회
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}
// 후위순회
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->data);
    }
}

int main()
{
    //     15
    //  4      20
    // 1   16    25
    printf("전위순회=");
    preorder(root);
    printf("\n");

    printf("중위순회=");
    inorder(root);
    printf("\n");

    printf("후위순회=");
    postorder(root);
    printf("\n");
//    Node *n1, *n2, *n3;
//
//    n1 = (Node *)malloc(sizeof(Node));
//    n2 = (Node *)malloc(sizeof(Node));
//    n3 = (Node *)malloc(sizeof(Node));
//
//    n1->data = 10;
//    n1->left = n2;
//    n1->right = n3;
//
//    n2->data = 20;
//    n2->left = NULL;
//    n2->right = NULL;
//
//    n3->data = 30;
//    n3->left = NULL;
//    n3->right = NULL;

//    printf("전위순회: ");
//    preorder(n1);
//    printf("\n");
//    printf("중위순회: ");
//    inorder(n1);
//    printf("\n");
//    printf("후위순회: ");
//    postorder(n1);
//
//    free(n1);
//    free(n2);
//    free(n3);

    return 0;

}
