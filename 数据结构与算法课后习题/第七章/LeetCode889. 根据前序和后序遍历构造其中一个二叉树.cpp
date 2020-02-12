TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
{
  TreeNode* node = new TreeNode(pre[preIndex++]);

  if (node->val != post[postIndex])
    node->left = constructFromPrePost(pre, post);
  if (node->val != post[postIndex])
    node->right = constructFromPrePost(pre, post);
  
  postIndex++;
  return node;
 }
