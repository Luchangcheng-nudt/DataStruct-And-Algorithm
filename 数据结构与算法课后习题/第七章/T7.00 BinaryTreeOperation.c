#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct btNode
{
    ElementType data;
    struct btNode *left;
    struct btNode *right;
}BTNode;

BTNode* InitBTNode(ElementType data);
BTNode* BuildTree(ElementType DataList[], int i, int n);
void PreOrder(BTNode *root);
void InOrder(BTNode *root);
void PostOrder(BTNode *root);

int main()
{
    ElementType data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    BTNode *root = BuildTree(data, 0, 10);

    PreOrder(root);
    return 0;
}

BTNode* InitBTNode(ElementType data)
{
    BTNode *ans = (BTNode*)malloc(sizeof(BTNode));
    if (ans == NULL)
    {
        printf("Memory allocate error!\n");
        exit(1);
    }

    ans->data = data;
    ans->left = NULL;
    ans->right = NULL;
    return ans;
}

BTNode* BuildTree(ElementType DataList[], int i, int n)
{
    if (DataList == NULL || i >= n || DataList[i] == -1)
        return NULL;
    
    BTNode *ans = InitBTNode(DataList[i]);
    ans->left = BuildTree(DataList, (i << 1) + 1, n);
    ans->right = BuildTree(DataList, (i + 1) << 1, n);
}

void PreOrder(BTNode* root)
{
    BTNode *stack[512] = {0};
    int index = -1;

    while (index > -1 || root != NULL)
    {
        if (root != NULL)
        {
            printf("%d ", root->data);
            stack[++index] = root;
            root = root->left;
        }
        else 
        {
            root = stack[index--];
            root = root->right;
        }
    }

    printf("\n");
}

void InOrder(BTNode *root)
{
    BTNode *stack[512] = {0};
    int index = -1;

    while (index > -1 || root != NULL)
    {
        if (root != NULL)
        {
            stack[++index] = root;
            root = root->left;
        }
        else 
        {
            root = stack[index--];
            printf("%d ", root->data);
            root = root->right;
        }
    }

    printf("\n");
}

void PostOrder(BTNode *root)
{
    BTNode *stack[512] = {0};
    int index = -1;
    BTNode *old = NULL;

    while (index > -1 || root != NULL)
    {
        if (root != NULL)
        {
            stack[++index] = root;
            root = root->left;
        }
        else
        {
            root = stack[index];
            if (root->right != NULL && root->right != old)
                root = root->right;
            else
            {
                stack[index--] = NULL;
                printf("%d ", root->data);
                old = root;
                root = NULL;
            }
        }
    }

    printf("\n");
}