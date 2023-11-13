#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*reverse the graph and apply topological sort*/
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> rev_graph[graph.size()];
        vector<int> indegree(graph.size(), 0);
        vector<int> ans;
        queue<int> q;

        for (int node = 0; node < graph.size(); node++)
        {
            for (int child : graph[node])
            {
                rev_graph[child].push_back(node);
            }
        }

        for (int node = 0; node < graph.size(); node++)
        {
            for (int child : rev_graph[node])
            {
                indegree[child]++;
            }
        }

        for (int node = 0; node < graph.size(); node++)
        {
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int child : rev_graph[node])
            {
                indegree[child]--;

                if (indegree[child] == 0)
                {
                    q.push(child);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}