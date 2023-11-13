#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int cherrys[70][70][70];

    int maxcherrys(int row, int col1, int col2, vector<vector<int>> &grid)
    {
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
        {
            return -1;
        }

        if (row == grid.size())
        {
            return 0;
        }

        if (cherrys[row][col1][col2] != -1)
        {
            return cherrys[row][col1][col2];
        }

        int max_cherrys = 0;

        for (int block1 = col1 - 1; block1 <= col1 + 1; block1++)
        {
            for (int block2 = col2 - 1; block2 <= col2 + 1; block2++)
            {
                max_cherrys = max(max_cherrys, maxcherrys(row + 1, block1, block2, grid));
            }
        }

        int cherry = (col1 == col2) ? (grid[row][col1]) : (grid[row][col1] + grid[row][col2]);
        max_cherrys += cherry;
        return cherrys[row][col1][col2] = max_cherrys;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        memset(cherrys, -1, sizeof(cherrys));
        int ans = maxcherrys(0, 0, grid[0].size() - 1, grid);
        return ans;
    }

    // tabulation
    int cherryPickup(vector<vector<int>> &grid)
    {
        int cherrys[grid.size()][grid[0].size()][grid[0].size()];

        for (int row = grid.size() - 1; row >= 0; row--)
        {
            for (int col1 = 0; col1 < grid[0].size(); col1++)
            {
                for (int col2 = 0; col2 < grid[0].size(); col2++)
                {
                    int cherry = (col1 == col2) ? (grid[row][col1]) : (grid[row][col1] + grid[row][col2]);

                    if (row == grid.size() - 1)
                    {
                        cherrys[row][col1][col2] = cherry;
                        continue;
                    }

                    int max_cherrys = 0;

                    for (int block1 = col1 - 1; block1 <= col1 + 1; block1++)
                    {
                        for (int block2 = col2 - 1; block2 <= col2 + 1; block2++)
                        {
                            if (block1 < 0 || block1 >= grid[0].size() || block2 < 0 || block2 >= grid[0].size())
                            {
                                continue;
                            }

                            max_cherrys = max(max_cherrys, cherrys[row + 1][block1][block2]);
                        }
                    }

                    max_cherrys += cherry;
                    cherrys[row][col1][col2] = max_cherrys;
                }
            }
        }

        return cherrys[0][0][grid[0].size() - 1];
    }

    // space optimization
    int cherryPickup(vector<vector<int>> &grid)
    {
        int curr_cherrys[grid[0].size()][grid[0].size()];
        int next_cherrys[grid[0].size()][grid[0].size()];

        for (int row = grid.size() - 1; row >= 0; row--)
        {
            for (int col1 = 0; col1 < grid[0].size(); col1++)
            {
                for (int col2 = 0; col2 < grid[0].size(); col2++)
                {
                    int cherry = (col1 == col2) ? (grid[row][col1]) : (grid[row][col1] + grid[row][col2]);

                    if (row == grid.size() - 1)
                    {
                        curr_cherrys[col1][col2] = cherry;
                        continue;
                    }

                    int max_cherrys = 0;
                    
                    for (int block1 = col1 - 1; block1 <= col1 + 1; block1++)
                    {
                        for (int block2 = col2 - 1; block2 <= col2 + 1; block2++)
                        {
                            if (block1 < 0 || block1 >= grid[0].size() || block2 < 0 || block2 >= grid[0].size())
                            {
                                continue;
                            }

                            max_cherrys = max(max_cherrys, next_cherrys[block1][block2]);
                        }
                    }

                    max_cherrys += cherry;
                    curr_cherrys[col1][col2] = max_cherrys;
                }
            }

            for (int col1 = 0; col1 < grid[0].size(); col1++)
            {
                for (int col2 = 0; col2 < grid[0].size(); col2++)
                {
                    next_cherrys[col1][col2] = curr_cherrys[col1][col2];
                }
            }
        }

        return curr_cherrys[0][grid[0].size() - 1];
    }
};

int main()
{

    return 0;
}