#include <bits/stdc++.h>
using namespace std;

// Recursion & Memoisation
class Solution
{
protected:
    int minimumFallingPath(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &pathSum)
    {
        int rows = grid.size(), cols = grid[0].size();
        int minimumFallingPathSumCurrRowAndCol = grid[row][col];

        if (pathSum[row][col] != -20000)
            return pathSum[row][col];

        int nextRow = row + 1, nextCol = 0;
        int minimumFallingPathSumNextRow = INT_MAX;

        for (nextCol = 0; nextCol < cols; nextCol++)
        {
            if (nextCol == col)
                continue;

            int fallingPathSumFromNextRow = minimumFallingPath(nextRow, nextCol, grid, pathSum);
            minimumFallingPathSumNextRow = min(minimumFallingPathSumNextRow, fallingPathSumFromNextRow);
        }

        minimumFallingPathSumCurrRowAndCol += minimumFallingPathSumNextRow;
        return pathSum[row][col] = minimumFallingPathSumCurrRowAndCol;
    }

public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int firstRow = 0, minimumFallingPathSumFirstRow = INT_MAX;
        vector<vector<int>> pathSum(rows, vector<int>(cols, -20000));

        for (int col = 0; col < cols; col++)
            pathSum[rows - 1][col] = grid[rows - 1][col];

        for (int col = 0; col < cols; col++)
        {
            int fallinPathSumCurrRowAndCol = minimumFallingPath(firstRow, col, grid, pathSum);
            minimumFallingPathSumFirstRow = min(minimumFallingPathSumFirstRow, fallinPathSumCurrRowAndCol);
        }

        int minimumFallingPathSum = minimumFallingPathSumFirstRow;
        return minimumFallingPathSum;
    }
};

// TC : O(N * N * N)
// SC : O(N * N)

// Tabulation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> pathSum(rows + 1, vector<int>(cols));
        int firstRow = 0, minimumFallingPathSumFirstRow = INT_MAX;

        for (int col = 0; col < cols; col++)
            pathSum[rows - 1][col] = grid[rows - 1][col];

        for (int row = rows - 2; row >= 0; row--)
        {
            for (int col = 0; col < cols; col++)
            {
                int nextRow = row + 1, nextCol = 0;
                int minimumFallingPathSumNextRow = INT_MAX;
                int minimumFallingPathSumCurrRowAndCol = grid[row][col];

                for (nextCol = 0; nextCol < cols; nextCol++)
                {
                    if (nextCol == col)
                        continue;

                    int fallingPathSumFromNextRow = pathSum[nextRow][nextCol];
                    minimumFallingPathSumNextRow = min(minimumFallingPathSumNextRow, fallingPathSumFromNextRow);
                }

                minimumFallingPathSumCurrRowAndCol += minimumFallingPathSumNextRow;
                pathSum[row][col] = minimumFallingPathSumCurrRowAndCol;
            }
        }

        for (int col = 0; col < cols; col++)
            minimumFallingPathSumFirstRow = min(pathSum[firstRow][col], minimumFallingPathSumFirstRow);

        int minimumFallingPathSum = minimumFallingPathSumFirstRow;
        return minimumFallingPathSum;
    }
};

// TC : O(N * N * N)
// SC : O(N * N)

// Space Optimization
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int minimumFallingPathSumFirstRow = INT_MAX;
        int rows = grid.size(), cols = grid[0].size();
        vector<int> currPathSum(cols), nextPathSum(cols);

        for (int col = 0; col < cols; col++)
            nextPathSum[col] = currPathSum[col] = grid[rows - 1][col];

        for (int row = rows - 2; row >= 0; row--)
        {
            for (int col = 0; col < cols; col++)
            {
                int minimumFallingPathSumNextRow = INT_MAX;
                int minimumFallingPathSumCurrRowAndCol = grid[row][col];

                for (int nextCol = 0; nextCol < cols; nextCol++)
                {
                    if (nextCol == col)
                        continue;

                    int fallingPathSumFromNextRow = nextPathSum[nextCol];
                    minimumFallingPathSumNextRow = min(minimumFallingPathSumNextRow, fallingPathSumFromNextRow);
                }

                minimumFallingPathSumCurrRowAndCol += minimumFallingPathSumNextRow;
                currPathSum[col] = minimumFallingPathSumCurrRowAndCol;
            }

            for (int col = 0; col < cols; col++)
                nextPathSum[col] = currPathSum[col];
        }

        for (int col = 0; col < cols; col++)
            minimumFallingPathSumFirstRow = min(currPathSum[col], minimumFallingPathSumFirstRow);

        int minimumFallingPathSum = minimumFallingPathSumFirstRow;
        return minimumFallingPathSum;
    }
};

// TC : O(N * N * N)
// SC : O(N)

