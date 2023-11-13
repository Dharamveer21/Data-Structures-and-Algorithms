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
    TreeNode *build_tree(int start_in, int end_in, int start_post, int end_post, vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &location)
    {
        if ((start_in > end_in) || (start_post > end_post))
        {
            return NULL;
        }

        int root_val = postorder[end_post];
        TreeNode *root = new TreeNode(root_val);

        int loca = location[root_val];
        int left_post_end = loca - start_in + start_post - 1;

        root->left = build_tree(start_in, loca - 1, start_post, left_post_end, inorder, postorder, location);
        root->right = build_tree(loca + 1, end_in, left_post_end + 1, end_post - 1, inorder, postorder, location);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        unordered_map<int, int> location;

        for (int i = 0; i < n; i++)
        {
            int num = inorder[i];
            location[num] = i;
        }

        TreeNode *root = build_tree(0, n - 1, 0, n - 1, inorder, postorder, location);
        return root;
    }
};

int main()
{

    return 0;
}