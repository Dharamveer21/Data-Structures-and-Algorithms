#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can think it in form of recursion
a function will give lcs in the given two strings starting from 0-index till ind1 in
text1 and ind2 in text2 .

Then there are three cases : the longest lcs will be in any of these
1. if (text1[ind1] == text2[ind2]) from ind1 - 1 & ind2 - 1
2. if (text1[ind1] != text2[ind2]) max(from ind1 & ind2 - 1 , from ind1 - 1 & ind2)

Then we can apply memoisation --> tabulation --> space optimization
*/

class Solution
{
protected:
    // memoisation
    int lcs(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &longestLenLCS)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }

        if (longestLenLCS[ind1][ind2] != -1)
        {
            return longestLenLCS[ind1][ind2];
        }

        int doesCharMatch = (str1[ind1] == str2[ind2]);

        if (doesCharMatch)
        {
            int lcsLenBothExclude = lcs(ind1 - 1, ind2 - 1, str1, str2, longestLenLCS) + doesCharMatch;
            return longestLenLCS[ind1][ind2] = lcsLenBothExclude;
        }

        int lcsLenExcStr1IncStr2 = lcs(ind1 - 1, ind2, str1, str2, longestLenLCS);
        int lcsLenIncStr1ExcStr2 = lcs(ind1, ind2 - 1, str1, str2, longestLenLCS);

        int maxLcsLen = max(lcsLenExcStr1IncStr2, lcsLenIncStr1ExcStr2);
        return longestLenLCS[ind1][ind2] = maxLcsLen;
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> longestLenLCS(n1, vector<int>(n2, -1));

        int longestLCS = lcs(n1 - 1, n2 - 1, text1, text2, longestLenLCS);
        return longestLCS;
    }

    // tabulation
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> longestLenLCS(n1, vector<int>(n2, 0));

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                int doesCharMatch = (text1[ind1] == text2[ind2]);

                if (doesCharMatch)
                {
                    int lcsLenBothExclude = ((ind1 == 0 || ind2 == 0) ? 0 : longestLenLCS[ind1 - 1][ind2 - 1]) + doesCharMatch;
                    longestLenLCS[ind1][ind2] = lcsLenBothExclude;
                    continue;
                }

                int lcsLenExcStr1IncStr2 = ((ind1 == 0) ? 0 : longestLenLCS[ind1 - 1][ind2]);
                int lcsLenIncStr1ExcStr2 = ((ind2 == 0) ? 0 : longestLenLCS[ind1][ind2 - 1]);

                int maxLcsLen = max(lcsLenExcStr1IncStr2, lcsLenIncStr1ExcStr2);
                longestLenLCS[ind1][ind2] = maxLcsLen;
            }
        }

        int longestLCS = longestLenLCS[n1 - 1][n2 - 1];
        return longestLCS;
    }

    // space optimization
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> prevLongestLenLCS(n2, 0);
        vector<int> currLongestLenLCS(n2, 0);

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                int doesCharMatch = (text1[ind1] == text2[ind2]);

                if (doesCharMatch)
                {
                    int lcsLenBothExclude = ((ind1 == 0 || ind2 == 0) ? 0 : prevLongestLenLCS[ind2 - 1]) + doesCharMatch;
                    currLongestLenLCS[ind2] = lcsLenBothExclude;
                    continue;
                }

                int lcsLenExcStr1IncStr2 = ((ind1 == 0) ? 0 : prevLongestLenLCS[ind2]);
                int lcsLenIncStr1ExcStr2 = ((ind2 == 0) ? 0 : currLongestLenLCS[ind2 - 1]);

                int maxLcsLen = max(lcsLenExcStr1IncStr2, lcsLenIncStr1ExcStr2);
                currLongestLenLCS[ind2] = maxLcsLen;
            }

            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                prevLongestLenLCS[ind2] = currLongestLenLCS[ind2];
            }
        }

        int longestLCS = currLongestLenLCS[n2 - 1];
        return longestLCS;
    }
};

// TC : O(N1 * N2)
// SC : O(N2)

int main()
{

    return 0;
}