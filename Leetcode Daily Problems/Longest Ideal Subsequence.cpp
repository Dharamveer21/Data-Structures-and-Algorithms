#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming
class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int *longestIdealStringEndingAtChar = new int[26]{};
        int len = s.length(), lengthOfLongestIdealString = 1;

        for (int ind = 0; ind < len; ind++)
        {
            char currChar = s[ind];
            int lenOfLongestStr = 0;
            int index = currChar - 'a';

            int leftStartIndex = max(0, index - k);
            int rightEndIndex = min(25, index + k);

            for (int adjChar = leftStartIndex; adjChar <= rightEndIndex; adjChar++)
                lenOfLongestStr = max(lenOfLongestStr, longestIdealStringEndingAtChar[adjChar]);

            longestIdealStringEndingAtChar[index] = max(longestIdealStringEndingAtChar[index], lenOfLongestStr + 1);
            lengthOfLongestIdealString = max(lengthOfLongestIdealString, longestIdealStringEndingAtChar[index]);
        }

        delete[] longestIdealStringEndingAtChar;
        return lengthOfLongestIdealString;
    }
};

// TC : O(N * K)
// SC : O(26)

int main()
{

    return 0;
}