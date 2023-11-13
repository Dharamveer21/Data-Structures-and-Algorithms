#include <bits/stdc++.h>
using namespace std;

// we use multisource bfs

class Solution
{
public:
    bool is_valid(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] == 0 || grid[row][col] == 2)
        {
            return false;
        }

        return true;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int cnt_fresh = 0;
        int max_rotten_time = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<pair<int, int>> moment = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 2)
                {
                    q.push({{row, col}, 0});
                }

                if (grid[row][col] == 1)
                {
                    cnt_fresh++;
                }
            }
        }

        while (!q.empty())
        {
            pair<pair<int, int>, int> node = q.front();
            q.pop();

            int par_x = node.first.first;
            int par_y = node.first.second;
            int par_rott = node.second;

            for (int i = 0; i < 4; i++)
            {
                int child_x = par_x + moment[i].first;
                int child_y = par_y + moment[i].second;
                int child_rott = par_rott + 1;

                if (is_valid(child_x, child_y, grid))
                {
                    grid[child_x][child_y] = 2;
                    max_rotten_time = max(max_rotten_time, child_rott);
                    q.push({{child_x, child_y}, child_rott});
                    cnt_fresh--;
                }
            }
        }

        return ((cnt_fresh == 0) ? max_rotten_time : -1);
    }
};

int main()
{

    return 0;
}