#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here the intution is that for making the smallest number we need the digits of the number should be
in increasing order . Also we will delete the most significant position digits first to make minimum number .
We will use a monotonic stack means we will keep adding digits till the order is non decreasing if the order
breaks we started popping out stack elements until the order is maintained . Finally return the number after
removing the preceeding zeros from the given ans . Here we can use string as monotonic stack .
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int numberOfDigitsCanBeRemoved = k;
        string smallestNumberAfterRemovingKDigits;
        smallestNumberAfterRemovingKDigits.push_back('0');

        for (char &digit : num)
        {
            char lastDigitOfSmallestNumber = smallestNumberAfterRemovingKDigits.back();

            while (numberOfDigitsCanBeRemoved > 0 && !smallestNumberAfterRemovingKDigits.empty() && lastDigitOfSmallestNumber > digit)
            {
                smallestNumberAfterRemovingKDigits.pop_back();
                numberOfDigitsCanBeRemoved = numberOfDigitsCanBeRemoved - 1;
                lastDigitOfSmallestNumber = smallestNumberAfterRemovingKDigits.back();
            }

            smallestNumberAfterRemovingKDigits.push_back(digit);
        }

        while (numberOfDigitsCanBeRemoved--)
        {
            smallestNumberAfterRemovingKDigits.pop_back();
        }

        int numberOfDigitsInSmallestNumber = smallestNumberAfterRemovingKDigits.length();
        reverse(smallestNumberAfterRemovingKDigits.begin(), smallestNumberAfterRemovingKDigits.end());

        for (int ind = numberOfDigitsInSmallestNumber - 1; ind >= 0; ind--)
        {
            if (smallestNumberAfterRemovingKDigits.back() != 0)
                break;

            smallestNumberAfterRemovingKDigits.pop_back();
        }

        reverse(smallestNumberAfterRemovingKDigits.begin(), smallestNumberAfterRemovingKDigits.end());
        return smallestNumberAfterRemovingKDigits;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}