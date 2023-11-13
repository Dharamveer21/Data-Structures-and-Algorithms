#include <bits/stdc++.h>
using namespace std;

// Find the parents of each node
// then find bfs from target node then find the level of each node -- the last level is minimum time to burn the tree

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    // store the parent of each node
    void findparent(Node *root, Node *par, int target, Node *&start, unordered_map<Node *, Node *> &parent, unordered_map<Node *, bool> &vis)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->data == target)
        {
            start = root;
        }

        parent[root] = par;
        vis[root] = false;

        findparent(root->left, root, target, start, parent, vis);
        findparent(root->right, root, target, start, parent, vis);
    }

public:
    int minTime(Node *root, int target)
    {
        Node *start = NULL;
        unordered_map<Node *, Node *> par;
        unordered_map<Node *, bool> vis;

        findparent(root, NULL, target, start, par, vis);
        int min_time = 0;

        // use multi source bsf
        queue<pair<Node *, int>> q;
        q.push({start, 0});
        vis[start] = true;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int time = it.second;

            min_time = time;

            if (node->left != NULL && !vis[node->left])
            {
                vis[node->left] = true;
                q.push({node->left, time + 1});
            }

            if (node->right != NULL && !vis[node->right])
            {
                vis[node->right] = true;
                q.push({node->right, time + 1});
            }

            if (par[node] != NULL && !vis[par[node]])
            {
                vis[par[node]] = true;
                q.push({par[node], time + 1});
            }
        }

        return min_time;
    }
};

int main()
{

    return 0;
}