// Time Optimization
class Solution
{
protected:
    void findMin1AndMin2(pair<int, int> &nextMinCol1AndValue, pair<int, int> &nextMinCol2AndValue, vector<int> &currPathSum)
    {
        int cols = currPathSum.size();
        int nextMinCol1 = cols, nextMinVal1 = INT_MAX;
        int nextMinCol2 = cols, nextMinVal2 = INT_MAX;

        for (int col = 0; col < cols; col++)
        {
            int val = currPathSum[col];

            if (val < nextMinVal1)
            {
                nextMinVal2 = nextMinVal1, nextMinCol2 = nextMinCol1;
                nextMinCol1 = col, nextMinVal1 = val;
            }

            else if (val < nextMinVal2)
                nextMinVal2 = val, nextMinCol2 = col;
        }

        nextMinCol1AndValue.first = nextMinCol1, nextMinCol1AndValue.second = nextMinVal1;
        nextMinCol2AndValue.first = nextMinCol2, nextMinCol2AndValue.second = nextMinVal2;
    }

public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> currPathSum(cols);

        int minimumFallingPathSumFirstRow = INT_MAX;
        pair<int, int> nextMinCol1AndValue, nextMinCol2AndValue;

        for (int col = 0; col < cols; col++)
            currPathSum[col] = grid[rows - 1][col];

        for (int row = rows - 2; row >= 0; row--)
        {
            findMin1AndMin2(nextMinCol1AndValue, nextMinCol2AndValue, currPathSum);
            int nextMinCol1 = nextMinCol1AndValue.first, nextMinVal1 = nextMinCol1AndValue.second;
            int nextMinCol2 = nextMinCol2AndValue.first, nextMinVal2 = nextMinCol2AndValue.second;

            for (int col = 0; col < cols; col++)
            {
                int minimumFallingPathSumCurrRowAndCol = grid[row][col];

                if (col == nextMinCol1)
                    minimumFallingPathSumCurrRowAndCol += nextMinVal2;

                else
                    minimumFallingPathSumCurrRowAndCol += nextMinVal1;

                currPathSum[col] = minimumFallingPathSumCurrRowAndCol;
            }
        }

        for (int col = 0; col < cols; col++)
            minimumFallingPathSumFirstRow = min(currPathSum[col], minimumFallingPathSumFirstRow);

        int minimumFallingPathSum = minimumFallingPathSumFirstRow;
        return minimumFallingPathSum;
    }
};

// TC : O(N * N)
// SC : O(N)

// Constant Space
class Solution
{
protected:
    void findMin1AndMin2(pair<int, int> &nextMinCol1AndValue, pair<int, int> &nextMinCol2AndValue, vector<int> &currPathSum)
    {
        int cols = currPathSum.size();
        int nextMinCol1 = cols, nextMinVal1 = INT_MAX;
        int nextMinCol2 = cols, nextMinVal2 = INT_MAX;

        for (int col = 0; col < cols; col++)
        {
            int val = currPathSum[col];

            if (val < nextMinVal1)
            {
                nextMinVal2 = nextMinVal1, nextMinCol2 = nextMinCol1;
                nextMinCol1 = col, nextMinVal1 = val;
            }

            else if (val < nextMinVal2)
                nextMinVal2 = val, nextMinCol2 = col;
        }

        nextMinCol1AndValue.first = nextMinCol1, nextMinCol1AndValue.second = nextMinVal1;
        nextMinCol2AndValue.first = nextMinCol2, nextMinCol2AndValue.second = nextMinVal2;
    }

public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int minimumFallingPathSumFirstRow = INT_MAX;
        int rows = grid.size(), cols = grid[0].size();
        pair<int, int> nextMinCol1AndValue, nextMinCol2AndValue;

        for (int row = rows - 2; row >= 0; row--)
        {
            findMin1AndMin2(nextMinCol1AndValue, nextMinCol2AndValue, grid[row + 1]);
            int nextMinCol1 = nextMinCol1AndValue.first, nextMinVal1 = nextMinCol1AndValue.second;
            int nextMinCol2 = nextMinCol2AndValue.first, nextMinVal2 = nextMinCol2AndValue.second;

            for (int col = 0; col < cols; col++)
            {
                int minimumFallingPathSumCurrRowAndCol = grid[row][col];

                if (col == nextMinCol1)
                    minimumFallingPathSumCurrRowAndCol += nextMinVal2;

                else
                    minimumFallingPathSumCurrRowAndCol += nextMinVal1;

                grid[row][col] = minimumFallingPathSumCurrRowAndCol;
            }
        }

        for (int col = 0; col < cols; col++)
            minimumFallingPathSumFirstRow = min(grid[0][col], minimumFallingPathSumFirstRow);

        int minimumFallingPathSum = minimumFallingPathSumFirstRow;
        return minimumFallingPathSum;
    }
};

// TC : O(N * N)
// SC : O(1)

int main()
{

    return 0;
}