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
执行用时 :12 ms, 在所有 C++ 提交中击败了97.21%的用户
内存消耗 :16.9 MB, 在所有 C++ 提交中击败了52.86%的用户
*/
class Solution {
public:
    int postIndex = 0;
    TreeNode* IPBuildTree(vector<int>& inorder, vector<int>& postorder, int left, int right)
    {
        if (left > right)
            return NULL;
        TreeNode* temp = new TreeNode(postorder[postIndex--]);
        if (left == right)
            return temp;
        
        int index = 0x7f7f7f7f;
        for (int i = right; i >= 0; i--)
        {
            if (inorder[i] == temp->val)
            {
                index = i;
                break;
            }
        }

        temp->right = IPBuildTree(inorder, postorder, index + 1, right);
        temp->left = IPBuildTree(inorder, postorder, left, index - 1);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        TreeNode* root = IPBuildTree(inorder, postorder, 0, postIndex);
        return root;
    }
};
