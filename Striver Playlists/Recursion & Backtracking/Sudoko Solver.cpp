#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool flag = false;

    bool isPossible(int row, int col, int num, vector<vector<bool>> &row_hash, vector<vector<bool>> &col_hash, vector<vector<bool>> &block_hash)
    {
        int block_row = row / 3;
        int block_col = col / 3;

        int r = num / 3;
        int c = num % 3 - 1;

        if (c == -1)
        {
            r -= 1;
            c = 2;
        }

        block_row = r + block_row * 3;
        block_col = c + block_col * 3;

        if (row_hash[row][num - 1] || col_hash[num - 1][col] || block_hash[block_row][block_col])
        {
            return false;
        }

        return true;
    }

    void mark(int row, int col, int num, vector<vector<bool>> &row_hash, vector<vector<bool>> &col_hash, vector<vector<bool>> &block_hash, bool to_mark)
    {
        row_hash[row][num - 1] = to_mark;
        col_hash[num - 1][col] = to_mark;

        int block_row = row / 3;
        int block_col = col / 3;

        int r = num / 3;
        int c = num % 3 - 1;

        if (c == -1)
        {
            r -= 1;
            c = 2;
        }

        block_row = r + block_row * 3;
        block_col = c + block_col * 3;

        block_hash[block_row][block_col] = to_mark;
    }

    void solve(int ind, vector<vector<char>> &board, vector<vector<bool>> &row_hash, vector<vector<bool>> &col_hash, vector<vector<bool>> &block_hash, vector<pair<int, int>> &to_fill)
    {
        if (ind == to_fill.size())
        {
            flag = true;
            return;
        }

        int row = to_fill[ind].first;
        int col = to_fill[ind].second;
        int count = 0;

        for (int num = 1; num <= 9; num++)
        {
            if (isPossible(row, col, num, row_hash, col_hash, block_hash))
            {
                board[row][col] = num + '0';
                mark(row, col, num, row_hash, col_hash, block_hash, true);
                solve(ind + 1, board, row_hash, col_hash, block_hash, to_fill);
                mark(row, col, num, row_hash, col_hash, block_hash, false);

                if (flag)
                    break;
            }

            else
            {
                count++;
            }
        }

        if (count == 9)
        {
            return;
        }
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> row_hash, col_hash, block_hash;
        vector<pair<int, int>> to_fill;
        vector<bool> temp(9, false);

        for (int i = 0; i < 9; i++)
        {
            row_hash.push_back(temp);
            col_hash.push_back(temp);
            block_hash.push_back(temp);
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = board[i][j];

                if (ch == '.')
                {
                    to_fill.push_back({i, j});
                }

                else
                {
                    int num = ch - '0';
                    mark(i, j, num, row_hash, col_hash, block_hash, true);
                }
            }
        }

        solve(0, board, row_hash, col_hash, block_hash, to_fill);
    }
};

int main()
{

    return 0;
}
