#include<bits/stdc++.h>
using namespace std;

// using priority queue
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        const int INF = 1e9 + 10;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INF);

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto child : adj[node])
            {
                int child_dist = child[1];
                int child_node = child[0];

                if (dist[child_node] > child_dist + dis)
                {
                    dist[child_node] = child_dist + dis;
                    pq.push({dist[child_node], child_node});
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