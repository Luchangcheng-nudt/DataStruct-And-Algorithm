//Programmer: Luchangcheng  2020/02/08
//Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)  std=C++11  tested on Ubuntu Kylin 19.10.1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 0x7f
typedef char EleType;
typedef struct Node TreeNode;

struct Node
{
    EleType data;
    TreeNode* left;
    TreeNode* right;
};

//BinaryTree Operation
void InitBTNode(TreeNode* root, EleType e, TreeNode* left, TreeNode* right);
TreeNode* CreateBTNode(EleType item, TreeNode* lptr, TreeNode* rptr);
TreeNode* BuildBTree(EleType data[], int len);
void PostOrder(TreeNode* root);
void StackPostOrder(TreeNode* root);
void InOrder(TreeNode* root);
void StackInOrder(TreeNode* root);
void PreOrder(TreeNode* root);
void StackPreOrder(TreeNode* root);

int main()
{
    char list[] = "abcdef";
    TreeNode* root = BuildBTree(list, strlen(list));
    
    StackPostOrder(root);
    StackInOrder(root);
    StackPreOrder(root);
    return 0;
}

void InitBTNode(TreeNode* root, EleType e, TreeNode* leftNode, TreeNode* rightNode)
{
    root->left = leftNode;
    root->right = rightNode;
    root->data = e;
}

TreeNode* CreateBTNode(EleType item, TreeNode* lptr, TreeNode* rptr)
{
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    if (p == NULL)
    {
        printf("Memory allocation failure!\n");
        exit(1);
    }
    else 
        InitBTNode(p, item, lptr, rptr);
    return p;
}

TreeNode* BuildBTree(EleType list[], int len)
{
    ++len;
    TreeNode** box = (TreeNode**)malloc(sizeof(TreeNode*) * len);
    for (int i = 1; i < len; i++)
        box[i] = (list[i-1] != -1 ? CreateBTNode(list[i - 1], NULL, NULL) : NULL);

    for (int i = 1; i <= (len >> 1); i++)
    {
        int p = i << 1;
        if (p < len && box[i] != NULL)
        {
            int q = (i << 1) + 1;
            if (q < len)
                InitBTNode(box[i], box[i]->data, box[p], box[q]);
            else 
                InitBTNode(box[i], box[i]->data, box[p], NULL);
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        if (box[i] == NULL)
            free(box[i]);
    }
    
    return box[1] != NULL ? box[1] : NULL;
}

void PostOrder(TreeNode* root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->data);
}

void StackPostOrder(TreeNode* root)
{
    TreeNode* stack[MAXSIZE] = {NULL};
    int curSize = -1;
    TreeNode* cur = root;
    TreeNode* old = NULL;

    while (cur != NULL || curSize != -1)
    {
        if (cur != NULL)
        {
            stack[++curSize] = cur;
            cur = cur->left;
        }
        else
        {
            cur = stack[curSize];
            if (cur->right != NULL && cur->right != old)
                cur = cur->right;
            else
            {
                stack[curSize--] = NULL;
                printf("%c ", cur->data);
                old = cur;
                cur = NULL;
            }
        }
    }
    printf("\n");
}

void InOrder(TreeNode* root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}

void StackInOrder(TreeNode* root)
{
    TreeNode* stack[1000] = {NULL};
    int curSize = -1;
    TreeNode* cur = root;
    
    while (cur != NULL || curSize > -1)
    {
        if (cur != NULL)
        {
            stack[++curSize] = cur;
            cur = cur->left;
        }
        else
        {
            cur = stack[curSize];
            stack[curSize--] = NULL;
            printf("%c ", cur->data);
            cur = cur->right;
        }
    }
    printf("\n");
}

void PreOrder(TreeNode* root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void StackPreOrder(TreeNode* root)
{
    TreeNode* stack[1000] = {NULL};
    int curSize = -1;
    TreeNode* cur = root;
    
    while (cur != NULL || curSize > -1)
    {
        if (cur != NULL)
        {
            printf("%c ", cur->data);
            stack[++curSize] = cur;
            cur = cur->left;
        }
        else
        {
            cur = stack[curSize];
            stack[curSize--] = NULL;
            cur = cur->right;
        }
    }
    printf("\n");
}
