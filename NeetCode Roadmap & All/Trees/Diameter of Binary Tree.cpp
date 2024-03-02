#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we can use a recusive approach where the recusive function will return as the maxDepth from our
Left & right subtree , We add them and get the diameter with including the current node . Now we will return
the max of (leftdepth & rightdepth) + 1 . Finally we have the value of maxDiameter .
*/

class TreeNode
{
public:
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int val)
    {
        this->val = val;
    }
};

class Solution
{
protected:
    int maxDepth(TreeNode *root, int &diameter)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftMaxDepth = maxDepth(root->left, diameter);
        int rightMaxDepth = maxDepth(root->right, diameter);

        int currDiameter = leftMaxDepth + rightMaxDepth;
        diameter = max(currDiameter, diameter);

        int depth = max(leftMaxDepth, rightMaxDepth) + 1;
        return depth;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }
};

// TC : O(N) -- number of nodes
// SC : O(H) -- height of tree

int main()
{

    return 0;
}