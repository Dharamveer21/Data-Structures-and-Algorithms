#include <bits/stdc++.h>
using namespace std;

// Depth First Search
class Solution
{
protected:
    bool traversingTheGraph(int node, vector<vector<int>> &graph, vector<bool> &visited, int &destination)
    {
        if (node == destination)
            return true;

        if (visited[node] == true)
            return false;

        visited[node] = true;

        for (int child : graph[node])
        {
            if (traversingTheGraph(child, graph, visited, destination))
                return true;
        }

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);

        for (auto &edge : edges)
        {
            int vertex0 = edge[0];
            int vertex1 = edge[1];

            graph[vertex0].push_back(vertex1);
            graph[vertex1].push_back(vertex0);
        }

        bool isPathExists = traversingTheGraph(source, graph, visited, destination);
        return isPathExists;
    }
};

// TC : O(V + E)
// SC : O(V + E)

// Breadth First Search
class Solution
{
protected:
    bool traversingTheGraph(int source, int destination, vector<vector<int>> &graph, vector<bool> &visited)
    {
        queue<int> queueOfNodes;
        queueOfNodes.push(source);
        visited[source] = true;

        while (!queueOfNodes.empty())
        {
            int node = queueOfNodes.front();
            queueOfNodes.pop();

            if (node == destination)
                return true;

            for (int child : graph[node])
            {
                if (!visited[child])
                {
                    queueOfNodes.push(child);
                    visited[child] = true;
                }
            }
        }

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);

        for (auto &edge : edges)
        {
            int vertex0 = edge[0];
            int vertex1 = edge[1];

            graph[vertex0].push_back(vertex1);
            graph[vertex1].push_back(vertex0);
        }

        bool isPathExists = traversingTheGraph(source, destination, graph, visited);
        return isPathExists;
    }
};

// TC : O(V + E)
// SC : O(V + E)

int main()
{

    return 0;
}