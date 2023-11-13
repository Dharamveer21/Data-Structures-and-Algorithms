#include <bits/stdc++.h>
using namespace std;

// use bfs or dikstra without priority queue
class Solution
{
private:
    bool isvalid(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] == 1)
        {
            return false;
        }

        return true;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        const int INF = 1e9 + 10;
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, INF));
        vector<pair<int, int>> moments = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1)
        {
            return -1;
        }

        dist[0][0] = 1;
        q.push({0, 0});

        while (!q.empty())
        {
            auto node_dist = q.front();
            q.pop();

            int node_rows = node_dist.first;
            int node_cols = node_dist.second;
            int dis = dist[node_rows][node_cols];

            for (int i = 0; i < 8; i++)
            {
                int child_row = node_rows + moments[i].first;
                int child_col = node_cols + moments[i].second;

                if (isvalid(child_row, child_col, grid))
                {
                    if (dist[child_row][child_col] > (dis + 1))
                    {
                        dist[child_row][child_col] = dis + 1;
                        q.push({child_row, child_col});
                    }
                }
            }
        }
        
        if (dist[rows - 1][cols - 1] == INF)
        {
            return -1;
        }

        return dist[rows - 1][cols - 1];
    }
};

int main()
{

    return 0;
}