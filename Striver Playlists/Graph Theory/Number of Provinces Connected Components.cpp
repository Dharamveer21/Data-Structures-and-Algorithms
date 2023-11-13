#include <bits/stdc++.h>
using namespace std;

// using connected components
class Solution
{
public:
    void dfs(int vertex, vector<bool> &vis, vector<vector<int>> &matrix)
    {
        int vertices = matrix.size();
        vis[vertex] = true;

        for (int i = 0; i < vertices; i++)
        {
            if (matrix[vertex][i] == 1 && !vis[i])
            {
                dfs(i, vis, matrix);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int vertices = isConnected.size();
        vector<bool> vis(vertices, false);
        int provinces = 0;

        for (int i = 0; i < vertices; i++)
        {
            if (!vis[i])
            {
                provinces++;
                dfs(i, vis, isConnected);
            }
        }

        return provinces;
    }
};

int main()
{

    return 0;
}