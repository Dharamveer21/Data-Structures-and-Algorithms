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
    TreeNode *build_tree(int start_in, int end_in, int start_pre, int end_pre, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &location)
    {
        if ((start_in > end_in) || (start_pre > end_pre))
        {
            return NULL;
        }

        int root_val = preorder[start_pre];
        TreeNode *root = new TreeNode(root_val);

        int loca = location[root_val];
        int left_pre_end = start_pre + loca - start_in;

        root->left = build_tree(start_in, loca - 1, start_pre + 1, left_pre_end, preorder, inorder, location);
        root->right = build_tree(loca + 1, end_in, left_pre_end + 1, end_pre, preorder, inorder, location);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        unordered_map<int, int> location;

        for (int i = 0; i < n; i++)
        {
            int num = inorder[i];
            location[num] = i;
        }

        TreeNode *root = build_tree(0, n - 1, 0, n - 1, preorder, inorder, location);
        return root;
    }
};

int main()
{

    return 0;
}