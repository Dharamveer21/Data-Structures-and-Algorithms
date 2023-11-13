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

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

class Solution
{
public:
    // A O(N^2) solution would be i consider for every node that the daimeter passes through it of the subtree below it, then its value is left_height + right_height
    // but then i have call height function for every node via traversing it

    // This is O(N) solution using the same approach
    int height(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left_height = height(root->left, maxi);
        int right_height = height(root->right, maxi);

        maxi = max(maxi, left_height + right_height);
        return (1 + max(left_height, right_height));
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        height(root, maxi);
        return maxi;
    }
};

int main()
{

    return 0;
}