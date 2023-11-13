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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> top_view;
        set<int> levels;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> traversal;

        if (root == NULL)
        {
            return top_view;
        }

        queue<pair<Node *, int>> nodes;
        nodes.push({root, 0});

        while (!nodes.empty())
        {
            auto node = nodes.front();
            nodes.pop();

            int node_val = node.first->data;
            int level = node.second;

            if (levels.find(level) == levels.end())
            {
                traversal.push({level, node_val});
                levels.insert(level);
            }

            if (node.first->left != NULL)
            {
                nodes.push({node.first->left, level - 1});
            }

            if (node.first->right != NULL)
            {
                nodes.push({node.first->right, level + 1});
            }
        }

        while (!traversal.empty())
        {
            int node = traversal.top().second;
            traversal.pop();

            top_view.push_back(node);
        }

        return top_view;
    }
};

int main()
{

    return 0;
}