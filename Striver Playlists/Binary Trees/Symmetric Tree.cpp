#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    bool is_symmetric(TreeNode *left, TreeNode *right)
    {
        if (left == NULL || right == NULL)
        {
            return (left == right);
        }

        if (left->val != right->val)
        {
            return false;
        }

        return ((is_symmetric(left->left, right->right)) && (is_symmetric(left->right, right->left)));
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        return is_symmetric(root->left, root->right);
    }
};

int main()
{

    return 0;
}