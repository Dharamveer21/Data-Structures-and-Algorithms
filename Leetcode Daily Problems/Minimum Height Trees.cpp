#include <bits/stdc++.h>
using namespace std;

// BFS & Topological Sort
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};

        vector<int> indegree(n);
        queue<int> queueOfLeafNodes;

        vector<vector<int>> tree(n);
        int countOfProcessedNodes = n;
        vector<int> rootsWithMinimumTreeHeights;

        for (auto &edge : edges)
        {
            int vertex0 = edge[0];
            int vertex1 = edge[1];

            indegree[vertex0] += 1;
            indegree[vertex1] += 1;

            tree[vertex0].push_back(vertex1);
            tree[vertex1].push_back(vertex0);
        }

        for (int vertex = 0; vertex < n; vertex++)
        {
            if (indegree[vertex] == 1)
                queueOfLeafNodes.push(vertex);
        }

        while (countOfProcessedNodes > 2)
        {
            int size = queueOfLeafNodes.size();
            countOfProcessedNodes -= size;

            while (size--)
            {
                int vertex = queueOfLeafNodes.front();
                queueOfLeafNodes.pop();

                for (int &adjacentVertex : tree[vertex])
                {
                    indegree[adjacentVertex] -= 1;

                    if (indegree[adjacentVertex] == 1)
                        queueOfLeafNodes.push(adjacentVertex);
                }
            }
        }

        while (!queueOfLeafNodes.empty())
        {
            int root = queueOfLeafNodes.front();
            queueOfLeafNodes.pop();

            rootsWithMinimumTreeHeights.push_back(root);
        }

        return rootsWithMinimumTreeHeights;
    }
};

// TC : O(V + E)
// SC : O(V + E)

int main()
{

    return 0;
}