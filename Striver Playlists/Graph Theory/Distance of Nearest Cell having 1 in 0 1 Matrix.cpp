#include <bits/stdc++.h>
using namespace std;

// multi source bfs from each 0 node -- assign the level to all nearest 1

class Solution
{
public:
    bool is_valid(int row, int col, vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || mat[row][col] == -1)
        {
            return false;
        }

        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> level(rows, vector<int>(cols, 0));
        vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        queue<pair<int, int>> q;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (mat[row][col] == 0)
                {
                    q.push({row, col});
                    mat[row][col] = -1;
                    level[row][col] = 0;
                }
            }
        }

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            for (int i = 0; i < 4; i++)
            {
                int child_x = row + moments[i].first;
                int child_y = col + moments[i].second;
                int child_lev = level[row][col] + 1;

                if (is_valid(child_x, child_y, mat))
                {
                    mat[child_x][child_y] = -1;
                    level[child_x][child_y] = child_lev;
                    q.push({child_x, child_y});
                }
            }
        }

        return level;
    }
};

int main()
{

    return 0;
}