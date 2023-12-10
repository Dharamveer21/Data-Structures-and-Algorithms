#include <bits/stdc++.h>
using namespace std;

/*
Approach -- any element at [row][col] will be at [col][row] in new matrix
In case of square matrix we just need a swapping operation for upper triangular matrix with lower one
*/

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> transposedMatrix(cols, vector<int>(rows));

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                transposedMatrix[col][row] = matrix[row][col];
            }
        }

        return transposedMatrix;
    }
};

// TC : O(M*N)
// SC : O(M*N)

int main()
{

    return 0;
}