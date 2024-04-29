#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a simple stack problem where the we just check if either the current character and top of char
of stack are in capital-small pair or not . If yes we pop it from stack otherwise we push the char in stack .
Finally the characters in the stack is the result string . We will use the result string directly as a stack .
We can convert any uppercase char into lower case by adding 32 to it and reverse also by minus 32 from it .
*/

class Solution
{
public:
    string makeGood(string &s)
    {
        string convertedIntoGoodString;

        for (char &currChar : s)
        {
            char prevChar = ((convertedIntoGoodString == "") ? NULL : convertedIntoGoodString.back());
            int isCharInCapitalSmallPair = ((prevChar + 32 == currChar) || (prevChar - 32 == currChar));

            switch (isCharInCapitalSmallPair)
            {
            case 0:
                convertedIntoGoodString.push_back(currChar);
                break;

            case 1:
                convertedIntoGoodString.pop_back();
            }
        }

        return convertedIntoGoodString;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}