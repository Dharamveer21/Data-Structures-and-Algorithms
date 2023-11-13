#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Left View
vector<int> leftView(Node *root)
{
    vector<int> left_view;

    if (root == NULL)
    {
        return left_view;
    }

    set<int> levels;
    queue<pair<Node *, int>> q;
    q.push({root, 1});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        Node *node = it.first;
        int lev = it.second;

        if (levels.find(lev) == levels.end())
        {
            left_view.push_back(node->data);
            levels.insert(lev);
        }

        if (node->left != NULL)
        {
            q.push({node->left, lev + 1});
        }

        if (node->right != NULL)
        {
            q.push({node->right, lev + 1});
        }
    }

    return left_view;
}

// Right View
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> right_view;

        if (root == NULL)
        {
            return right_view;
        }

        unordered_map<int, int> nodes;
        vector<pair<int, int>> levels;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode *node = it.first;
            int lev = it.second;

            nodes[lev] = node->val;

            if (node->left != NULL)
            {
                q.push({node->left, lev + 1});
            }

            if (node->right != NULL)
            {
                q.push({node->right, lev + 1});
            }
        }

        for (auto node : nodes)
        {
            int lev = node.first;
            int node_val = node.second;

            levels.push_back({lev, node_val});
        }

        sort(levels.begin(), levels.end());

        for (int i = 0; i < levels.size(); i++)
        {
            right_view.push_back(levels[i].second);
        }

        return right_view;
    }
};

int main()
{

    return 0;
}