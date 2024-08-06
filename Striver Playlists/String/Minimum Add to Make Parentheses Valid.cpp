#include <bits/stdc++.h>
using namespace std;

// Stack
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> openParanthesis;
        int n = s.length(), minMoves = 0;

        for (int ind = 0; ind < n; ind++)
        {
            char ch = s[ind];

            switch (ch)
            {
            case '(':
                openParanthesis.push(ch);
                break;

            case ')':
                if (openParanthesis.empty())
                    minMoves++;

                else
                    openParanthesis.pop();
            }
        }

        minMoves += openParanthesis.size();
        return minMoves;
    }
};

// TC : O(N)
// SC : O(N)

// Logic & Implimentation
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int openParanthesisCount = 0;
        int n = s.length(), minMoves = 0;

        for (int ind = 0; ind < n; ind++)
        {
            char ch = s[ind];

            switch (ch)
            {
            case '(':
                openParanthesisCount++;
                break;

            case ')':
                if (openParanthesisCount == 0)
                    minMoves++;

                else
                    openParanthesisCount--;
            }
        }

        minMoves += openParanthesisCount;
        return minMoves;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}