#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Store the parents of each node in a map & then we find do a bfs assignParents from the start node
In bfs the the level of last node visited is the time to spread the infection
*/

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

/*
Approach -- Store the parents of each node in a map & then we find do a bfs assignParents from the start node
In bfs the the level of last node visited is the time to spread the infection
*/

class Solution
{
protected:
    void assignParents(TreeNode *node, TreeNode *parent, unordered_map<TreeNode *, TreeNode *> &par, TreeNode *&source, int start)
    {
        if (node == NULL)
        {
            return;
        }

        if (node->val == start)
        {
            source = node;
        }

        par[node] = parent;
        assignParents(node->left, node, par, source, start);
        assignParents(node->right, node, par, source, start);
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        TreeNode *source;
        int minTime = 0;
        const int INF = 1e9 + 10;
        unordered_map<TreeNode *, int> time;
        unordered_map<TreeNode *, TreeNode *> par;

        assignParents(root, NULL, par, source, start);

        for (auto node : par)
        {
            time[node.first] = INF;
        }

        queue<TreeNode *> q;
        q.push(source);
        time[source] = 0;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left != NULL)
            {
                TreeNode *node = curr->left;

                int prevTime = time[node];
                int newTime = time[curr] + 1;

                if (newTime < prevTime)
                {
                    time[node] = newTime;
                    minTime = max(minTime, newTime);
                    q.push(node);
                }
            }

            if (curr->right != NULL)
            {
                TreeNode *node = curr->right;

                int prevTime = time[node];
                int newTime = time[curr] + 1;

                if (newTime < prevTime)
                {
                    time[node] = newTime;
                    minTime = max(minTime, newTime);
                    q.push(node);
                }
            }

            if (par[curr] != NULL)
            {
                TreeNode *node = par[curr];

                int prevTime = time[node];
                int newTime = time[curr] + 1;

                if (newTime < prevTime)
                {
                    time[node] = newTime;
                    minTime = max(minTime, newTime);
                    q.push(node);
                }
            }
        }

        return minTime;
    }
};

// TC : O(N + N) = O(N) -- traversal for storing parents & bfs
// SC : O(N + N) = O(N) -- store parents & time

int main()
{

    return 0;
}