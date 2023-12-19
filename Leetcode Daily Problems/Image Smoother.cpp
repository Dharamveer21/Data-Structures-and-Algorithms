#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- Take a new ans array and find the average for each element & store it in the array
for traversing the neighbours store the all possible neighbours in an array and then traverse over it

Approach 2 -- We can optmise the space by updating the existing array but keeping the information of the
previous row and use it to update the values by calculating the average
*/

class Solution
{
public:
    // Approach 1
    bool isValid(int row, int col, int &rows, int &cols)
    {
        return (row >= 0 && col >= 0 && row < rows && col < cols);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        vector<pair<int, int>> moments = {{0, 0},{0, 1},{0, -1},{-1, 0},{1, 0},{-1, -1},{-1, 1},{1, -1},{1, 1},};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                float momentSum = 0, momentCount = 0;
                int numRow = row, numCol = col;

                for (auto moment : moments)
                {
                    int currRow = numRow + moment.first;
                    int currCol = numCol + moment.second;

                    if (isValid(currRow, currCol, rows, cols))
                    {
                        momentSum += img[currRow][currCol];
                        momentCount++;
                    }
                }

                int avgValue = (momentSum / momentCount);
                ans[numRow][numCol] = floor(avgValue);
            }
        }

        return ans;
    }

    // Approach 2
    bool isValid(int row, int col, int &rows, int &cols)
    {
        return (row >= 0 && col >= 0 && row < rows && col < cols);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int rows = img.size();
        int cols = img[0].size();
        int prevCorner = 0;
        vector<int> prevRow(cols);
        vector<pair<int, int>> moments = {{0, 0},{0, 1},{0, -1},{-1, 0},{1, 0},{-1, -1},{-1, 1},{1, -1},{1, 1},};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                float momentSum = 0, momentCount = 0;
                int numRow = row, numCol = col;

                for (auto moment : moments)
                {
                    int currRow = numRow + moment.first;
                    int currCol = numCol + moment.second;

                    if (isValid(currRow, currCol, rows, cols))
                    {
                        momentCount++;

                        if ((currRow > numRow) || (currRow == numRow && currCol >= numCol))
                        {
                            momentSum += img[currRow][currCol];
                            continue;
                        }

                        if ((currRow == numRow) && (currCol < numCol))
                        {
                            momentSum += prevCorner;
                            continue;
                        }

                        momentSum += prevRow[currCol];
                    }
                }

                prevCorner = (row == 0) ? img[numRow][numCol] : prevRow[numCol];
                prevRow[numCol] = img[numRow][numCol];

                int avgValue = (momentSum / momentCount);
                img[numRow][numCol] = floor(avgValue);
            }
        }

        return img;
    }
};

// TC : O(M * N * 9) = O(M * N)
// SC : O(N + 1) = O(N)

int main()
{

    return 0;
}