TreeNode* FindPreNode(TreeNode* threadedRoot)
{
    if (threadedRoot == NULL)
        return NULL;
    
    if (threadedRoot->lflag == 1)
        return threadedRoot->left;

    threadedRoot = threadedRoot->left;
    while (threadedRoot != NULL && threadedRoot->rflag == 0)
        threadedRoot = threadedRoot->right;
    
    return threadedRoot;
}
