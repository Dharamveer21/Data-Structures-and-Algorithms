#include <bits/stdc++.h>
using namespace std;

/*
if we remove any vertex from the graph then all the edges connected to that vertex will be removed
now even after that if the graph remian connected then it is not a articulation point

when i remove the node then the children of the node should be not be able to reach a node before it that means
lowest_time[child] >= time[node] && par != -1 -- which means it must not be a starting point

for starting point -- if it has more than one disconnected children then it is an articulation point
*/

class Solution
{
private:
    int timer = 0;

protected:
    void findArticulationPoint(int node, int parent, vector<bool> &vis, vector<bool> &markArticulationPoint, vector<int> &disc, vector<int> &low, vector<int> graph[])
    {
        vis[node] = true;
        disc[node] = low[node] = timer;
        timer++;

        int children = 0;

        for (int child : graph[node])
        {
            if (child == parent)
            {
                continue;
            }

            if (!vis[child])
            {
                findArticulationPoint(child, node, vis, markArticulationPoint, disc, low, graph);
                low[node] = min(low[node], low[child]);

                if (low[child] >= disc[node] && parent != -1)
                {
                    markArticulationPoint[node] = true;
                }

                children++;
            }

            else
            {
                low[node] = min(low[node], disc[child]);
            }
        }

        if (parent == -1 && children > 1)
        {
            markArticulationPoint[node] = true;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> disc(V, 0), low(V, 0);
        vector<bool> markArticulationPoint(V, false);
        vector<int> articulationPoints;

        findArticulationPoint(0, -1, vis, markArticulationPoint, disc, low, adj);

        for (int node = 0; node < V; node++)
        {
            if (markArticulationPoint[node] == true)
            {
                articulationPoints.push_back(node);
            }
        }

        if (articulationPoints.size() == 0)
        {
            return {-1};
        }

        return articulationPoints;
    }
};

int main()
{

    return 0;
}
