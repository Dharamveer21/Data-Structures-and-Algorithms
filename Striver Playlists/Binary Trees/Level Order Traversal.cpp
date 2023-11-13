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

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        int level = 1;
        queue<pair<TreeNode *, int>> q;
        vector<vector<int>> traversal;
        vector<int> level_traversal;

        if (root == NULL)
        {
            return traversal;
        }

        q.push({root, 1});

        while (!q.empty())
        {
            auto value = q.front();
            q.pop();

            TreeNode *node = value.first;
            int lev = value.second;

            if (lev == level + 1)
            {
                level++;
                traversal.push_back(level_traversal);
                level_traversal.clear();
            }
             
            level_traversal.push_back(node->val);

            if (node->left != NULL)
            {
                q.push({node->left, lev + 1});
            }

            if (node->right != NULL)
            {
                q.push({node->right, lev + 1});
            }
        }

        traversal.push_back(level_traversal);
        return traversal;
    }
};

int main()
{

    return 0;
}