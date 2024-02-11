#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a DP Problem where we can make a function f(row1,col1,row2,col2) which will give us the
maximum cherrys that the two robots can collect . Now both have 9 possible ways to move & we will explore
each way & get the maximum of all of these ways . This was the simple recursive function . After that we will
memoise it using 3D array as row1 == row2 always so we can use a row .Then tabulation & space optimization .
*/

class Solution
{
protected:
    bool isMomentValid(int col1, int col2, int cols)
    {
        return (col1 >= 0 && col1 < cols && col2 >= 0 && col2 < cols);
    }

    // memoisation
    int maxCherryPickedUp(int row, int col1, int col2, vector<vector<int>> &grid, int maxCherrys[][70][70])
    {
        int rows = grid.size(), cols = grid[0].size();
        int newRow = row + 1, maxCherrysCollected = 0;

        if (row == rows)
        {
            return maxCherrysCollected;
        }

        if (maxCherrys[row][col1][col2] != -1)
        {
            return maxCherrys[row][col1][col2];
        }

        for (int newCol1 = col1 - 1; newCol1 < col1 + 2; newCol1++)
        {
            for (int newCol2 = col2 - 1; newCol2 < col2 + 2; newCol2++)
            {
                if (isMomentValid(newCol1, newCol2, cols))
                {
                    int cherrysCollected = maxCherryPickedUp(newRow, newCol1, newCol2, grid, maxCherrys);
                    maxCherrysCollected = max(maxCherrysCollected, cherrysCollected);
                }
            }
        }

        int currCherrys = ((col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2]);
        maxCherrysCollected = maxCherrysCollected + currCherrys;

        return maxCherrys[row][col1][col2] = maxCherrysCollected;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int maxCherrys[70][70][70];
        memset(maxCherrys, -1, sizeof(maxCherrys));

        int rows = grid.size(), cols = grid[0].size();
        int maxCherrysCollected = maxCherryPickedUp(0, 0, cols - 1, grid, maxCherrys);

        return maxCherrysCollected;
    }

    // tabulation
    int cherryPickup(vector<vector<int>> &grid)
    {
        int maxCherrys[71][70][70];
        memset(maxCherrys, 0, sizeof(maxCherrys));
        int rows = grid.size(), cols = grid[0].size();

        for (int row = rows - 1; row >= 0; row--)
        {
            for (int col1 = 0; col1 < min(row + 1, cols); col1++)
            {
                for (int col2 = cols - 1; col2 >= max(0, cols - row - 1); col2--)
                {
                    int newRow = row + 1, maxCherrysCollected = 0;

                    for (int newCol1 = col1 - 1; newCol1 < col1 + 2; newCol1++)
                    {
                        for (int newCol2 = col2 - 1; newCol2 < col2 + 2; newCol2++)
                        {
                            if (isMomentValid(newCol1, newCol2, cols))
                            {
                                int cherrysCollected = maxCherrys[newRow][newCol1][newCol2];
                                maxCherrysCollected = max(maxCherrysCollected, cherrysCollected);
                            }
                        }
                    }

                    int currCherrys = ((col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2]);
                    maxCherrysCollected = maxCherrysCollected + currCherrys;

                    maxCherrys[row][col1][col2] = maxCherrysCollected;
                }
            }
        }

        int maxCherrysCollected = maxCherrys[0][0][cols - 1];
        return maxCherrysCollected;
    }

    // space optimisation
    int cherryPickup(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int currMaxCherrys[70][70], nextMaxCherrys[70][70];
        memset(nextMaxCherrys, 0, sizeof(nextMaxCherrys));

        for (int row = rows - 1; row >= 0; row--)
        {
            for (int col1 = 0; col1 < min(row + 1, cols); col1++)
            {
                for (int col2 = cols - 1; col2 >= max(0, cols - row - 1); col2--)
                {
                    int maxCherrysCollected = 0;

                    for (int newCol1 = col1 - 1; newCol1 < col1 + 2; newCol1++)
                    {
                        for (int newCol2 = col2 - 1; newCol2 < col2 + 2; newCol2++)
                        {
                            if (isMomentValid(newCol1, newCol2, cols))
                            {
                                int cherrysCollected = nextMaxCherrys[newCol1][newCol2];
                                maxCherrysCollected = max(maxCherrysCollected, cherrysCollected);
                            }
                        }
                    }

                    int currCherrys = ((col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2]);
                    maxCherrysCollected = maxCherrysCollected + currCherrys;

                    currMaxCherrys[col1][col2] = maxCherrysCollected;
                }
            }

            for (int col1 = 0; col1 < min(row + 1, cols); col1++)
            {
                for (int col2 = cols - 1; col2 >= max(0, cols - row - 1); col2--)
                {
                    nextMaxCherrys[col1][col2] = currMaxCherrys[col1][col2];
                }
            }
        }

        int maxCherrysCollected = currMaxCherrys[0][cols - 1];
        return maxCherrysCollected;
    }
};

// TC : O(rows * cols^2 * 9)
// SC : O(cols^2)

int main()
{

    return 0;
}