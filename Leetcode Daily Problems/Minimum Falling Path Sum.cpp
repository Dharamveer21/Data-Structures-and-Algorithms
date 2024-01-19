#include <bits/stdc++.h>
using namespace std;

/*
Approach -- find the minimum Path sum for any 'row' then on its basis we can calculate for 'row - 1'
*/

class Solution
{
protected:
    bool isValidMoment(int row, int col, int rows, int cols)
    {
        return (row >= 0 && row < rows && col >= 0 && col < cols);
    }

public:
    // tabulation
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int minFallingPath = INT_MAX;
        vector<pair<int, int>> moments = {{1, -1}, {1, 0}, {1, 1}};

        for (int row = rows - 1; row >= 0; row--)
        {
            for (int col = 0; col < cols; col++)
            {
                int minPath = INT_MAX;

                for (auto &moment : moments)
                {
                    int newRow = row + moment.first;
                    int newCol = col + moment.second;

                    if (isValidMoment(newRow, newCol, rows, cols))
                    {
                        minPath = min(minPath, matrix[newRow][newCol]);
                    }
                }

                matrix[row][col] = matrix[row][col] + (minPath == INT_MAX ? 0 : minPath);
            }
        }

        for (int col = 0; col < cols; col++)
        {
            minFallingPath = min(minFallingPath, matrix[0][col]);
        }

        return minFallingPath;
    }
};

// TC : O(M * N + N) = O(M * N)
// SC : O(N)

int main()
{

    return 0;
}