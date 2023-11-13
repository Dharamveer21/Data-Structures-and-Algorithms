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
    void postorder(TreeNode *root, vector<int> &traversal)
    {
        if (root == NULL)
        {
            return;
        }

        postorder(root->left, traversal);  // Left
        postorder(root->right, traversal); // Right
        traversal.push_back(root->val);    // Root
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> traversal;
        postorder(root, traversal);
        return traversal;
    }
};

int main()
{

    return 0;
}