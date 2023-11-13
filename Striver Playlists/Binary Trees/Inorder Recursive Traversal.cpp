#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int data)
    {
        this->val = data;
    }
};

// Recursion
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &traversal)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, traversal);  // Left
        traversal.push_back(root->val);  // Root
        inorder(root->right, traversal); // Right
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> traversal;
        inorder(root, traversal);
        return traversal;
    }
};

int main()
{

    return 0;
}