#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_path_valid(int row, int col, int reach_time, vector<vector<int>> &fire_time, vector<vector<int>> &vis)
    {
        int rows = fire_time.size();
        int cols = fire_time[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || vis[row][col] == 1)
        {
            return false;
        }

        if (fire_time[row][col] == -1)
        {
            return true;
        }
        
        if (row == rows - 1 && col == cols - 1)
        {
            return (fire_time[row][col] >= reach_time);
        }
        
        return (fire_time[row][col] > reach_time);
    }
    
    int min_wait_path(int row, int col, int reach_time, vector<vector<int>> &fire_time, vector<pair<int, int>> &moment, vector<vector<int>> &vis)
    {
        const int INF = 1e9;
        int rows = fire_time.size();
        int cols = fire_time[0].size();
        int fire = fire_time[row][col];
        vis[row][col] = 1;
        
        if (row == rows - 1 && col == cols - 1)
        {
            vis[row][col] = 0;
            return ((fire_time[row][col] == -1) ? INF : fire - reach_time);
        }

        int wait = ((fire_time[row][col] == -1) ? INF : fire - reach_time - 1);
        int max_wait_time = -1;

        for (int i = 0; i < 4; i++)
        {
            int child_x = row + moment[i].first;
            int child_y = col + moment[i].second;

            if (is_path_valid(child_x, child_y, reach_time + 1, fire_time, vis))
            {
                vis[row][col] = 1;
                int wait_time = min_wait_path(child_x, child_y, reach_time + 1, fire_time, moment, vis);
                max_wait_time = max(max_wait_time, wait_time);
                vis[row][col] = 0;
            }
        }

        if (max_wait_time == -1)
        {
            return -1;
        }

        return min(max_wait_time, wait);
    }
    
    bool is_valid(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] != 0)
        {
            return false;
        }

        return true;
    }

    int maximumMinutes(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<pair<int, int>> moment = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> fire_time(rows, vector<int>(cols, -1));

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                {
                    q.push({{row, col}, 0});
                    fire_time[row][col] = 0;
                }

                if (grid[row][col] == 2)
                {
                    fire_time[row][col] = 0;
                }
            }
        }

        while (!q.empty())
        {
            pair<pair<int, int>, int> node = q.front();
            q.pop();

            int par_x = node.first.first;
            int par_y = node.first.second;
            int par_fire_time = node.second;

            for (int i = 0; i < 4; i++)
            {
                int child_x = par_x + moment[i].first;
                int child_y = par_y + moment[i].second;
                int child_fire_time = par_fire_time + 1;

                if (is_valid(child_x, child_y, grid))
                {
                    grid[child_x][child_y] = 1;
                    q.push({{child_x, child_y}, child_fire_time});
                    fire_time[child_x][child_y] = child_fire_time;
                }
            }
        }
        
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                grid[row][col] = 0;
            }
        }
        
        return min_wait_path(0, 0, 0, fire_time, moment, grid);
    }
};

int main()
{

    return 0;
}