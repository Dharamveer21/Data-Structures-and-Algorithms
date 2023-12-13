#include <bits/stdc++.h>
using namespace std;

/*
Approach -- store the count of '1' for each row & each col so that we can use it latter in O(1)
then iterate over the network if we find any cell with '1' we check its row & column count & check
*/

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);
        int specialNum = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                int num = mat[row][col];

                if (num == 1)
                {
                    int rowIndex = row;
                    int colIndex = col;

                    rowCount[rowIndex]++;
                    colCount[colIndex]++;
                }
            }
        }

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                int num = mat[row][col];

                if (num == 1)
                {
                    int rowIndex = row;
                    int colIndex = col;

                    if (rowCount[rowIndex] == 1 && colCount[colIndex] == 1)
                    {
                        specialNum++;
                    }
                }
            }
        }

        return specialNum;
    }
};

// TC: O(M * N)
// SC: O(M + N)

int main()
{

    return 0;
}