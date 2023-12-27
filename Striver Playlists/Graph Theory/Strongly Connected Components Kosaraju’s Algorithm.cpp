#include <bits/stdc++.h>
using namespace std;

/*
the vis graph can be break into strongly connected components if the edges are reversed
it will not change anything in strong connected components but their neighbour SCC are not vis by them

The ans is the no of dfs calls by main function
*/

// we can easily find the connected components
// this algorithm is used to find the strongly connected components inside the connected components

// sort all vertices according to finshing time
// Reverse the graph
// Do a dfs

class Solution
{
private:
    void dfs(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &graph)
    {
        vis[node] = true;

        for (auto child : graph[node])
        {
            if (!vis[child])
            {
                dfs(child, vis, st, graph);
            }
        }

        st.push(node);
    }

    void strongly_connected(int node, vector<bool> &vis, vector<vector<int>> &graph)
    {
        vis[node] = true;

        for (auto child : graph[node])
        {
            if (!vis[child])
            {
                strongly_connected(child, vis, graph);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<bool> vis(V, false);
        stack<int> st;
        int str_cnt = 0;

        // arrange accoriding to finish time
        for (int node = 0; node < V; node++)
        {
            if (!vis[node])
            {
                dfs(node, vis, st, adj);
            }
        }

        // reverse the graph
        vector<vector<int>> graph;
        graph.resize(V);
        vector<bool> rev_vis(V, false);

        for (int node = 0; node < adj.size(); node++)
        {
            for (int child : adj[node])
            {
                graph[child].push_back(node);
            }
        }

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!rev_vis[node])
            {
                str_cnt++;
                strongly_connected(node, rev_vis, graph);
            }
        }

        return str_cnt;
    }
};

int main()
{

    return 0;
}