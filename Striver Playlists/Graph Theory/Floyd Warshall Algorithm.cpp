#include <bits/stdc++.h>
using namespace std;

/*Multi souce shortest path algorithm*/
/*It can handle negative weights*/
/*can detect negative cycle*/

/*It is a DP algorithm which says travel via all nodes*/

/*
To detect the negative cycle -- we just have to check whether if there is any node which has distance to itself is less than zero
*/

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = rows;
        const int INF = 1e8 + 10;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (matrix[row][col] == -1)
                {
                    matrix[row][col] = INF;
                }
            }
        }

        for (int via = 0; via < rows; via++)
        {
            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    matrix[row][col] = min(matrix[row][col], matrix[row][via] + matrix[via][col]);
                }
            }
        }
    }
};

int main()
{

    return 0;
}