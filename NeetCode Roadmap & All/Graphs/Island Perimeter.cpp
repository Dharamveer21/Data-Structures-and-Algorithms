#include <bits/stdc++.h>
using namespace std;

// Depth First Search
class Solution
{
protected:
    bool isBoundaryWall(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        return (row == -1 || row == rows || col == -1 || col == cols || grid[row][col] == 0);
    }

    void traversingTheIsLand(int row, int col, int &perimeter, vector<pair<int, int>> &moments, vector<vector<int>> &grid)
    {
        if (isBoundaryWall(row, col, grid))
        {
            perimeter += 1;
            return;
        }

        if (grid[row][col] == -1)
            return;

        grid[row][col] = -1;

        for (auto &moment : moments)
        {
            int newRow = row + moment.first;
            int newCol = col + moment.second;

            traversingTheIsLand(newRow, newCol, perimeter, moments, grid);
        }
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0, rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> moments = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                    traversingTheIsLand(row, col, perimeter, moments, grid);
            }
        }

        return perimeter;
    }
};

// TC : O(M * N)
// SC : O(max(M , N))

// Breadth First Search
class Solution
{
protected:
    bool isBoundaryWall(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        return (row == -1 || row == rows || col == -1 || col == cols || grid[row][col] == 0);
    }

    void traversingTheIsLand(int startRow, int startCol, int &perimeter, vector<pair<int, int>> &moments, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> queueOfIslands;
        queueOfIslands.push({startRow, startCol});
        grid[startRow][startCol] = -1;

        while (!queueOfIslands.empty())
        {
            auto island = queueOfIslands.front();
            queueOfIslands.pop();

            int row = island.first, col = island.second;

            for (auto &moment : moments)
            {
                int newRow = row + moment.first;
                int newCol = col + moment.second;

                if (isBoundaryWall(newRow, newCol, grid))
                    perimeter = perimeter + 1;

                else if (grid[newRow][newCol] == -1)
                    continue;

                else
                {
                    queueOfIslands.push({newRow, newCol});
                    grid[newRow][newCol] = -1;
                }
            }
        }
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0, rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> moments = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                    traversingTheIsLand(row, col, perimeter, moments, grid);
            }
        }

        return perimeter;
    }
};

// TC : O(M * N)
// SC : O(M * N)

// Brute Force
class Solution
{
protected:
    bool isBoundaryWall(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        return (row == -1 || row == rows || col == -1 || col == cols || grid[row][col] == 0);
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0, rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> moments = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                {
                    for (auto &moment : moments)
                    {
                        int newRow = row + moment.first;
                        int newCol = col + moment.second;

                        perimeter += isBoundaryWall(newRow, newCol, grid);
                    }
                }
            }
        }

        return perimeter;
    }
};

// TC : O(M * N)
// SC : O(1)

int main()
{

    return 0;
}