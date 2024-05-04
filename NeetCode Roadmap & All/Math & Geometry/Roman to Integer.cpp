#include <bits/stdc++.h>
using namespace std;

// Implementation
class Solution
{
public:
    int romanToInt(string &s)
    {
        unordered_map<char, int> romanToIntegerMapping = {{'J', 2}, {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int strLen = s.length(), integerNumber = romanToIntegerMapping[s[strLen - 1]];

        for (int ind = strLen - 2; ind >= 0; ind--)
        {
            int currCharVal = romanToIntegerMapping[s[ind]];
            int nextCharVal = romanToIntegerMapping[s[ind + 1]];

            if (currCharVal < nextCharVal)
                integerNumber = integerNumber - currCharVal;

            else
                integerNumber = integerNumber + currCharVal;
        }

        return integerNumber;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}