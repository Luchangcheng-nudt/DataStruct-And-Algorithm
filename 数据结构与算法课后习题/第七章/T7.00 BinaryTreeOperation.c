//Programmer: Luchangcheng  2020/02/08
//Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)  std=C++11  tested on Ubuntu Kylin 19.10.1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char EleType;
typedef struct Node TreeNode;
struct Node
{
    EleType data;
    TreeNode* left;
    TreeNode* right;
};

void InitBTNode(TreeNode* root, EleType e, TreeNode* left, TreeNode* right);
TreeNode* CreateBTNode(EleType item, TreeNode* lptr, TreeNode* rptr);
TreeNode* BuildBTree(EleType data[], int len);
void PostOrder(TreeNode* root);
void InOrder(TreeNode* root);
void PreOrder(TreeNode* root);

int main()
{
    char list[] = "abcdef";
    TreeNode* root = BuildBTree(list, strlen(list));
    DFS(root);
    printf("\n");
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
        printf("Memory allocation failure!\n");
    else 
        InitBTNode(p, item, lptr, rptr);
    return p;
}

void PostOrder(TreeNode* root)
{
    if (root == NULL)
        return;
    DFS(root->left);
    DFS(root->right);
    printf("%c ", root->data);
}

void InOrder(TreeNode* root)
{
    if (root == NULL)
        return;
    DFS(root->left);
    printf("%c ", root->data);
    DFS(root->right);
}

void PreOrder(TreeNode* root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    DFS(root->left);
    DFS(root->right);
}

TreeNode* BuildBTree(EleType list[], int len)
{
    ++len;
    TreeNode** NodeList = (TreeNode**)malloc(sizeof(TreeNode*) * len);
    for (int i = 0; i < len; i++)
        NodeList[i] = (TreeNode*)malloc(sizeof(TreeNode));
    for (int i = 1; i < len; i++)
        InitBTNode(NodeList[i], list[i-1], NULL, NULL);
    for (int i = 1; i <= (len >> 1); i++)
    {
        if ((i << 1) < len && NodeList[i] != NULL)
        {
            if ((i << 1) + 1 < len)
                InitBTNode(NodeList[i], NodeList[i]->data, (NodeList[i << 1]->data == -1 ? NULL : NodeList[i << 1]), \
                (NodeList[(i << 1) + 1]->data == -1 ? NULL : (NodeList[i << 1]->data == -1 ? NULL : NodeList[(i << 1) + 1])));
            else 
                InitBTNode(NodeList[i], NodeList[i]->data, (NodeList[i << 1]->data == -1 ? NULL : NodeList[i << 1]), NULL);
        }
    }

    return NodeList[1];
}
