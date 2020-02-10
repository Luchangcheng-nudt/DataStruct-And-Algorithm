//Programmer: Luchangcheng  2020/02/09
//Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)  std=c11  tested on Ubuntu Kylin 19.10.1
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
void InOrderThreaded(TreeNode* p);//非递归中序线索化二叉树实现
void ThreadedInTravel(TreeNode* p);


int main()
{
    char list[] = "abcdef";
    TreeNode* root = BuildBTree(list, strlen(list));

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

void InOrderThreaded(TreeNode* p)//非递归中序线索化二叉树实现
{
    TreeNode* stack[MAXSIZE] = {NULL};
    int curSize = -1;
    TreeNode* cur = p;
    TreeNode* pre = NULL;

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

            //按照规则，依次将结点线索化
            if (pre != NULL && pre->rflag == 1)
                pre->right = cur;
            if (cur->left == NULL)
            {
                cur->lflag = 1;
                cur->left = pre;
            }
            if (cur->right == NULL)
                cur->rflag = 1;
            pre = cur;
            //×××××××××××××××××××××

            cur = cur->right;
        }
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
