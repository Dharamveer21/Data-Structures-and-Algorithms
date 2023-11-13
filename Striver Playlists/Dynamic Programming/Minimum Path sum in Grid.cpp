#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int minPath(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &path_sum)
    {
        if (path_sum[row][col] != -1)
        {
            return path_sum[row][col];
        }
        
        int up = INT_MAX, left = INT_MAX, min_path;

        if (row > 0)
        {
            up = minPath(row - 1, col, grid, path_sum);
        }

        if (col > 0)
        {
            left = minPath(row, col - 1, grid, path_sum);
        }

        min_path = min(up, left) + grid[row][col];
        return path_sum[row][col] = min_path;
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> path_sum(rows, vector<int>(cols, -1));
        path_sum[0][0] = grid[0][0];

        return minPath(rows - 1, cols - 1, grid, path_sum);
    }

    // tabulation
    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> path_sum(rows, vector<int>(cols, -1));

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (row == 0 && col == 0)
                {
                    path_sum[0][0] = grid[0][0];
                    continue;
                }

                int up = INT_MAX, left = INT_MAX, min_path;

                if (row > 0)
                {
                    up = path_sum[row - 1][col];
                }

                if (col > 0)
                {
                    left = path_sum[row][col - 1];
                }

                min_path = min(up, left) + grid[row][col];
                path_sum[row][col] = min_path;
            }
        }

        return path_sum[rows - 1][cols - 1];
    }

    // space optimization
    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> curr_row(cols, 0), prev_row(cols, 0);
    
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (row == 0 && col == 0)
                {
                    curr_row[0] = grid[0][0];
                    continue;
                }
    
                int up = INT_MAX, left = INT_MAX, min_path;
    
                if (row > 0)
                {
                    up = prev_row[col];
                }

                if (col > 0)
                {
                    left = curr_row[col - 1];
                }

                min_path = min(up, left) + grid[row][col];
                curr_row[col] = min_path;
            }

            for (int col = 0; col < cols; col++)
            {
                prev_row[col] = curr_row[col];
            }
        }

        return curr_row[cols - 1];
    }
};

int main()
{

    return 0;
}