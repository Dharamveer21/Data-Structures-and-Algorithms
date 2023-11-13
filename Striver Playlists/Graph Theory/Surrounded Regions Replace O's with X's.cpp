#include <bits/stdc++.h>
using namespace std;

// use multi source bfs from all boundry Os

class Solution
{
public:
    bool is_valid(int row, int col, vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || board[row][col] != 'O')
        {
            return false;
        }

        return true;
    }

    void solve(vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();
        vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int, int>> q;

        for (int row = 0; row < rows; row++)
        {
            if (board[row][0] == 'O')
            {
                q.push({row, 0});
                board[row][0] = 'A';
            }

            if (board[row][cols - 1] == 'O')
            {
                q.push({row, cols - 1});
                board[row][cols - 1] = 'A';
            }
        }

        for (int col = 0; col < cols; col++)
        {
            if (board[0][col] == 'O')
            {
                q.push({0, col});
                board[0][col] = 'A';
            }

            if (board[rows - 1][col] == 'O')
            {
                q.push({rows - 1, col});
                board[rows - 1][col] = 'A';
            }
        }

        while (!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            for (int i = 0; i < 4; i++)
            {
                int child_x = row + moments[i].first;
                int child_y = col + moments[i].second;

                if (is_valid(child_x, child_y, board))
                {
                    board[child_x][child_y] = 'A';
                    q.push({child_x, child_y});
                }
            }
        }

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (board[row][col] == 'O')
                {
                    board[row][col] = 'X';
                }

                if (board[row][col] == 'A')
                {
                    board[row][col] = 'O';
                }
            }
        }
    }
};

// use dfs
class Solution
{
public:
    bool is_valid(int row, int col, vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols || board[row][col] != 'O')
        {
            return false;
        }

        return true;
    }

    void dfs(int row, int col, vector<vector<char>> &board, vector<pair<int, int>> &moments)
    {
        for (int i = 0; i < 4; i++)
        {
            int child_x = row + moments[i].first;
            int child_y = col + moments[i].second;

            if (is_valid(child_x, child_y, board))
            {
                board[child_x][child_y] = 'A';
                dfs(child_x, child_y, board, moments);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();

        vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (int row = 0; row < rows; row++)
        {
            if (board[row][0] == 'O')
            {
                board[row][0] = 'A';
                dfs(row, 0, board, moments);
            }

            if (board[row][cols - 1] == 'O')
            {
                board[row][cols - 1] = 'A';
                dfs(row, cols - 1, board, moments);
            }
        }

        for (int col = 0; col < cols; col++)
        {
            if (board[0][col] == 'O')
            {
                board[0][col] = 'A';
                dfs(0, col, board, moments);
            }

            if (board[rows - 1][col] == 'O')
            {
                board[rows - 1][col] = 'A';
                dfs(rows - 1, col, board, moments);
            }
        }

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (board[row][col] == 'O')
                {
                    board[row][col] = 'X';
                }

                if (board[row][col] == 'A')
                {
                    board[row][col] = 'O';
                }
            }
        }
    }
};

int main()
{

    return 0;
}