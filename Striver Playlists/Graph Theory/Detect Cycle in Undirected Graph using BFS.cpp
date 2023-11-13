#include <bits/stdc++.h>
using namespace std;

// always solve for multiple components
// SC : O(N) + O(N)
// TC : O(N + 2E)

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool detect_cycle(int src, vector<int> adj[], vector<bool> &vis)
    {
        queue<pair<int, int>> q;

        q.push({src, -1});
        vis[src] = true;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            int ver = node.first;
            int par = node.second;

            for (auto child : adj[ver])
            {
                if (!vis[child])
                {
                    q.push({child, ver});
                    vis[child] = true;
                }

                else if (child != par)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect_cycle(i, adj, vis))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}