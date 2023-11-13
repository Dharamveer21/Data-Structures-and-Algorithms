#include <bits/stdc++.h>
using namespace std;

// tabulation
int lcs(string &str1, string &str2)
{
    vector<vector<int>> longest_substring(str1.size(), vector<int>(str2.size(), 0));
    int max_common_substr = 0;

    for (int ind1 = 0; ind1 < str1.size(); ind1++)
    {
        for (int ind2 = 0; ind2 < str2.size(); ind2++)
        {
            int len = (str1[ind1] == str2[ind2]);
            longest_substring[ind1][ind2] = ((ind1 == 0 || ind2 == 0 || len == 0) ? (len) : (longest_substring[ind1 - 1][ind2 - 1] + len));
            max_common_substr = max(max_common_substr, longest_substring[ind1][ind2]);
        }
    }

    return max_common_substr;
}

// space optimization
int lcs(string &str1, string &str2)
{
    int curr[str2.size()], prev[str2.size()];
    int max_common_substr = 0;

    for (int ind1 = 0; ind1 < str1.size(); ind1++)
    {
        for (int ind2 = 0; ind2 < str2.size(); ind2++)
        {
            int len = (str1[ind1] == str2[ind2]);
            curr[ind2] = ((ind1 == 0 || ind2 == 0 || len == 0) ? (len) : (prev[ind2 - 1] + len));
            max_common_substr = max(max_common_substr, curr[ind2]);
        }

        for (int ind2 = 0; ind2 < str2.size(); ind2++)
        {
            prev[ind2] = curr[ind2];
        }
    }

    return max_common_substr;
}

int main()
{

    return 0;
}