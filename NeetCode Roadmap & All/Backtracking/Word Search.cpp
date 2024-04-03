#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a simple backtracking problem we just have to start the index where the first character of the
word is match with the character in board . We need to pass index of the word string as argument along with row
and col of the curr char of board . Then we will compare the char of word with the 4 neighbours of the character
of the board . If it gets equal then we call the recursion and finally return if word is present or not . We can
also use board arrays as out visited array where we mark a char as dollar entering & reverse it when leaving .
*/

class Solution
{
protected:
    bool isMomentValid(int row, int col, vector<vector<char>> &visited)
    {
        int rows = visited.size();
        int cols = visited[0].size();

        return (row >= 0 && col >= 0 && row < rows && col < cols && visited[row][col] != '$');
    }

    bool isWordExistsInMatrix(int row, int col, int indexOfWord, string &word, vector<pair<int, int>> &moments, vector<vector<char>> &board)
    {
        bool isWordExists = false;

        if (indexOfWord == word.size())
            return true;

        char currentChar = word[indexOfWord];

        for (auto &moment : moments)
        {
            int newRow = row + moment.first;
            int newCol = col + moment.second;

            if (isMomentValid(newRow, newCol, board) && currentChar == board[newRow][newCol] && !isWordExists)
            {
                board[newRow][newCol] = '$';
                isWordExists = isWordExistsInMatrix(newRow, newCol, indexOfWord + 1, word, moments, board);
                board[newRow][newCol] = currentChar;
            }
        }

        return isWordExists;
    }

public:
    bool exist(vector<vector<char>> &board, string &word)
    {
        int rows = board.size();
        int cols = board[0].size();

        bool isWordExists = false;
        char firstChar = word[0];

        vector<pair<int, int>> moments = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                char ch = board[row][col];

                if (ch == firstChar && !isWordExists)
                {
                    board[row][col] = '$';
                    isWordExists = isWordExistsInMatrix(row, col, 1, word, moments, board);
                    board[row][col] = ch;
                }
            }
        }

        return isWordExists;
    }
};

// M -- rows , N -- cols , L -- length of the word
// TC : O(M * N * L) -- for each char in board traverse whole word in worst case
// SC : O(L) -- recursion stack space

int main()
{

    return 0;
}