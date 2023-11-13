#include <bits/stdc++.h>
using namespace std;

// level wise traversal
// store all children in a queue & then traverse

// space complexity -- O(3N)
// time complexity -- O(N) + O(2 * Edges)

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs;
        vector<bool> vis(V, false);
        queue<int> q;

        q.push(0);
        bfs.push_back(0);
        vis[0] = true;

        while (!q.empty())
        {
            int node = q.front();

            q.pop();
             
            for (int child : adj[node])
            {
                if (!vis[child])
                {
                    q.push(child);
                    bfs.push_back(child);
                    vis[child] = true;
                }
            }
        }

        return bfs;
    }
};

int main()
{

    return 0;
}