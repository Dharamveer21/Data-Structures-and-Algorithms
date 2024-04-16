#include <bits/stdc++.h>
using namespace std;

// Recursion & Memoisation
class Solution
{
protected:
    int areParenthesisBalanced(int ind, int openBracketCount, string &str, vector<vector<int>> &balanceParanthesis)
    {
        if (ind == str.size())
            return (openBracketCount == 0);

        if (balanceParanthesis[ind][openBracketCount] != -1)
            return balanceParanthesis[ind][openBracketCount];

        int isBalanced = 0;
        char ch = str[ind];

        switch (ch)
        {
        case '(':
            isBalanced = areParenthesisBalanced(ind + 1, openBracketCount + 1, str, balanceParanthesis);
            break;

        case ')':
            if (openBracketCount > 0)
                isBalanced = areParenthesisBalanced(ind + 1, openBracketCount - 1, str, balanceParanthesis);
            break;

        case '*':
            if (openBracketCount > 0)
                isBalanced |= areParenthesisBalanced(ind + 1, openBracketCount - 1, str, balanceParanthesis);

            isBalanced |= areParenthesisBalanced(ind + 1, openBracketCount, str, balanceParanthesis);
            isBalanced |= areParenthesisBalanced(ind + 1, openBracketCount + 1, str, balanceParanthesis);
        }

        return balanceParanthesis[ind][openBracketCount] = isBalanced;
    }

public:
    bool checkValidString(string &s)
    {
        int lenOfString = s.length();
        vector<vector<int>> balanceParanthesis(lenOfString, vector<int>(lenOfString + 1, -1));

        bool isBalanced = areParenthesisBalanced(0, 0, s, balanceParanthesis);
        return isBalanced;
    }
};

// TC : O(N * N)
// SC : O(N * N)

// Tabulation
class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length(), areParanthesisBalanced = 0;
        vector<vector<bool>> balanceParanthesis(n + 1, vector<bool>(n + 1, false));

        balanceParanthesis[n][0] = true;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int openBracketCount = 0; openBracketCount <= ind + 1; openBracketCount++)
            {
                char ch = s[ind];
                int isBalanced = 0;

                switch (ch)
                {
                case '(':
                    isBalanced = balanceParanthesis[ind + 1][openBracketCount + 1];
                    break;

                case ')':
                    if (openBracketCount > 0)
                        isBalanced = balanceParanthesis[ind + 1][openBracketCount - 1];
                    break;

                case '*':
                    if (openBracketCount > 0)
                        isBalanced |= balanceParanthesis[ind + 1][openBracketCount - 1];

                    isBalanced |= balanceParanthesis[ind + 1][openBracketCount];
                    isBalanced |= balanceParanthesis[ind + 1][openBracketCount + 1];
                }

                balanceParanthesis[ind][openBracketCount] = isBalanced;
            }
        }

        areParanthesisBalanced = balanceParanthesis[0][0];
        return areParanthesisBalanced;
    }
};

// TC : O(N * N)
// SC : O(N * N)

// Space Optimisation
class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length(), areParanthesisBalanced = 0;
        vector<bool> currBalanceParanthesis(n + 1, false);
        vector<bool> nextBalanceParanthesis(n + 1, false);

        nextBalanceParanthesis[0] = true;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int openBracketCount = 0; openBracketCount <= ind + 1; openBracketCount++)
            {
                char ch = s[ind];
                int isBalanced = 0;

                switch (ch)
                {
                case '(':
                    isBalanced = nextBalanceParanthesis[openBracketCount + 1];
                    break;

                case ')':
                    if (openBracketCount > 0)
                        isBalanced = nextBalanceParanthesis[openBracketCount - 1];
                    break;

                case '*':
                    if (openBracketCount > 0)
                        isBalanced |= nextBalanceParanthesis[openBracketCount - 1];

                    isBalanced |= nextBalanceParanthesis[openBracketCount];
                    isBalanced |= nextBalanceParanthesis[openBracketCount + 1];
                }

                currBalanceParanthesis[openBracketCount] = isBalanced;
            }

            for (int openBracketCount = 0; openBracketCount <= ind + 1; openBracketCount++)
                nextBalanceParanthesis[openBracketCount] = currBalanceParanthesis[openBracketCount];
        }

        areParanthesisBalanced = currBalanceParanthesis[0];
        return areParanthesisBalanced;
    }
};

// TC : O(N * N)
// SC : O(N)

// Stack & Store Indexes of asterisk
class Solution
{
public:
    bool checkValidString(string &s)
    {
        int lenOfString = s.length();
        bool isParanthesisBalanced = false;

        stack<int> openBracketsIndexes;
        stack<int> asteriskCharIndexes;

        for (int ind = 0; ind < lenOfString; ind++)
        {
            char ch = s[ind];

            switch (ch)
            {
            case '(':
                openBracketsIndexes.push(ind);
                break;

            case '*':
                asteriskCharIndexes.push(ind);
                break;

            case ')':
                if (!openBracketsIndexes.empty())
                    openBracketsIndexes.pop();

                else if (!asteriskCharIndexes.empty())
                    asteriskCharIndexes.pop();

                else
                    return isParanthesisBalanced;
            }
        }

        while (!openBracketsIndexes.empty() && !asteriskCharIndexes.empty())
        {
            int indexOfLastOpenBracket = openBracketsIndexes.top();
            int indexOfLastasteriskChar = asteriskCharIndexes.top();

            if (indexOfLastOpenBracket > indexOfLastasteriskChar)
                return isParanthesisBalanced;

            openBracketsIndexes.pop();
            asteriskCharIndexes.pop();
        }

        isParanthesisBalanced = openBracketsIndexes.empty();
        return isParanthesisBalanced;
    }
};

// TC : O(N)
// SC : O(N)

// Forward traversal with asterisk as Open And Backward with asterisk as Close Bracket
class Solution
{
public:
    bool checkValidString(string &s)
    {
        int lenOfString = s.length();
        bool areParanthesisBalanced = false;

        int openBracketsCountWithAsteriskAsOpenBracket = 0;
        int closeBracketsCountWithAsteriskAsCloseBracket = 0;

        for (int ind = 0; ind < lenOfString; ind++)
        {
            char ch = s[ind];

            if (ch == '(' || ch == '*')
                openBracketsCountWithAsteriskAsOpenBracket++;

            else
                openBracketsCountWithAsteriskAsOpenBracket--;

            if (openBracketsCountWithAsteriskAsOpenBracket < 0)
                return areParanthesisBalanced;
        }

        for (int ind = lenOfString - 1; ind >= 0; ind--)
        {
            char ch = s[ind];

            if (ch == ')' || ch == '*')
                closeBracketsCountWithAsteriskAsCloseBracket++;

            else
                closeBracketsCountWithAsteriskAsCloseBracket--;

            if (closeBracketsCountWithAsteriskAsCloseBracket < 0)
                return areParanthesisBalanced;
        }

        areParanthesisBalanced = true;
        return areParanthesisBalanced;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}