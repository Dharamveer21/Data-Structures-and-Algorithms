#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_valid(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] == 0)
        {
            return false;
        }

        return true;
    }

    void dfs(int row, int col, vector<vector<int>> &grid, vector<pair<int, int>> &moments)
    {
        for (int i = 0; i < 4; i++)
        {
            int child_x = row + moments[i].first;
            int child_y = col + moments[i].second;

            if (is_valid(child_x, child_y, grid))
            {
                grid[child_x][child_y] = 0;
                dfs(child_x, child_y, grid, moments);
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;

        vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (int row = 0; row < rows; row++)
        {
            if (grid[row][0] == 1)
            {
                grid[row][0] = 0;
                dfs(row, 0, grid, moments);
            }

            if (grid[row][cols - 1] == 1)
            {
                grid[row][cols - 1] = 0;
                dfs(row, cols - 1, grid, moments);
            }
        }

        for (int col = 0; col < cols; col++)
        {
            if (grid[0][col] == 1)
            {
                grid[0][col] = 0;
                dfs(0, col, grid, moments);
            }

            if (grid[rows - 1][col] == 1)
            {
                grid[rows - 1][col] = 0;
                dfs(rows - 1, col, grid, moments);
            }
        }

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}