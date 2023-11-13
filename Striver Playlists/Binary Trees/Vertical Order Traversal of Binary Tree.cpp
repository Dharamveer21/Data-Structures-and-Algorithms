#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    void traversals(TreeNode *root, int hor_lev, int ver_lev, priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> &traversal)
    {
        if (root == NULL)
        {
            return;
        }

        traversal.push({ver_lev, {hor_lev, root->val}});
        traversals(root->left, hor_lev + 1, ver_lev - 1, traversal);
        traversals(root->right, hor_lev + 1, ver_lev + 1, traversal);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> vertical_traversal;
        vector<int> level_travs;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> traversal;

        traversals(root, 0, 0, traversal);

        if (traversal.size() == 0)
        {
            return vertical_traversal;
        }

        int level = traversal.top().first;

        while (!traversal.empty())
        {
            auto node_level = traversal.top();
            traversal.pop();

            int node = node_level.second.second;
            int vert_lev = node_level.first;

            if (vert_lev > level)
            {
                vertical_traversal.push_back(level_travs);
                level_travs.clear();
                level++;
            }

            level_travs.push_back(node);
        }

        vertical_traversal.push_back(level_travs);
        return vertical_traversal;
    }
};

int main()
{

    return 0;
}