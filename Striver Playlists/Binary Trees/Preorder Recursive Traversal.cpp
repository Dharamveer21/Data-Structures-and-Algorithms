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
    void preorder(TreeNode *root, vector<int> &traversal)
    {
        if (root == NULL)
        {
            return;
        }

        traversal.push_back(root->val);   // Root
        preorder(root->left, traversal);  // Left
        preorder(root->right, traversal); // Right
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> traversal;
        preorder(root, traversal);
        return traversal;
    }
};

int main()
{

    return 0;
}