#include <bits/stdc++.h>
using namespace std;

// Sorting
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int numStrings = strs.size();
        sort(strs.begin(), strs.end());
        string longestCommonPrefixInStrings;

        string &firstString = strs[0], &lastString = strs[numStrings - 1];
        int len1 = firstString.length(), len2 = lastString.length();

        for (int ind = 0; ind < min(len1, len2); ind++)
        {
            char ch1 = firstString[ind];
            int ch2 = lastString[ind];

            if (ch1 != ch2)
                break;

            longestCommonPrefixInStrings.push_back(ch1);
        }

        return longestCommonPrefixInStrings;
    }
};

// TC : O(N * log(N))
// SC : O(1)

int main()
{

    return 0;
}