#include <bits/stdc++.h>
using namespace std;

/*To find MST for any graph*/
/*A priority Queue & a vis array*/
/*Greedy -- find minimum edge each time*/
/*The simple intution is that if the whole tree will be minimum spanning tree then the first node will be connected to the tree via minimum edge to remain the part of MST*/
/*we store the parent to find the edge which is going to be the part of algorithm*/

// E * log(E)

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // also find the mst
        int span_tree = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<bool> vis(V, false);
        vector<pair<pair<int, int>, int>> mst;

        pq.push({0, {0, -1}});

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second.first;
            int par = it.second.second;
            
            if (vis[node])
            {
                continue;
            }

            vis[node] = true;
            span_tree += wt;
             
            if (par != -1)
            {
                mst.push_back({{par, node}, wt});
                mst.push_back({{node, par}, wt});
            }
            
            for (auto child : adj[node])
            {
                int child_node = child[0];
                int child_wt = child[1];

                if (!vis[child_node])
                {
                    pq.push({child_wt, {child_node, node}});
                }
            }
        }

        return span_tree;
    }
};

int main()
{

    return 0;
}