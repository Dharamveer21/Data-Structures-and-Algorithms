#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int minPath(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &path)
    {
        if (path[row][col] != 1e4 + 1)
        {
            return path[row][col];
        }

        if (col <= row)
        {
            int up_same = INT_MAX, up_left = INT_MAX;

            if (col != row)
            {
                up_same = minPath(row - 1, col, triangle, path);
            }

            if (col > 0)
            {
                up_left = minPath(row - 1, col - 1, triangle, path);
            }

            int min_path = min(up_same, up_left) + triangle[row][col];
            return path[row][col] = min_path;
        }

        int min_path = INT_MAX;

        for (int i = 0; i <= row; i++)
        {
            min_path = min(min_path, minPath(row, i, triangle, path));
        }

        return path[row][col] = min_path;
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> path;

        for (int row = 0; row < triangle.size(); row++)
        {
            vector<int> curr_row;

            for (int col = 0; col <= row + 1; col++)
            {
                int num = 1e4 + 1;
                curr_row.push_back(num);
            }

            path.push_back(curr_row);
        }

        path[0][0] = triangle[0][0];
        path[0][1] = triangle[0][0];

        return minPath(triangle.size() - 1, triangle.size(), triangle, path);
    }

    // tabulation
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> path;

        for (int row = 0; row < triangle.size(); row++)
        {
            vector<int> curr_row;

            for (int col = 0; col <= row + 1; col++)
            {
                int num = 1e4 + 1;
                curr_row.push_back(num);
            }

            path.push_back(curr_row);
        }

        path[0][0] = triangle[0][0];
        path[0][1] = triangle[0][0];

        for (int row = 1; row < triangle.size(); row++)
        {
            for (int col = 0; col <= row + 1; col++)
            {
                if (col <= row)
                {
                    int up_same = INT_MAX, up_left = INT_MAX;

                    if (col != row)
                    {
                        up_same = path[row - 1][col];
                    }

                    if (col > 0)
                    {
                        up_left = path[row - 1][col - 1];
                    }

                    int min_path = min(up_same, up_left) + triangle[row][col];
                    path[row][col] = min_path;
                    continue;
                }

                int min_path = INT_MAX;

                for (int i = 0; i <= row; i++)
                {
                    min_path = min(min_path, path[row][i]);
                }

                path[row][col] = min_path;
            }
        }

        return path[triangle.size() - 1][triangle.size()];
    }

    // space optimization
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<int> curr_path(triangle.size() + 1);
        vector<int> prev_path(triangle.size() + 1);

        curr_path[0] = prev_path[0] = triangle[0][0];
        curr_path[1] = prev_path[1] = triangle[0][0];

        for (int row = 1; row < triangle.size(); row++)
        {
            for (int col = 0; col <= row + 1; col++)
            {
                if (col <= row)
                {
                    int up_same = INT_MAX, up_left = INT_MAX;

                    if (col != row)
                    {
                        up_same = prev_path[col];
                    }

                    if (col > 0)
                    {
                        up_left = prev_path[col - 1];
                    }

                    int min_path = min(up_same, up_left) + triangle[row][col];
                    curr_path[col] = min_path;
                }

                else
                {
                    int min_path = INT_MAX;

                    for (int i = 0; i <= row; i++)
                    {
                        min_path = min(min_path, curr_path[i]);
                    }

                    curr_path[col] = min_path;
                }
            }

            for (int col = 0; col <= row + 1; col++)
            {
                prev_path[col] = curr_path[col];
            }
        }

        return curr_path[triangle.size()];
    }
};

int main()
{

    return 0;
}