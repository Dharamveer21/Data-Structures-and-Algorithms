#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int falling_path(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &path)
    {
        int n = matrix.size();

        if (path[row][col] != 101)
        {
            return path[row][col];
        }

        if (col < n)
        {
            int mini_path;
            int up = INT_MAX, up_left = INT_MAX, up_right = INT_MAX;

            if (col > 0)
            {
                up_left = falling_path(row - 1, col - 1, matrix, path);
            }

            up = falling_path(row - 1, col, matrix, path);

            if (col < n - 1)
            {
                up_right = falling_path(row - 1, col + 1, matrix, path);
            }

            mini_path = min(up, min(up_left, up_right)) + matrix[row][col];
            return path[row][col] = mini_path;
        }

        int mini_path = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            mini_path = min(mini_path, falling_path(row, i, matrix, path));
        }

        return path[row][col] = mini_path;
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> path(n, vector<int>(n + 1, 101));

        int mini_path = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            path[0][i] = matrix[0][i];
            mini_path = min(mini_path, matrix[0][i]);
        }

        path[0][n] = mini_path;

        return falling_path(n - 1, n, matrix, path);
    }

    // tabulation
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> path(n, vector<int>(n + 1, 101));

        int mini_path = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            path[0][i] = matrix[0][i];
            mini_path = min(mini_path, matrix[0][i]);
        }

        path[0][n] = mini_path;

        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col <= n; col++)
            {
                if (col < n)
                {
                    int mini_path;
                    int up = INT_MAX, up_left = INT_MAX, up_right = INT_MAX;

                    if (col > 0)
                    {
                        up_left = path[row - 1][col - 1];
                    }

                    up = path[row - 1][col];

                    if (col < n - 1)
                    {
                        up_right = path[row - 1][col + 1];
                    }

                    mini_path = min(up, min(up_left, up_right)) + matrix[row][col];
                    path[row][col] = mini_path;
                }

                else
                {
                    int mini_path = INT_MAX;

                    for (int i = 0; i < n; i++)
                    {
                        mini_path = min(mini_path, path[row][i]);
                    }

                    path[row][col] = mini_path;
                }
            }
        }

        return path[n - 1][n];
    }

    // space optimization
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> prev_path(n + 1, 101);
        vector<int> curr_path(n + 1, 101);

        int mini_path = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            prev_path[i] = curr_path[i] = matrix[0][i];
            mini_path = min(mini_path, matrix[0][i]);
        }

        prev_path[n] = curr_path[n] = mini_path;

        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col <= n; col++)
            {
                if (col < n)
                {
                    int mini_path;
                    int up = INT_MAX, up_left = INT_MAX, up_right = INT_MAX;

                    if (col > 0)
                    {
                        up_left = prev_path[col - 1];
                    }

                    up = prev_path[col];

                    if (col < n - 1)
                    {
                        up_right = prev_path[col + 1];
                    }

                    mini_path = min(up, min(up_left, up_right)) + matrix[row][col];
                    curr_path[col] = mini_path;
                }

                else
                {
                    int mini_path = INT_MAX;

                    for (int i = 0; i < n; i++)
                    {
                        mini_path = min(mini_path, curr_path[i]);
                    }

                    curr_path[col] = mini_path;
                }
            }

            for (int col = 0; col <= n; col++)
            {
                prev_path[col] = curr_path[col];
            }
        }

        return curr_path[n];
    }
};

int main()
{

    return 0;
}