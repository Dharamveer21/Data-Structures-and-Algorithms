#include <bits/stdc++.h>
using namespace std;

/*at any ind the no. of sqaures end end at it*/

class Solution
{
public:
    // tabulation
    int countSquares(vector<vector<int>> &matrix)
    {
        int rows = matrix.size() + 1;
        int cols = matrix[0].size() + 1;

        vector<vector<int>> squares(rows, vector<int>(cols, 0));
        int total_squares = 0;

        for (int row = 1; row < rows; row++)
        {
            for (int col = 1; col < cols; col++)
            {
                if (matrix[row - 1][col - 1] == 0)
                {
                    continue;
                }

                squares[row][col] = min(squares[row - 1][col - 1], min(squares[row - 1][col], squares[row][col - 1])) + 1;
                total_squares += squares[row][col];
            }
        }

        return total_squares;
    }

    // space optimization
    int countSquares(vector<vector<int>> &matrix)
    {
        int rows = matrix.size() + 1;
        int cols = matrix[0].size() + 1;

        vector<int> curr_squares(cols, 0);
        vector<int> prev_squares(cols, 0);
        int total_squares = 0;

        for (int row = 1; row < rows; row++)
        {
            for (int col = 1; col < cols; col++)
            {
                if (matrix[row - 1][col - 1] == 0)
                {
                    curr_squares[col] = 0;
                    continue;
                }

                curr_squares[col] = min(prev_squares[col - 1], min(prev_squares[col], curr_squares[col - 1])) + 1;
                total_squares += curr_squares[col];
            }
            
            for (int col = 0; col < cols; col++)
            {
                prev_squares[col] = curr_squares[col];
            }
        }

        return total_squares;
    }
};

int main()
{

    return 0;
}