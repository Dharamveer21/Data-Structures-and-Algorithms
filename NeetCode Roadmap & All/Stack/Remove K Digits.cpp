#include <bits/stdc++.h>
using namespace std;

// Monotonic Stack
class Solution
{
public:
    string removeKdigits(string &num, int k)
    {
        int numberOfDigitsCanBeRemoved = k;
        string smallestNumberAfterRemovingKDigits;

        for (char &digit : num)
        {
            while (!smallestNumberAfterRemovingKDigits.empty() && smallestNumberAfterRemovingKDigits.back() > digit && numberOfDigitsCanBeRemoved > 0)
            {
                smallestNumberAfterRemovingKDigits.pop_back();
                numberOfDigitsCanBeRemoved = numberOfDigitsCanBeRemoved - 1;
            }

            if (!smallestNumberAfterRemovingKDigits.empty() || digit != '0')
                smallestNumberAfterRemovingKDigits.push_back(digit);
        }

        while (!smallestNumberAfterRemovingKDigits.empty() && numberOfDigitsCanBeRemoved > 0)
        {
            numberOfDigitsCanBeRemoved -= 1;
            smallestNumberAfterRemovingKDigits.pop_back();
        }

        if (smallestNumberAfterRemovingKDigits.empty())
            return "0";

        return smallestNumberAfterRemovingKDigits;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}