#include <bits/stdc++.h>
using namespace std;

/*Dijkstra fails for negative edge weights*/
/*It helps in detecting negative weight cycle*/
/*Exactly n-1 iterations -- because in one iteration distance of atleast one node gets updated*/
/*if we give nth relaxation & the distance array still updates then it must have negative cycle*/
/*For Directed Graphs convert them to directed graph by converting unirected edge with two edges with equal weight as the weight of the undirected edge*/

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        const int INF = 1e8;
        vector<int> dist(V, INF);

        dist[S] = 0;

        // N-1 iteration
        for (int i = 1; i < V; i++)
        {
            for (int i = 0; i < edges.size(); i++)
            {
                int ver1 = edges[i][0];
                int ver2 = edges[i][1];
                int wt = edges[i][2];

                int old_dist = dist[ver2];
                int new_dist = dist[ver1] + wt;

                if (new_dist < old_dist)
                {
                    dist[ver2] = new_dist;
                }
            }
        }

        // check of negative cycle
        for (int i = 0; i < edges.size(); i++)
        {
            int ver1 = edges[i][0];
            int ver2 = edges[i][1];
            int wt = edges[i][2];

            int old_dist = dist[ver2];
            int new_dist = dist[ver1] + wt;

            if (new_dist < old_dist)
            {
                return {-1};
            }
        }

        return dist;
    }
};

int main()
{

    return 0;
}