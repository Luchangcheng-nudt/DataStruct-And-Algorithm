//Init num = 0, begin = 0, end = MaxArrayIndex. maybe num is global or in main function
TreeNode* PIBuildTree(char pre[], char in[], int begin, int end, int& num)
{
    if (begin > end)
        return NULL;
    TreeNode* temp = CreateBTNode(pre[num++], NULL, NULL);
    if (begin == end)
        return temp;
    
    int index = -1;
    for (int i = begin; i <= end; i++)
    {
        if (in[i] == temp->data)
        {
            index = i;
            break;
        }
    }

    temp->left = PIBuildTree(pre, in, begin, index - 1, num);
    temp->right = PIBuildTree(pre, in, index + 1, end, num);
    return temp;
}
