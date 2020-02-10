//Programmer: Luchangcheng  2020/02/09
//Compiler: gcc version 8.1.0 (x86_64-win32-sjlj-rev0, Built by MinGW-W64 project)  std=c11  tested on Windows 10
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
    int lflag;
    int rflag;
};

//BinaryTree Operation
void InitBTNode(TreeNode* root, EleType e, TreeNode* left, TreeNode* right);
TreeNode* CreateBTNode(EleType item, TreeNode* lptr, TreeNode* rptr);
TreeNode* BuildBTree(EleType data[], int len);
void InOrderThreaded(TreeNode* p);
void ThreadedInTravel(TreeNode* p);
TreeNode* pre = NULL;

int main()
{
    char list[] = "abcdef";
    TreeNode* root = BuildBTree(list, strlen(list));
    TreeNode* pre = NULL;
    InOrderThreaded(root);
    ThreadedInTravel(root);
    
    printf("\n");
    return 0;
}

inline void InitBTNode(TreeNode* root, EleType e, TreeNode* leftNode, TreeNode* rightNode)
{
    root->left = leftNode;
    root->right = rightNode;
    root->data = e;
    root->rflag = 0;
    root->lflag = 0;
}

inline TreeNode* CreateBTNode(EleType item, TreeNode* lptr, TreeNode* rptr)
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
        box[i] = (list[i - 1] != -1 ? CreateBTNode(list[i - 1], NULL, NULL) : NULL);

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

    TreeNode* ans = (box[1] != NULL) ? box[1] : NULL;
    for (int i = 0; i < len; i++)
    {
        if (box[i] == NULL)
            free(box[i]);
    }

    return ans;
}

void InOrderThreaded(TreeNode* p)
{
    TreeNode* stack[MAXSIZE] = {NULL};
    int curSize = -1;
    TreeNode* list[MAXSIZE] = {NULL};
    int listSize = 0;
    TreeNode* cur = p;

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
            stack[curSize--] = NULL;
            list[listSize++] = cur;
            cur = cur->right;
        }
    }

    TreeNode* pre = NULL;
    for (int i = 0; i < listSize; i++)//将排好遍历顺序的二叉树结点依次遍历，按照规则线索化
    {
        if (pre != NULL && pre->rflag == 1)
            pre->right = list[i];
        
        if (list[i]->left == NULL)
        {
            list[i]->lflag = 1;
            list[i]->left = pre;
        }

        if (list[i]->right == NULL)
            list[i]->rflag = 1;
        
        pre = list[i];
    }
}

void ThreadedInTravel(TreeNode* p)
{
    if (p != NULL)
    {
        while (p->lflag == 0)
            p = p->left;//找到最左下角的点，即中序遍历的起点
        
        do
        {
            printf("%c ", p->data);
            if (p->rflag == 1)//该节点已被线索化，直接找到右结点
                p = p->right;
            else
            {
                p = p->right;
                while (p->lflag == 0)//该节点存在右子树，未被线索化，则找到下一个左下角的点
                    p = p->left;
            }
        } while (p != NULL);
    }
}
