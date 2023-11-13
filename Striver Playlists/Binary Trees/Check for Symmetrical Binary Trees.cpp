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

// use simple recursion to check the equality of left subtree & right subtree
class Solution
{
public:
    bool is_tree_equal(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL || root2 == NULL)
        {
            return (root1 == root2);
        }
        
        if (root1->val != root2->val)
        {
            return false;
        }

        if (!is_tree_equal(root1->left, root2->left))
        {
            return false;
        }

        if (!is_tree_equal(root1->right, root2->right))
        {
            return false;
        }

        return true;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return is_tree_equal(p, q);
    }
};

int main()
{

    return 0;
}