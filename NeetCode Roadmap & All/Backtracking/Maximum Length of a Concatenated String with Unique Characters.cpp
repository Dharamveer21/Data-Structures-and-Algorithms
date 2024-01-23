#include <bits/stdc++.h>
using namespace std;

/*
Approach -- it is a backtracking problem , we can either include a particular string or exclude it
for including the current string it must satisfy two functions

1. isValidString -- which means string itself must not contain duplicate characters
2. canConcatenate -- which will check whether we can add this string on basis of idea that its characters are
   not present in prevChar array , prevChar array will keep the track of the strings will are added before
   when we include a string we update it in prevChar array after finding the maxLen we remove str from prevChar
*/

class Solution
{
protected:
    bool isValidString(string &str)
    {
        vector<bool> charStr(26, false);

        for (char &ch : str)
        {
            int index = ch - 'a';

            if (charStr[index] == true)
            {
                return false;
            }

            charStr[index] = true;
        }

        return true;
    }

    bool canConcatenate(vector<bool> &prevChar, string &str)
    {
        int isPossible = false;

        for (char &ch : str)
        {
            int index = ch - 'a';
            bool isPresent = prevChar[index];

            isPossible = (isPossible || isPresent);
        }

        return (isPossible == false);
    }

    void removeConcatenate(vector<bool> &prevChar, string &str)
    {
        for (char &ch : str)
        {
            int index = ch - 'a';
            prevChar[index] = false;
        }
    }

    void additionConcatenate(vector<bool> &prevChar, string &str)
    {
        for (char &ch : str)
        {
            int index = ch - 'a';
            prevChar[index] = true;
        }
    }

    int maxConcatenatString(int ind, vector<bool> &prevChar, vector<string> &arr)
    {
        if (ind == arr.size())
        {
            return 0;
        }

        string &str = arr[ind];
        int maxLenWithExcluding = 0, maxLenWithIncluding = 0;

        maxLenWithExcluding = maxConcatenatString(ind + 1, prevChar, arr);

        if (isValidString(str) && canConcatenate(prevChar, str))
        {
            int len = str.length();
            additionConcatenate(prevChar, str);
            maxLenWithIncluding = len + maxConcatenatString(ind + 1, prevChar, arr);
            removeConcatenate(prevChar, str);
        }

        int maxLen = max(maxLenWithExcluding, maxLenWithIncluding);
        return maxLen;
    }

public:
    int maxLength(vector<string> &arr)
    {
        vector<bool> prevChar(26, false);
        int maxLen = maxConcatenatString(0, prevChar, arr);

        return maxLen;
    }
};

// K -- average size of string , N -- size of vector
// TC : O(2^N * K)
// SC : O(N + K)

int main()
{

    return 0;
}