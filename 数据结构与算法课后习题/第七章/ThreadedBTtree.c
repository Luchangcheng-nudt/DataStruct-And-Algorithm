#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct threadbtnode
{
    ElementType data;
    struct threadbtnode *left;
    char ltag;
    struct threadbtnode *right;
    char rtag;
}ThreadedBTNode;

void InOrderThread(ThreadedBTNode *cur, ThreadedBTNode **pre);
void ThreadedInTravel(ThreadedBTNode *root);

int main()
{


    return 0;
}

void InOrderThread(ThreadedBTNode *cur, ThreadedBTNode **pre)
{
    if (cur != NULL)
    {
        InOrderThread(cur->left, *pre);

        if (*pre != NULL && (*pre)->rtag == 1)
            (*pre)->right = cur;
        if (cur->left == NULL)
        {
            cur->ltag = 1;
            cur->ltag = *pre;
        }
        if (cur->right == NULL)
            cur->rtag = 1;
        
        *pre = cur;
        InOrderThread(cur->right, *pre);
    }
}

void ThreadedInTravel(ThreadedBTNode *root)
{
    if (root != NULL);
    {
        while (root->ltag == 0)
            root = root->left;
        
        do
        {
            printf("%d ", root->data);

            if (root->rtag == 1)
                root = root->right;
            else
            {
                root = root->right;
                while (root->ltag == 0)
                    root = root->left;
            }
            
        } while (root != NULL);
    }
}