#include <bits/stdc++.h>
using namespace std;

/*
Approach -- use recursion to generate all numbers for n-1 length
use a all possible positions vector for the moves
it is DP problem
in tabulation Dp we first need to calculate Numbers of length l for each num then we can calculate
numbers of length (l+1) for any number
*/

class Solution
{
private:
    static const int M = 1e9 + 7;
    vector<vector<int>> keypad = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
    vector<pair<int, int>> movements = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};

public:
    // memoisation
    bool isValid(int row, int col)
    {
        if (row < 0 || col < 0 || row > 3 || col > 2 || keypad[row][col] == -1)
        {
            return false;
        }

        return true;
    }

    int distinctNumbers(int row, int col, int length, vector<vector<int>> &Numbers)
    {
        int num = keypad[row][col];
        int totalNumbers = 0;

        if (length == 1)
        {
            return 1;
        }

        if (Numbers[num][length] != -1)
        {
            return Numbers[num][length];
        }

        for (auto movement : movements)
        {
            int newRow = row + movement.first;
            int newCol = col + movement.second;

            if (isValid(newRow, newCol))
            {
                totalNumbers = (totalNumbers + 0LL + distinctNumbers(newRow, newCol, length - 1, Numbers)) % M;
            }
        }

        return (Numbers[num][length] = totalNumbers);
    }

    int knightDialer(int n)
    {
        int totalNumbers = 0;
        vector<vector<int>> Numbers(10, vector<int>(n + 1, -1));

        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                int num = keypad[row][col];

                if (num != -1)
                {
                    int numbers = distinctNumbers(row, col, n, Numbers);
                    totalNumbers = (totalNumbers + 0LL + numbers) % M;
                }
            }
        }

        return totalNumbers;
    }

    // tabulation
    bool isValid(int row, int col)
    {
        if (row < 0 || col < 0 || row > 3 || col > 2 || keypad[row][col] == -1)
        {
            return false;
        }

        return true;
    }

    int knightDialer(int n)
    {
        int totalNumbers = 0;
        vector<vector<int>> Numbers(10, vector<int>(n + 1, 0));

        for (int num = 0; num < 10; num++)
        {
            Numbers[num][1] = 1;
        }

        for (int length = 2; length <= n; length++)
        {
            for (int row = 0; row < 4; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    int num = keypad[row][col];

                    if (num != -1)
                    {
                        for (auto movement : movements)
                        {
                            int newRow = row + movement.first;
                            int newCol = col + movement.second;

                            if (isValid(newRow, newCol))
                            {
                                int newNum = keypad[newRow][newCol];
                                Numbers[num][length] = (Numbers[num][length] + 0LL + Numbers[newNum][length - 1]) % M;
                            }
                        }

                        int numbers = Numbers[num][n];
                        totalNumbers = (totalNumbers + 0LL + numbers) % M;
                    }
                }
            }
        }

        return ((n == 1) ? 10 : totalNumbers);
    }
};

int main()
{

    return 0;
}
