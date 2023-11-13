#include <bits/stdc++.h>
using namespace std;

// always solve for multiple components
// SC : O(N) + O(N)
// TC : O(N + 2E)

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int src, int par, vector<int> adj[], vector<bool> &vis)
    {
        vis[src] = true;

        for (int child : adj[src])
        {
            if (!vis[child])
            {
                vis[child] = true;

                if (dfs(child, src, adj, vis))
                {
                    return true;
                }
            }

            else if (child != par)
            {
                return true;
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
                if (dfs(i, -1, adj, vis))
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