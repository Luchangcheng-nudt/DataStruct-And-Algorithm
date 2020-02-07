//Programmer: Luchangcheng  2020/02/07
//Compiler: gcc version 8.1.0 (x86_64-win32-sjlj-rev0, Built by MinGW-W64 project)  -std=C++11 tested on Windows 10
#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* BuildTree(int nodeList[], int len);
void FindNext(TreeNode* root, int nodelist[], int len, int index);
void DFS(TreeNode* root);
int main()
{
    int list[] = { -1, 0, 2, 31, 4, 575, -1, 7 };
    TreeNode* root = BuildTree(list, 8);

    DFS(root);

    return 0;
}

TreeNode* BuildTree(int nodeList[], int len)
{
    TreeNode* head = new TreeNode;
    head->data = nodeList[1];
    head->left = NULL;
    head->right = NULL;
    FindNext(head, nodeList, len, 1);

    return head;
}

void FindNext(TreeNode* root, int nodelist[], int len, int index)
{
    int data = root->data;
    if ((index << 1) < len)
    {
        TreeNode* nextNode = new TreeNode;
        nextNode->data = nodelist[index << 1];
        nextNode->left = NULL;
        nextNode->right = NULL;
        root->left = nextNode;
        FindNext(root->left, nodelist, len, index << 1);
    }
    if ((index << 1) + 1 < len)
    {
        TreeNode* nextNode = new TreeNode;
        nextNode->data = nodelist[(index << 1) + 1];
        nextNode->left = NULL;
        nextNode->right = NULL;
        root->right = nextNode;
        FindNext(root->right, nodelist, len, (index << 1) + 1);
    }
}

void DFS(TreeNode* root)
{
    if (root == NULL)
        return;
    if (root->data == -1)
        cout << "Null ";
    else 
        cout << root->data << " ";
    if (root->left != NULL)
    {
        DFS(root->left);
    }
    if (root->right != NULL)
    {
        DFS(root->right);
    }
}
