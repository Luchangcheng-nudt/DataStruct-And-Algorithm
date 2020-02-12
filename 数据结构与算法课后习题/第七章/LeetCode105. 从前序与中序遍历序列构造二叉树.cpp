/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
执行结果：通过
执行用时 :16 ms, 在所有 C++ 提交中击败了91.37%的用户
内存消耗 :16.7 MB, 在所有 C++ 提交中击败了58.73%的用户
*/
class Solution {
public:
    int preIndex = 0;
    TreeNode* PIBuildTree(vector<int>& preorder, vector<int>& inorder, int left, int right)
    {
        if (left > right)
            return NULL;
        TreeNode* temp = new TreeNode(preorder[preIndex++]);
        if (left == right)
            return temp;
        
        int index = -1;
        for (int i = 0; i <= right; i++)
        {
            if (inorder[i] == temp->val)
            {
                index = i;
                break;
            }
        }

        temp->left = PIBuildTree(preorder, inorder, left, index - 1);
        temp->right = PIBuildTree(preorder, inorder, index + 1, right);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return PIBuildTree(preorder, inorder, 0, preorder.size() - 1);
    }
};
