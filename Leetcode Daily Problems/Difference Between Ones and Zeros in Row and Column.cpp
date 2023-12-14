#include <bits/stdc++.h>
using namespace std;

/*
Approach -- store the ones in each row & each col first and then calculate diff for each row & col and put it in matrix
*/

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> rowsCount1(rows, 0);
        vector<int> colsCount1(cols, 0);

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                int num = grid[row][col];
                int rowIndex = row;
                int colIndex = col;

                if (num == 1)
                {
                    rowsCount1[rowIndex]++;
                    colsCount1[colIndex]++;
                    continue;
                }
            }
        }

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                int rowIndex = row;
                int colIndex = col;

                int onesRow = rowsCount1[row];
                int onesCol = colsCount1[col];

                int zerosRow = cols - onesRow;
                int zerosCol = rows - onesCol;

                int diff = ((onesRow + onesCol) - (zerosRow + zerosCol));
                grid[row][col] = diff;
            }
        }

        return grid;
    }
};

// TC : O(N * M)
// TC : O(N + M)

int main()
{

    return 0;
}