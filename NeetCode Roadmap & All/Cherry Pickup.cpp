#include <bits/stdc++.h>
using namespace std;

/*
we don't need backtracking in these type of problems of simultaneous movers because
on any cell either both movers come together or only one of them comes over it
it will never be happen that one of the movers reach a cell first & other mover reach at that cell after first mover
*/

class Solution
{
public:
    // memoisation
    int cherrys[51][51][51];
    int MaxCherry(int row1, int col1, int row2, int col2, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int max_cherry = -2500;

        if (row1 < 0 || row2 < 0 || col1 < 0 || col2 < 0 || row1 > n - 1 || row2 > n - 1 || col1 > n - 1 || col2 > n - 1 || grid[row1][col1] == -1 || grid[row2][col2] == -1)
        {
            return max_cherry;
        }

        if (cherrys[row1][col1][row2] != -1)
        {
            return cherrys[row1][col1][row2];
        }

        int cherry = ((row1 == row2 && col1 == col2) ? (grid[row1][col1]) : (grid[row1][col1] + grid[row2][col2]));

        int down_down = MaxCherry(row1 + 1, col1, row2 + 1, col2, grid);
        int right_right = MaxCherry(row1, col1 + 1, row2, col2 + 1, grid);
        int right_down = MaxCherry(row1, col1 + 1, row2 + 1, col2, grid);
        int down_right = MaxCherry(row1 + 1, col1, row2, col2 + 1, grid);

        max_cherry = max(max_cherry, max(max(down_down, right_right), max(down_right, right_down))) + cherry;
        return cherrys[row1][col1][row2] = max_cherry;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        memset(cherrys, -1, sizeof(cherrys));
        cherrys[n - 1][n - 1][n - 1] = grid[n - 1][n - 1];
        int ans = MaxCherry(0, 0, 0, 0, grid);
        return (ans > 0 ? ans : 0);
    }

    // tabulation
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int cherrys[n][n][n];
        cherrys[n - 1][n - 1][n - 1] = grid[n - 1][n - 1];

        for (int row1 = n - 1; row1 >= 0; row1--)
        {
            for (int col1 = n - 1; col1 >= 0; col1--)
            {
                for (int row2 = n - 1; row2 >= 0; row2--)
                {
                    int col2 = row1 + col1 - row2;
                    int max_cherry = -2500;

                    if (col2 > n - 1 || col2 < 0 || (row1 == n - 1 && col1 == n - 1))
                    {
                        continue;
                    }

                    if (grid[row1][col1] == -1 || grid[row2][col2] == -1)
                    {
                        cherrys[row1][col1][row2] = max_cherry;
                        continue;
                    }

                    int cherry = ((row1 == row2 && col1 == col2) ? (grid[row1][col1]) : (grid[row1][col1] + grid[row2][col2]));

                    int down_down = (row1 == n - 1 || row2 == n - 1) ? max_cherry : cherrys[row1 + 1][col1][row2 + 1];
                    int right_right = (col1 == n - 1 || col2 == n - 1) ? max_cherry : cherrys[row1][col1 + 1][row2];
                    int right_down = (col1 == n - 1 || row2 == n - 1) ? max_cherry : cherrys[row1][col1 + 1][row2 + 1];
                    int down_right = (row1 == n - 1 || col2 == n - 1) ? max_cherry : cherrys[row1 + 1][col1][row2];

                    max_cherry = max(max(down_down, right_right), max(down_right, right_down)) + cherry;
                    cherrys[row1][col1][row2] = max_cherry;
                }
            }
        }

        int ans = cherrys[0][0][0];
        return (ans > 0 ? ans : 0);
    }
};

int main()
{

    return 0;
}