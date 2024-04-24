#include <bits/stdc++.h>
using namespace std;

// Depth First Search
class Solution
{
protected:
    bool isValid(int row, int col, vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        return (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == '1');
    }

    void traversingTheIsLand(int row, int col, vector<pair<int, int>> &moments, vector<vector<char>> &grid)
    {
        for (auto &moment : moments)
        {
            int newRow = row + moment.first;
            int newCol = col + moment.second;

            if (isValid(newRow, newCol, grid))
            {
                grid[newRow][newCol] = '0';
                traversingTheIsLand(newRow, newCol, moments, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int islandCount = 0, rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> moments = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == '1')
                {
                    islandCount = islandCount + 1;
                    traversingTheIsLand(row, col, moments, grid);
                }
            }
        }

        return islandCount;
    }
};

// TC : O(M * N)
// SC : O(max(M , N))

// Breadth First Search
class Solution
{
protected:
    bool isValid(int row, int col, vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        return (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == '1');
    }

    void traversingTheIsLand(int startRow, int startCol, vector<pair<int, int>> &moments, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> queueOfIsLands;
        queueOfIsLands.push({startRow, startCol});
        grid[startRow][startCol] = '0';

        while (!queueOfIsLands.empty())
        {
            auto island = queueOfIsLands.front();
            queueOfIsLands.pop();

            int row = island.first, col = island.second;

            for (auto &moment : moments)
            {
                int newRow = row + moment.first;
                int newCol = col + moment.second;

                if (isValid(newRow, newCol, grid))
                {
                    grid[newRow][newCol] = '0';
                    queueOfIsLands.push({newRow, newCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int islandCount = 0, rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> moments = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == '1')
                {
                    islandCount = islandCount + 1;
                    traversingTheIsLand(row, col, moments, grid);
                }
            }
        }

        return islandCount;
    }
};

// TC : O(M * N)
// SC : O(M * N)

int main()
{

    return 0;
}