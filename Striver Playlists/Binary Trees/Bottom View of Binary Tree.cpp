#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> bottom_view;
        unordered_map<int, int> level_node;
        vector<pair<int, int>> bottom;

        if (root == NULL)
        {
            return bottom_view;
        }

        queue<pair<Node *, int>> nodes;
        nodes.push({root, 0});

        while (!nodes.empty())
        {
            auto node = nodes.front();
            nodes.pop();

            int node_val = node.first->data;
            int level = node.second;

            level_node[level] = node_val;

            if (node.first->left != NULL)
            {
                nodes.push({node.first->left, level - 1});
            }

            if (node.first->right != NULL)
            {
                nodes.push({node.first->right, level + 1});
            }
        }

        for (auto node : level_node)
        {
            int lev = node.first;
            int node_val = node.second;

            bottom.push_back({lev, node_val});
        }

        sort(bottom.begin(), bottom.end());

        for (int i = 0; i < bottom.size(); i++)
        {
            bottom_view.push_back(bottom[i].second);
        }

        return bottom_view;
    }
};

int main()
{

    return 0;
}