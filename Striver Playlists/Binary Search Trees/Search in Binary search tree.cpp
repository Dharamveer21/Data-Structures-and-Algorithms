#include <bits/stdc++.h>
using namespace std;

/*using binary search*/

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
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (val > root->val)
        {
            return searchBST(root->right, val);
        }

        else if (val < root->val)
        {
            return searchBST(root->left, val);
        }

        return root;
    }
};

int main()
{

    return 0;
}