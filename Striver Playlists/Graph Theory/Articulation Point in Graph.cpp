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
    int timer = 1;
    void dfs(int node, int parent, vector<bool> &vis, vector<bool> &mark, vector<int> &time, vector<int> &lowest_time, vector<int> adj[])
    {
        int children = 0;
        vis[node] = true;
        time[node] = lowest_time[node] = timer;
        timer++;

        for (auto child : adj[node])
        {
            if (child == parent)
            {
                continue;
            }

            if (!vis[child])
            {
                dfs(child, node, vis, mark, time, lowest_time, adj);
                lowest_time[node] = min(lowest_time[node], lowest_time[child]);

                if (lowest_time[child] >= time[node] && parent != -1)
                {
                    mark[node] = true;
                }

                children++;
            }

            else
            {
                lowest_time[node] = min(lowest_time[node], time[child]); // because if that node is removed i can't reach anyone that have lowest time than it
            }
        }

        if (children > 1 && parent == -1)
        {
            mark[node] = true;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> time(V);
        vector<int> lowest_time(V);
        vector<bool> mark(V, false);
        vector<int> ans;

        for (int node = 0; node < V; node++)
        {
            if (!vis[node])
            {
                dfs(node, -1, vis, mark, time, lowest_time, adj);
            }
        }

        for (int node = 0; node < V; node++)
        {
            if (mark[node])
            {
                ans.push_back(node);
            }
        }

        if (ans.size() == 0)
        {
            return {-1};
        }

        return ans;
    }
};

int main()
{

    return 0;
}