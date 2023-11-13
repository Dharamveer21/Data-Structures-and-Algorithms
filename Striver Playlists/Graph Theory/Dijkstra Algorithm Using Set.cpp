#include <bits/stdc++.h>
using namespace std;

// using set
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        const int INF = 1e9 + 10;
        set<pair<int, int>> pq;
        vector<int> dist(V, INF);

        dist[S] = 0;
        pq.insert({0, S});

        while (!pq.empty())
        {
            auto it = pq.begin();

            int dis = it->first;
            int node = it->second;
            pq.erase(it);

            for (auto child : adj[node])
            {
                int child_dist = child[1];
                int child_node = child[0];

                if (dist[child_node] > child_dist + dis)
                {
                    if (dist[child_node] != INF)
                    {
                        pq.erase({dist[child_node], child_node});
                    }

                    dist[child_node] = child_dist + dis;
                    pq.insert({dist[child_node], child_node});
                }
            }
        }

        return dist;
    }
};

int main()
{

    return 0;
}