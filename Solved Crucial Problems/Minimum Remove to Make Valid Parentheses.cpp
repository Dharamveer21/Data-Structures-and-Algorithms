#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- We can make use stack to find the indexes of the invalid paranthesis then we put all invalid index
in a unordered_set because when we traverse the string we can check if currIndex is invalid or not in O(1) .

Approach 2 -- We can also solve it without using a stack , we can simply make take the count of the openBrackets
and if ever we got a close Bracket we when openBracket count is 0 , then it is invalid and we don't add it in
the result string . After this all we traverse the result string again from right and don't add the first K open
brackets in the final string where K is number of open Brackets count remained after traversing the string first
time . We finally reverse the final string and got our valid string after minimum removals of invalid brackets .
*/

// Approach 1
class Solution
{
public:
    string minRemoveToMakeValid(string &s)
    {
        int n = s.length();
        string validStringAfterRemoves;
        stack<int> indexOfOpenBrackets;
        unordered_set<int> indexOfInvalidBrackets;

        for (int ind = 0; ind < n; ind++)
        {
            char ch = s[ind];

            switch (ch)
            {
            case '(':
                indexOfOpenBrackets.push(ind);
                break;

            case ')':
                if (indexOfOpenBrackets.empty())
                    indexOfInvalidBrackets.insert(ind);

                else
                    indexOfOpenBrackets.pop();
            }
        }

        while (!indexOfOpenBrackets.empty())
        {
            int index = indexOfOpenBrackets.top();
            indexOfOpenBrackets.pop();

            indexOfInvalidBrackets.insert(index);
        }

        for (int ind = 0; ind < n; ind++)
        {
            char ch = s[ind];

            if (indexOfInvalidBrackets.find(ind) == indexOfInvalidBrackets.end())
                validStringAfterRemoves.push_back(ch);
        }

        return validStringAfterRemoves;
    }
};

// TC : O(N)
// SC : O(N)

// Approach 2
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.length(), openBracketsCount = 0;
        string validStringAfterInvalidClosedBracketsRemoves;
        string finalValidStringAfterInvalidOpenBracketsRemoves;

        for (int ind = 0; ind < n; ind++)
        {
            char ch = s[ind];

            switch (ch)
            {
            case '(':
                openBracketsCount += 1;
                break;

            case ')':
                if (openBracketsCount == 0)
                    continue;

                openBracketsCount -= 1;
            }

            validStringAfterInvalidClosedBracketsRemoves.push_back(ch);
        }

        n = validStringAfterInvalidClosedBracketsRemoves.length();

        for (int ind = n - 1; ind >= 0; ind--)
        {
            char ch = validStringAfterInvalidClosedBracketsRemoves[ind];

            if (ch == '(' && openBracketsCount > 0)
            {
                openBracketsCount -= 1;
                continue;
            }

            finalValidStringAfterInvalidOpenBracketsRemoves.push_back(ch);
        }

        reverse(finalValidStringAfterInvalidOpenBracketsRemoves.begin(), finalValidStringAfterInvalidOpenBracketsRemoves.end());
        return finalValidStringAfterInvalidOpenBracketsRemoves;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}