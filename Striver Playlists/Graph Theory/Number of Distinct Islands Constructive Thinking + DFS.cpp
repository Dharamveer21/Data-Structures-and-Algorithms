#include <bits/stdc++.h>
using namespace std;

// use dfs & subtract base technique to store the shape in the set
class Solution
{
public:
    bool is_valid(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] == 0)
        {
            return false;
        }

        return true;
    }

    void dfs(int row, int col, pair<int, int> base, vector<vector<int>> &grid, vector<pair<int, int>> &shape, vector<pair<int, int>> &moments)
    {
        shape.push_back({row - base.first, col - base.second});

        for (int i = 0; i < 4; i++)
        {
            int child_x = row + moments[i].first;
            int child_y = col + moments[i].second;

            if (is_valid(child_x, child_y, grid))
            {
                grid[child_x][child_y] = 0;
                dfs(child_x, child_y, base, grid, shape, moments);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        set<vector<pair<int, int>>> distinct_islands;
        vector<pair<int, int>> moments = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        vector<pair<int, int>> shape;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                {
                    grid[row][col] = 0;
                    dfs(row, col, {row, col}, grid, shape, moments);
                    distinct_islands.insert(shape);
                    shape.clear();
                }
            }
        }

        return distinct_islands.size();
    }
};

int main()
{

    return 0;
}