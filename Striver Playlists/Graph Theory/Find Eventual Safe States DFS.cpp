#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // using DFS
    bool find_safe_dfs(int node, vector<bool> &safe_nodes, vector<bool> &vis, vector<bool> &path_vis, vector<vector<int>> &graph)
    {
        vis[node] = true;
        path_vis[node] = true;

        for (int child : graph[node])
        {
            if (!vis[child])
            {
                if (!find_safe_dfs(child, safe_nodes, vis, path_vis, graph))
                {
                    return false;
                }
            }

            else if (path_vis[child])
            {
                return false;
            }
        }

        safe_nodes[node] = true;
        path_vis[node] = false;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<bool> vis(graph.size(), false);
        vector<bool> path_vis(graph.size(), false);
        vector<bool> is_safe(graph.size(), false);
        vector<int> safe_nodes;

        for (int node = 0; node < graph.size(); node++)
        {
            if (!vis[node])
            {
                find_safe_dfs(node, is_safe, vis, path_vis, graph);
            }
        }

        for (int node = 0; node < graph.size(); node++)
        {
            if (is_safe[node])
            {
                safe_nodes.push_back(node);
            }
        }

        return safe_nodes;
    }
};

int main()
{

    return 0;
}