#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        vector<bool> vis(V, false);
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
            vis[node] = true;
            topo_sort.pop();

            for (int child : adj[node])
            {
                indegree[child]--;

                if (indegree[child] == 0)
                {
                    topo_sort.push(child);
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}