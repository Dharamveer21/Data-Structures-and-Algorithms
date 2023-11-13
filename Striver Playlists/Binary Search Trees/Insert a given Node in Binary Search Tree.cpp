#include <bits/stdc++.h>
using namespace std;

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return (new TreeNode(val));
        }

        TreeNode *curr = root;

        while (true)
        {
            int num = curr->val;

            if (val < num)
            {
                if (curr->left == NULL)
                {
                    curr->left = new TreeNode(val);
                    break;
                }

                curr = curr->left;
            }

            if (val > num)
            {
                if (curr->right == NULL)
                {
                    curr->right = new TreeNode(val);
                    break;
                }

                curr = curr->right;
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}