#include <bits/stdc++.h>
using namespace std;

/*prepare a graph by comparing adjacent edges & then apply topological sort*/
/*topological sort also works for parallel edges*/

class Solution
{
private:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        vector<int> ans;
        queue<int> topo_sort;

        for (int node = 0; node < V; node++)
        {
            for (int child : adj[node])
            {
                indegree[child]++;
            }
        }

        for (int node = 0; node < V; node++)
        {
            if (indegree[node] == 0)
            {
                topo_sort.push(node);
            }
        }

        while (!topo_sort.empty())
        {
            int node = topo_sort.front();
            topo_sort.pop();

            ans.push_back(node);

            for (int child : adj[node])
            {
                indegree[child]--;

                if (indegree[child] == 0)
                {
                    topo_sort.push(child);
                }
            }
        }

        return ans;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> graph[K];

        for (int i = 1; i < N; i++)
        {
            string &str1 = dict[i - 1];
            string &str2 = dict[i];

            int len = min(str1.size(), str2.size());

            for (int j = 0; j < len; j++)
            {
                if (str1[j] != str2[j])
                {
                    int v1 = str1[j] - 'a';
                    int v2 = str2[j] - 'a';

                    graph[v1].push_back(v2);
                    break;
                }
            }
        }

        string ans;
        vector<int> value = topoSort(K, graph);

        for (int i = 0; i < K; i++)
        {
            char ch = value[i] + 'a';
            ans.push_back(ch);
        }

        return ans;
    }
};

int main()
{

    return 0;
}