#include <bits/stdc++.h>
using namespace std;

// Depth First Search
class Solution
{
protected:
    bool isValidFarm(int row, int col, vector<vector<int>> &land)
    {
        int rows = land.size();
        int cols = land[0].size();

        return (row >= 0 && row < rows && col >= 0 && col < cols && land[row][col] == 1);
    }

    void travesingTheFarmLand(int row, int col, pair<int, int> &bottomRightCorner, vector<pair<int, int>> &moments, vector<vector<int>> &land)
    {
        int rows = land.size();
        int cols = land[0].size();

        int maxRow = bottomRightCorner.first;
        int maxCol = bottomRightCorner.second;

        bottomRightCorner.first = max(maxRow, row);
        bottomRightCorner.second = max(maxCol, col);

        for (auto &moment : moments)
        {
            int newRow = row + moment.first;
            int newCol = col + moment.second;

            if (isValidFarm(newRow, newCol, land))
            {
                land[newRow][newCol] = 0;
                travesingTheFarmLand(newRow, newCol, bottomRightCorner, moments, land);
            }
        }
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> farmLand;
        int rows = land.size(), cols = land[0].size();
        vector<pair<int, int>> moments = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                pair<int, int> topLeftCorner = {row, col};
                pair<int, int> bottomRightCorner = {row, col};

                if (land[row][col] == 1)
                {
                    travesingTheFarmLand(row, col, bottomRightCorner, moments, land);

                    int row1 = topLeftCorner.first, row2 = bottomRightCorner.first;
                    int col1 = topLeftCorner.second, col2 = bottomRightCorner.second;

                    farmLand.push_back({row1, col1, row2, col2});
                }
            }
        }

        return farmLand;
    }
};

// TC : O(M * N) // visit each block of land
// SC : O(max(M , N)) // recursion stack space

// Breadth First Search
class Solution
{
protected:
    bool isValidFarm(int row, int col, vector<vector<int>> &land)
    {
        int rows = land.size();
        int cols = land[0].size();

        return (row >= 0 && row < rows && col >= 0 && col < cols && land[row][col] == 1);
    }

    void travesingTheFarmLand(int row, int col, pair<int, int> &bottomRightCorner, vector<pair<int, int>> &moments, vector<vector<int>> &land)
    {
        queue<pair<int, int>> queueOfFarms;
        queueOfFarms.push({row, col});
        land[row][col] = 0;

        while (!queueOfFarms.empty())
        {
            pair<int, int> farm = queueOfFarms.front();
            int farmRow = farm.first, farmCol = farm.second;
            queueOfFarms.pop();

            int maxRow = bottomRightCorner.first;
            int maxCol = bottomRightCorner.second;

            bottomRightCorner.first = max(maxRow, farmRow);
            bottomRightCorner.second = max(maxCol, farmCol);

            for (auto &moment : moments)
            {
                int newRow = farmRow + moment.first;
                int newCol = farmCol + moment.second;

                if (isValidFarm(newRow, newCol, land))
                {
                    land[newRow][newCol] = 0;
                    queueOfFarms.push({newRow, newCol});
                }
            }
        }
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> farmLand;
        int rows = land.size(), cols = land[0].size();
        vector<pair<int, int>> moments = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                pair<int, int> topLeftCorner = {row, col};
                pair<int, int> bottomRightCorner = {row, col};

                if (land[row][col] == 1)
                {
                    travesingTheFarmLand(row, col, bottomRightCorner, moments, land);

                    int row1 = topLeftCorner.first, row2 = bottomRightCorner.first;
                    int col1 = topLeftCorner.second, col2 = bottomRightCorner.second;

                    farmLand.push_back({row1, col1, row2, col2});
                }
            }
        }

        return farmLand;
    }
};

// TC : O(M * N)
// SC : O(M * N)

// Brute Force
class Solution
{
protected:
    void visitAllFarmsLand(int startRow, int startCol, int endRow, int endCol, vector<vector<int>> &land)
    {
        for (int row = startRow; row <= endRow; row++)
        {
            for (int col = startCol; col <= endCol; col++)
            {
                land[row][col] = 0;
            }
        }
    }

    pair<int, int> findBottomRightCorner(int startRow, int startCol, vector<vector<int>> &land)
    {
        pair<int, int> bottomRightCorner;
        int row = startRow, col = startCol;
        int rows = land.size(), cols = land[0].size();

        while (row < rows)
        {
            if (land[row][startCol] == 0)
                break;

            row = row + 1;
        }

        while (col < cols)
        {
            if (land[startRow][col] == 0)
                break;

            col = col + 1;
        }

        bottomRightCorner.first = row - 1;
        bottomRightCorner.second = col - 1;

        return bottomRightCorner;
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> farmLand;
        int rows = land.size(), cols = land[0].size();

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                pair<int, int> topLeftCorner = {row, col};
                pair<int, int> bottomRightCorner = {row, col};

                if (land[row][col] == 1)
                {
                    bottomRightCorner = findBottomRightCorner(row, col, land);

                    int row1 = topLeftCorner.first, row2 = bottomRightCorner.first;
                    int col1 = topLeftCorner.second, col2 = bottomRightCorner.second;

                    visitAllFarmsLand(row1, col1, row2, col2, land);
                    farmLand.push_back({row1, col1, row2, col2});
                }
            }
        }

        return farmLand;
    }
};

// TC : O(M * N)
// SC : O(1)

int main()
{

    return 0;
}