#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // using vis matrix
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] == '0' || vis[row][col])
        {
            return;
        }

        vis[row][col] = true;

        dfs(row, col - 1, vis, grid);
        dfs(row - 1, col, vis, grid);
        dfs(row, col + 1, vis, grid);
        dfs(row + 1, col, vis, grid);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int islands = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                char ch = grid[row][col];

                if (ch == '1' && !vis[row][col])
                {
                    islands++;
                    dfs(row, col, vis, grid);
                }
            }
        }

        return islands;
    }

    // without using vis matrix
    void dfs(int row, int col, vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] == '0')
        {
            return;
        }

        grid[row][col] = '0';

        dfs(row, col - 1, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row + 1, col, grid);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                char ch = grid[row][col];

                if (ch == '1')
                {
                    islands++;
                    dfs(row, col, grid);
                }
            }
        }

        return islands;
    }
};

int main()
{

    return 0;
}