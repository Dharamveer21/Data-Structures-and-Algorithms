#include <bits/stdc++.h>
using namespace std;

/*
Approach -- any node can reach in less time than now is to feel that the node is removed
we just check if that node can be visited by anyone before its own time which is par_time + 1
if yes then this edge is not a bridge
*/

class Solution
{
private:
    int timer = 0;

protected:
    void findBridges(int node, int parent, vector<bool> &vis, vector<int> &low, vector<int> &disc, vector<vector<int>> &bridges, vector<vector<int>> &graph)
    {
        vis[node] = true;
        disc[node] = low[node] = timer;
        timer++;

        for (int child : graph[node])
        {
            if (child == parent)
            {
                continue;
            }

            if (!vis[child])
            {
                findBridges(child, node, vis, low, disc, bridges, graph);
                low[node] = min(low[node], low[child]);

                if (low[child] > disc[node])
                {
                    bridges.push_back({node, child});
                }
            }

            else
            {
                low[node] = min(low[node], disc[child]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<bool> vis(n, false);
        vector<int> low(n, 0), disc(n, 0);
        vector<vector<int>> bridges, graph(n);

        for (int ind = 0; ind < connections.size(); ind++)
        {
            int node1 = connections[ind][0];
            int node2 = connections[ind][1];

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        findBridges(0, -1, vis, low, disc, bridges, graph);
        return bridges;
    }
};

int main()
{
    return 0;
}