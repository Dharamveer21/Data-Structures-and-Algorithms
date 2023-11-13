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

// TC : O(log n) * O(log n) approach && SC : O(log n) -- because it a complete tree

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left_height = left_height_finder(root);
        int right_height = right_height_finder(root);

        if (left_height == right_height)
        {
            return (1 << left_height) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int left_height_finder(TreeNode *node)
    {
        int height = 0;

        while (node != NULL)
        {
            height++;
            node = node->left;
        }

        return height;
    }

    int right_height_finder(TreeNode *node)
    {
        int height = 0;

        while (node != NULL)
        {
            height++;
            node = node->right;
        }

        return height;
    }
};

int main()
{

    return 0;
}