#include <bits/stdc++.h>
using namespace std;

/*any node can reach in less time than now is to feel that the node is removed*/
/*we just check if that node can be visited by anyone before its own time which is par_time + 1*/
/*if yes then this edge is not a bridge*/

class Solution
{
private:
    int timer = 1;

    void dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &graph, vector<vector<int>> &bridges, vector<int> &time, vector<int> &lowest_time)
    {
        vis[node] = true;
        time[node] = lowest_time[node] = timer;
        timer++;

        for (int child : graph[node])
        {
            if (child == parent)
            {
                continue;
            }

            if (!vis[child])
            {
                dfs(child, node, vis, graph, bridges, time, lowest_time);
                lowest_time[node] = min(lowest_time[child], lowest_time[node]);

                if (time[node] < lowest_time[child]) // That means there is no other way to reach that node -- its a bridge
                {
                    bridges.push_back({child, node});
                }
            }

            else
            {
                lowest_time[node] = min(lowest_time[child], lowest_time[node]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n);
        vector<vector<int>> bridges;
        vector<int> time(n, 0);
        vector<int> lowest_time(n, 0);

        for (auto it : connections)
        {
            int v1 = it[0];
            int v2 = it[1];

            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        dfs(0, -1, vis, graph, bridges, time, lowest_time);
        return bridges;
    }
};

int main()
{

    return 0;
}