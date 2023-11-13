#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int unique_paths(int row, int col, vector<vector<int>> &obstacleGrid, vector<vector<int>> &paths)
    {
        // base case
        if (paths[row][col] != -1)
        {
            return paths[row][col];
        }

        if (obstacleGrid[row][col] == 1)
        {
            return paths[row][col] = 0;
        }

        int left = 0, up = 0, total = 0;

        if (row > 0)
        {
            up = unique_paths(row - 1, col, obstacleGrid, paths);
        }

        if (col > 0)
        {
            left = unique_paths(row, col - 1, obstacleGrid, paths);
        }

        total = up + left;
        return paths[row][col] = total;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> paths(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        paths[0][0] = 1 - obstacleGrid[0][0];
        return unique_paths(obstacleGrid.size() - 1, obstacleGrid[0].size() - 1, obstacleGrid, paths);
    }

    // tabulation
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> paths(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));

        for (int row = 0; row < obstacleGrid.size(); row++)
        {
            for (int col = 0; col < obstacleGrid[0].size(); col++)
            {
                if (row == 0 && col == 0)
                {
                    paths[0][0] = 1 - obstacleGrid[0][0];
                    continue;
                }

                if (obstacleGrid[row][col] == 1)
                {
                    paths[row][col] = 0;
                    continue;
                }

                int left = 0, up = 0, total = 0;

                if (row > 0)
                {
                    up = paths[row - 1][col];
                }

                if (col > 0)
                {
                    left = paths[row][col - 1];
                }

                total = up + left;
                paths[row][col] = total;
            }
        }

        return paths[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }

    // space optimization
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<int> curr_row(obstacleGrid[0].size(), 1 - obstacleGrid[0][0]), prev_row(obstacleGrid[0].size(), 1 - obstacleGrid[0][0]);

        for (int row = 0; row < obstacleGrid.size(); row++)
        {
            for (int col = 0; col < obstacleGrid[0].size(); col++)
            {
                if (row == 0 && col == 0)
                {
                    curr_row[0] = 1 - obstacleGrid[0][0];
                    continue;
                }

                if (obstacleGrid[row][col] == 1)
                {
                    curr_row[col] = 0;
                    continue;
                }

                int left = 0, up = 0, total = 0;

                if (row > 0)
                {
                    up = prev_row[col];
                }

                if (col > 0)
                {
                    left = curr_row[col - 1];
                }

                total = up + left;
                curr_row[col] = total;
            }

            for (int col = 0; col < obstacleGrid[0].size(); col++)
            {
                prev_row[col] = curr_row[col];
            }
        }

        return curr_row[obstacleGrid[0].size() - 1];
    }
};

int main()
{

    return 0;
}