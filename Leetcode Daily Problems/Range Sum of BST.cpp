#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Traverse the tree & check the value in the given range & find the sum of such values
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
    int isPresentInRange(TreeNode *node, int low, int high)
    {
        int val = node->val;
        return ((low <= val && val <= high) ? val : 0);
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int rangeSum = 0;
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                rangeSum += isPresentInRange(curr, low, high);
                curr = curr->right;
            }

            else
            {
                TreeNode *prev = curr->left;

                while (prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }

                else
                {
                    rangeSum += isPresentInRange(curr, low, high);
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return rangeSum;
    }
};

// TC : O(N) -- traversal of the whole tree
// SC : O(1) -- by morris traversal

int main()
{

    return 0;
}