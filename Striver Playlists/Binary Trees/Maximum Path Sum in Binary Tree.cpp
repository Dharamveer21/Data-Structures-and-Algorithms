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

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.A node can only appear in the sequence at most once.Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.

class Solution
{
public:
    // O(N) -- use kadane algo that if path_sum is neg take it 0
    // use logic as same for daimeter -- assume path passes through that node for tree below it

    int max_path(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left_path_sum = max(max_path(root->left, maxi), 0);
        int right_path_sum = max(max_path(root->right, maxi), 0);

        int path = left_path_sum + right_path_sum + root->val;
        maxi = max(maxi, path); // if we consider that node as root node

        return (root->val + max(left_path_sum, right_path_sum)); // we consider that node as a part of tree & can only take either left path or roght path
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        max_path(root, maxi);
        return maxi;
    }
};

int main()
{

    return 0;
}