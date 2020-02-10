//Programmer: Luchangcheng  2020/02/10
//Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)  std=C11  tested on Ubuntu Kylin 19.10.1
int isFullBT(TreeNode* root)
{
    TreeNode* que[MAXSIZE] = {NULL};
    int front = -1;
    int rear = -1;
    que[++rear % MAXSIZE] = root;

    int level = 1;
    int cnt = 1;
    TreeNode* preNode = NULL;

    while (front != rear)
    {
        TreeNode* temp = que[++front % MAXSIZE];

        if (cnt > 1 && temp != NULL && preNode == NULL)
            return 0;
        if (temp != NULL)
        {
            que[++rear % MAXSIZE] = temp->left;
            que[++rear % MAXSIZE] = temp->right;
        }

        if (cnt >= level)
        {
            cnt = 1;
            level <<= 1;
        }
        preNode = temp;
        cnt++;
    }

    return 1;
}
