#include <bits/stdc++.h>
using namespace std;

// The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself
// Normal solution is that when we use a two arrays to store the paths of the nodes while traversing them two times (one time for each) -- TC : O(N) + O(N) , SC : O(N) + O(N)
// Optimized approach would be if just check what my both child return not NULL that means i am the LCA

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *left_child = ((root->left == NULL) ? NULL : lowestCommonAncestor(root->left, p, q));
        TreeNode *right_child = ((root->right == NULL) ? NULL : lowestCommonAncestor(root->right, p, q));

        if (left_child == NULL)
        {
            return right_child;
        }

        if (right_child == NULL)
        {
            return left_child;
        }

        return root;
    }
};

int main()
{

    return 0;
}