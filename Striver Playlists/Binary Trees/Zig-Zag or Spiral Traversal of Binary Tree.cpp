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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        int level = 1;
        vector<vector<int>> traversal;
        vector<int> level_traversal;

        if (root == NULL)
        {
            return traversal;
        }

        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});

        while (!q.empty())
        {
            auto node_val = q.front();
            q.pop();

            TreeNode *node = node_val.first;
            int lev = node_val.second;

            if (lev > level)
            {
                if ((level & 1) == 0)
                {
                    reverse(level_traversal.begin(), level_traversal.end());
                }

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

        if ((level & 1) == 0)
        {
            reverse(level_traversal.begin(), level_traversal.end());
        }

        traversal.push_back(level_traversal);
        return traversal;
    }
};

int main()
{
    return 0;
}