#include <bits/stdc++.h>
using namespace std;

// search the depth first and then other children
// space complexity -- O(2N) + O(N) recursion stack space
// time complexity -- O(N) + O(2 * Edges)

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(int vertex, vector<int> adj[], vector<int> &dfs, vector<bool> &vis)
    {
        dfs.push_back(vertex);
        vis[vertex] = true;

        for (int child : adj[vertex])
        {
            if (!vis[child])
            {
                DFS(child, adj, dfs, vis);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> dfs;
        vector<bool> vis(V, false);

        DFS(0, adj, dfs, vis);
        return dfs;
    }
};

int main()
{

    return 0;
}