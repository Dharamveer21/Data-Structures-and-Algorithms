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

/*Balanced binary tree is a tree if for every node -- whose left subtree & right subtree has a height diff of <= 1*/
// This is an O(N^2) approach as in this approach we will calculate the height of tree every time the balanced function is called
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return (1 + max(height(root->left), height(root->right)));
    }

    bool is_balanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        if (is_balanced(root->left) && is_balanced(root->right))
        {
            return (abs(height(root->left) - height(root->right)) <= 1);
        }

        return false;
    }

    bool isBalanced(TreeNode *root)
    {
        return is_balanced(root);
    }
};

// O(N) solution would be when we just use height funtion & modify it in between
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left_height = height(root->left);
        int right_height = height(root->right);

        if ((left_height == -1 || right_height == -1) || (abs(left_height - right_height) > 1))
        {
            return -1;
        }
        
        return (1 + max(left_height, right_height));
    }

    bool isBalanced(TreeNode *root)
    {
        return (height(root) != -1);
    }
};

int main()
{

    return 0;
}