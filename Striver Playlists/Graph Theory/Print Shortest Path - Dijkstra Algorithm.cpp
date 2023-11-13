#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // prepare a graph
        const int INF = 1e9 + 10;
        vector<pair<int, int>> graph[n + 1];

        for (int i = 0; i < m; i++)
        {
            int parent = edges[i][0];
            int child = edges[i][1];
            int dist = edges[i][2];

            graph[parent].push_back({child, dist});
            graph[child].push_back({parent, dist});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INF);
        vector<int> par(n + 1, -1);

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto child : graph[node])
            {
                int child_node = child.first;
                int child_dist = child.second;

                if (dist[child_node] > dis + child_dist)
                {
                    par[child_node] = node;
                    dist[child_node] = dis + child_dist;
                    pq.push({dist[child_node], child_node});
                }
            }
        }

        if (dist[n] == INF)
        {
            return {-1};
        }

        vector<int> ans;
        int node = n;

        while (node != 1)
        {
            ans.push_back(node);
            node = par[node];
        }

        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}