#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int unique_paths(int row, int col, vector<vector<int>> &paths)
    {
        if (paths[row][col] != -1)
        {
            return paths[row][col];
        }

        int up_paths = 0, left_paths = 0;

        if (row - 1 >= 0)
        {
            up_paths = unique_paths(row - 1, col, paths);
        }
        
        if (col - 1 >= 0)
        {
            left_paths = unique_paths(row, col - 1, paths);
        }

        int total_paths = up_paths + left_paths;

        return paths[row][col] = total_paths;
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> paths(m, vector<int>(n, -1));
        paths[0][0] = 1; // base case

        return unique_paths(m - 1, n - 1, paths);
    }

    // tabulation
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> paths(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row == 0 && col == 0)
                {
                    paths[0][0] = 1;
                    continue;
                }

                int up_paths = 0, left_paths = 0;

                if (row > 0)
                {
                    up_paths = paths[row - 1][col];
                }

                if (col > 0)
                {
                    left_paths = paths[row][col - 1];
                }

                int total_paths = up_paths + left_paths;
                paths[row][col] = total_paths;
            }
        }

        return paths[m - 1][n - 1];
    }

    // space optimization
    int uniquePaths(int m, int n)
    {
        vector<int> curr_row(n, 1), prev_row(n, 1);

        for (int row = 1; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int up_paths = 0, left_paths = 0;
                up_paths = prev_row[col];

                if (col > 0)
                {
                    left_paths = curr_row[col - 1];
                }

                int total_paths = up_paths + left_paths;
                curr_row[col] = total_paths;
            }

            for (int col = 0; col < n; col++)
            {
                prev_row[col] = curr_row[col];
            }
        }

        return curr_row[n - 1];
    }
};

int main()
{

    return 0;
}