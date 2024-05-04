#include <bits/stdc++.h>
using namespace std;

/* Approach
here we need to find the path which breaks minimum walls
so we will use a priority queue to firstly traverse the path which brakes minimum walls
when we reach first the wall it means we reach there by breaking the minimum walls
we return at that moment & find the minimum obs needed to reach the destination
*/

class Solution
{
public:
    bool is_valid(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols)
        {
            return false;
        }

        return true;
    }

    int minimumObstacles(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        const int INF = 1e9 + 10;

        vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, INF));

        q.push({(grid[0][0] == 1), {0, 0}});
        dist[0][0] = 0;

        while (!q.empty())
        {
            auto node = q.top();
            q.pop();

            int obs = node.first;
            int row = node.second.first;
            int col = node.second.second;
            int dis = dist[row][col];

            if (row == rows - 1 && col == cols - 1)
            {
                return obs;
            }

            for (auto &moment : moments)
            {
                int child_row = row + moment.first;
                int child_col = col + moment.second;

                if (is_valid(child_row, child_col, grid))
                {
                    int child_dist = dist[child_row][child_col];

                    if (child_dist > dis + 1)
                    {
                        if ((grid[child_row][child_col] == 1))
                        {
                            dist[child_row][child_col] = dis + 1;
                            q.push({obs + 1, {child_row, child_col}});
                        }

                        else if (grid[child_row][child_col] == 0)
                        {
                            dist[child_row][child_col] = dis + 1;
                            q.push({obs, {child_row, child_col}});
                        }
                    }
                }
            }
        }

        return (rows + cols - 1);
    }
};

/*
Approach -- 2

here are only two values of each node 0 or 1 , so we can use 0-1 BFS and find the shortest level we can assign to the destination cell
*/

class Solution
{
public:
    bool is_valid(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols)
        {
            return false;
        }

        return true;
    }
    
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        const int INF = 1e9 + 10;

        vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        vector<vector<int>> dist(rows, vector<int>(cols, INF));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[0][0] = grid[0][0];
        int mini_obs = (rows + cols - 1);

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;
            int dis = dist[row][col];

            for (auto &moment : moments)
            {
                int child_row = row + moment.first;
                int child_col = col + moment.second;

                if (is_valid(child_row, child_col, grid))
                {
                    int child_dist = dist[child_row][child_col];

                    if (child_dist > dis + grid[child_row][child_col])
                    {
                        dist[child_row][child_col] = dis + grid[child_row][child_col];
                        q.push({child_row, child_col});
                    }
                }
            }
        }
        
        return dist[rows - 1][cols - 1];
    }
};

int main()
{

    return 0;
}