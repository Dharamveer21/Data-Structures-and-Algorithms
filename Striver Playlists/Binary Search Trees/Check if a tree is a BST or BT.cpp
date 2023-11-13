#include <bits/stdc++.h>
using namespace std;

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

// set a min , max range for every node via recusion
class Solution
{
public:
    bool is_valid(TreeNode *root, pair<long long, long long> range)
    {
        if (root == NULL)
        {
            return true;
        }

        long long num = root->val;

        if (num <= range.first || num >= range.second)
        {
            return false;
        }

        return (is_valid(root->left, {range.first, num}) && is_valid(root->right, {num, range.second}));
    }

    bool isValidBST(TreeNode *root)
    {
        return is_valid(root, {LLONG_MIN, LLONG_MAX});
    }
};

int main()
{

    return 0;
}