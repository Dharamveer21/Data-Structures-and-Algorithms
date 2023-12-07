#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Find the first odd digit from last , it makes whole number odd
*/

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.size();
        int lastOddDigitInd = n;

        for (int i = n - 1; i >= 0; i--)
        {
            char ch = num[i];
            int digit = ch - '0';

            if (digit & 1)
            {
                lastOddDigitInd = i;
                break;
            }
        }

        if (lastOddDigitInd == n)
        {
            return "";
        }

        return num.substr(0, lastOddDigitInd + 1);
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}