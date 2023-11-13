#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // DFS Function to return list containing vertices in Topological order.
    void dfs(int node, stack<int> &topo_sort, vector<bool> &vis, vector<int> graph[])
    {
        vis[node] = true;

        for (int child : graph[node])
        {
            if (!vis[child])
            {
                dfs(child, topo_sort, vis, graph);
            }
        }

        topo_sort.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> ans;
        stack<int> topo_sort;

        for (int node = 0; node < V; node++)
        {
            if (!vis[node])
            {
                dfs(node, topo_sort, vis, adj);
            }
        }

        while (!topo_sort.empty())
        {
            int node = topo_sort.top();
            topo_sort.pop();
            ans.push_back(node);
        }

        return ans;
    }

    // BFS Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        vector<int> ans;
        queue<int> topo_sort;

        for (int node = 0; node < V; node++)
        {
            for (int child : adj[node])
            {
                indegree[child]++;
            }
        }

        for (int node = 0; node < V; node++)
        {
            if (indegree[node] == 0)
            {
                topo_sort.push(node);
            }
        }

        while (!topo_sort.empty())
        {
            int node = topo_sort.front();
            topo_sort.pop();

            ans.push_back(node);

            for (int child : adj[node])
            {
                indegree[child]--;

                if (indegree[child] == 0)
                {
                    topo_sort.push(child);
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}