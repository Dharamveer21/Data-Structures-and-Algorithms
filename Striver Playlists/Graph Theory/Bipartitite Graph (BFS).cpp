#include <bits/stdc++.h>
using namespace std;

// bfs for finding all the nearest neighbours

class Solution
{
public:
    bool isbipartite(int source, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &color)
    {
        queue<pair<int, int>> q;
        q.push({source, -1});
        vis[source] = true;
        color[source] = true;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            int ver = node.first;
            int par = node.second;

            for (auto child : graph[ver])
            {
                if (!vis[child])
                {
                    vis[child] = true;
                    color[child] = !color[ver];
                    q.push({child, ver});
                }

                else if ((child != par) && (color[ver] == color[child]))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<bool> vis(graph.size(), false);
        vector<bool> color(graph.size(), false);

        for (int node = 0; node < graph.size(); node++)
        {
            if (!vis[node])
            {
                if (!isbipartite(node, graph, vis, color))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}