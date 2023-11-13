#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool detect_cylcle_dfs(int node, vector<bool> &vis, vector<bool> &path_vis, vector<int> adj[])
    {
        vis[node] = true;
        path_vis[node] = true;

        for (int child : adj[node])
        {
            if (!vis[child])
            {
                if (detect_cylcle_dfs(child, vis, path_vis, adj))
                {
                    return true;
                }
            }

            else if (path_vis[child])
            {
                return true;
            }
        }
        
        path_vis[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<bool> path_vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect_cylcle_dfs(i, vis, path_vis, adj))
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