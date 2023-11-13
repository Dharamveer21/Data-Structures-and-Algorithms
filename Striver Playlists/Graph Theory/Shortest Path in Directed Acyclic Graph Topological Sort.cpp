#include <bits/stdc++.h>
using namespace std;

/*topo sort is the method of arrangement of parents before children in directed acyclic graph*/
/*in this graph we can assign the weights to INF & then source weight to zero then compare the dist of the source node children & their children*/

class Solution
{
public:
    void TopoSort(int node, stack<int> &st, vector<pair<int, int>> graph[], vector<bool> &vis)
    {
        vis[node] = true;

        for (auto child_node : graph[node])
        {
            int child = child_node.first;

            if (!vis[child])
            {
                TopoSort(child, st, graph, vis);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        int src = 0;
        stack<int> st;
        vector<pair<int, int>> graph[N];
        vector<bool> vis(N, false);
        vector<int> dist(N, -1);

        for (int edge = 0; edge < M; edge++)
        {
            int par = edges[edge][0];
            int child = edges[edge][1];
            int weight = edges[edge][2];

            graph[par].push_back({child, weight});
        }

        for (int node = 0; node < N; node++)
        {
            if (!vis[node])
            {
                TopoSort(node, st, graph, vis);
            }
        }

        dist[src] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (dist[node] == -1)
            {
                continue;
            }

            for (auto child_node : graph[node])
            {
                int child = child_node.first;
                int weight = child_node.second;

                int distance = dist[node] + weight;

                if (dist[child] == -1 || distance < dist[child])
                {
                    dist[child] = distance;
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