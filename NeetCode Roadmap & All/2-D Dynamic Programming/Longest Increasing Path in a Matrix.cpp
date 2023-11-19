#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int increasing_path(int row, int col, vector<vector<int>> &matrix, vector<pair<int, int>> &movements, vector<vector<int>> &longest_increasing_path)
    {
        if (longest_increasing_path[row][col] != -1)
        {
            return longest_increasing_path[row][col];
        }

        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;
        int maxi = 1;

        for (int dir = 0; dir < 4; dir++)
        {
            int new_row = row + movements[dir].first;
            int new_col = col + movements[dir].second;

            if (new_row < 0 || new_row > rows || new_col < 0 || new_col > cols || matrix[new_row][new_col] <= matrix[row][col])
            {
                continue;
            }

            int path_len = 1 + increasing_path(new_row, new_col, matrix, movements, longest_increasing_path);
            maxi = max(maxi, path_len);
        }

        return longest_increasing_path[row][col] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<pair<int, int>> movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> longest_increasing_path(rows, vector<int>(cols, -1));
        int maxi = 1;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                int path_len = increasing_path(row, col, matrix, movements, longest_increasing_path);
                maxi = max(maxi, path_len);
            }
        }

        return maxi;
    }
};

int main()
{

    return 0;
}