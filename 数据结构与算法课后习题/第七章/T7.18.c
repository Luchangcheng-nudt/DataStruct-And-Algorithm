TreeNode* FindPreNode(TreeNode* threadedRoot)
{
    if (threadedRoot == NULL)
        return NULL;
    
    if (threadedRoot->rflag == 0)
        return threadedRoot->right;
    if (threadedRoot->lflag == 0)
        return threadedRoot->left;
    
    threadedRoot = threadedRoot->left;
    while (threadedRoot != NULL && threadedRoot->lflag == 1)
        threadedRoot = threadedRoot->left;

    return threadedRoot != NULL ? threadedRoot->left : NULL;
}
