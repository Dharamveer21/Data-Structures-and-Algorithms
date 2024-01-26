#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a dynamic programming problem in the way that how many ways to reach boundary from the given
cell in given number of moves is equal to the number of ways of going out of from the four neighbours of cell
& the number of ways of going out from curr cell , so we can put it like this --

dp[move][row][col] = dp[move-1][row][col] + openBoundaryCount(row,col)

We need three functions :
1. isMovePossible -- to check we can move into that cell or not
2. openBoundaryCount -- to count open boundaries whenever we visited a cell
3. findPaths -- given function to call the functions & to caluclate tabulation
*/

class Solution
{
private:
    static const int M = 1e9 + 7;
    vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

protected:
    bool isMovePossible(int row, int col, pair<int, int> &ground)
    {
        int rows = ground.first;
        int cols = ground.second;

        return (row >= 0 && row < rows && col >= 0 && col < cols);
    }

    int openBoundaryCount(int row, int col, pair<int, int> &ground)
    {
        int count = 0;

        for (auto &moment : moments)
        {
            int childRow = row + moment.first;
            int childCol = col + moment.second;

            count += (isMovePossible(childRow, childCol, ground) == false);
        }

        return count;
    }

public:
    // tabulation
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int rows = m, cols = n;
        pair<int, int> ground = {rows, cols};
        vector<vector<vector<int>>> paths(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));

        for (int moves = 1; moves <= maxMove; moves++)
        {
            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    int totalPaths = openBoundaryCount(row, col, ground);

                    for (auto &moment : moments)
                    {
                        int childRow = row + moment.first;
                        int childCol = col + moment.second;

                        if (isMovePossible(childRow, childCol, ground))
                        {
                            totalPaths = (totalPaths + 0LL + paths[moves - 1][childRow][childCol]) % M;
                        }
                    }

                    paths[moves][row][col] = totalPaths;
                }
            }
        }

        int totalOutPaths = paths[maxMove][startRow][startColumn];
        return totalOutPaths;
    }

    // space optimization
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int rows = m, cols = n;
        pair<int, int> ground = {rows, cols};

        vector<vector<int>> prevPaths(m, vector<int>(n, 0));
        vector<vector<int>> currPaths(m, vector<int>(n, 0));

        for (int moves = 1; moves <= maxMove; moves++)
        {
            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    int totalPaths = openBoundaryCount(row, col, ground);

                    for (auto &moment : moments)
                    {
                        int childRow = row + moment.first;
                        int childCol = col + moment.second;

                        if (isMovePossible(childRow, childCol, ground))
                        {
                            totalPaths = (totalPaths + 0LL + prevPaths[childRow][childCol]) % M;
                        }
                    }

                    currPaths[row][col] = totalPaths;
                }
            }

            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    prevPaths[row][col] = currPaths[row][col];
                }
            }
        }

        int totalOutPaths = currPaths[startRow][startColumn];
        return totalOutPaths;
    }
};

// TC : O(M * N * maxMoves)
// SC : O(M * N)

int main()
{

    return 0;
}