#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int row, int col, vector<bool> &left, vector<bool> &up, vector<bool> &down, int &n)
    {
        if (left[row] == true || down[row + col] == true || up[row - col + n - 1] == true)
        {
            return false;
        }

        return true;
    }

    void place_n_queens(int col, vector<string> &chess, vector<vector<string>> &all_solutions, vector<bool> &left, vector<bool> &up, vector<bool> &down, int &n)
    {
        if (col == n)
        {
            all_solutions.push_back(chess);
            return;
        }

        if (col == 0)
        {
            for (int row = 0; row < n; row++)
            {
                chess[row][col] = 'Q';
                left[row] = up[row - col + n - 1] = down[row + col] = true;
                place_n_queens(col + 1, chess, all_solutions, left, up, down, n);
                chess[row][col] = '.';
                left[row] = up[row - col + n - 1] = down[row + col] = false;
            }
        }

        else
        {
            int count = 0;

            for (int row = 0; row < n; row++)
            {
                if (!isPossible(row, col, left, up, down, n))
                {
                    count++;
                    continue;
                }

                chess[row][col] = 'Q';
                left[row] = up[row - col + n - 1] = down[row + col] = true;
                place_n_queens(col + 1, chess, all_solutions, left, up, down, n);
                chess[row][col] = '.';
                left[row] = up[row - col + n - 1] = down[row + col] = false;
            }

            if (count == n)
            {
                return;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> chess;
        vector<vector<string>> all_solutions;
        vector<bool> left(n, false), up(2 * n - 1, false), down(2 * n - 1, false);

        string s;

        for (int j = 0; j < n; j++)
        {
            char ch = '.';
            s.push_back(ch);
        }

        for (int i = 0; i < n; i++)
        {
            chess.push_back(s);
        }

        place_n_queens(0, chess, all_solutions, left, up, down, n);
        return all_solutions;
    }
};

int main()
{

    return 0;
}