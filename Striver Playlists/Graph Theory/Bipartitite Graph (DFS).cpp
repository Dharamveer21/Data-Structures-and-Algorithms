#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isbipartite(int source, int parent, int colour, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &color)
    {
        vis[source] = true;
        color[source] = colour;

        for (auto child : graph[source])
        {
            if (!vis[child])
            {
                if (!isbipartite(child, source, !colour, graph, vis, color))
                {
                    return false;
                }
            }

            else if ((child != parent) && (color[child] == colour))
            {
                return false;
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
                if (!isbipartite(node, -1, true, graph, vis, color))
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