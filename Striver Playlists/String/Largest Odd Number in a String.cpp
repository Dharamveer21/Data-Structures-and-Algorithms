#include <bits/stdc++.h>
using namespace std;

// String & Implimentation
class Solution
{
public:
    string largestOddNumber(string &num)
    {
        int n = num.length(), len = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            char ch = num[ind];
            int digit = ch - '0';

            if (digit & 1)
            {
                len = ind + 1;
                break;
            }
        }

        string largestOdd = num.substr(0, len);
        return largestOdd;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}