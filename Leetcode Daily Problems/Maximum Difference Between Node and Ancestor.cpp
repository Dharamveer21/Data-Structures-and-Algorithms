#include <bits/stdc++.h>
using namespace std;

/*
Approach -- The maximum value of the Ancestor Difference is difference of the current node from the maximum &
minimum value of the left & right subtree of that node , find the max & min from both subtree minmax values

Then the diff of our node value & min , max values is the required values
find maximum from those values , it is the required answer
*/

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
protected:
    pair<int, int> minmaxNode(TreeNode *root, TreeNode *par, int &maxAncDiff)
    {
        if (root == NULL)
        {
            return {par->val, par->val};
        }

        pair<int, int> minmaxLeft = minmaxNode(root->left, root, maxAncDiff);
        pair<int, int> minmaxRight = minmaxNode(root->right, root, maxAncDiff);

        int value = root->val;
        int minVal = min(minmaxLeft.first, minmaxRight.first);
        int maxVal = max(minmaxLeft.second, minmaxRight.second);

        maxAncDiff = max(maxAncDiff, max(abs(value - minVal), abs(value - maxVal)));
        return {min(minVal, value), max(maxVal, value)};
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        int maxAncDiff = 0;
        minmaxNode(root, NULL, maxAncDiff);
        return maxAncDiff;
    }
};

// TC : O(N) -- traversal of whole tree
// SC : O(N) -- stack space

int main()
{

    return 0;
}