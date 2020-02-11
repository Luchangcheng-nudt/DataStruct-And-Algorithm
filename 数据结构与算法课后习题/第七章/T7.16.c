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
