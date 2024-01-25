#include <bits/stdc++.h>
using namespace std;

void print_lcs(vector<vector<int>> &longest_sequence, string &text1, string &text2)
{
    int rows = longest_sequence.size();
    int cols = longest_sequence[0].size();
    int ind1 = rows - 1, ind2 = cols - 1;
    string ans;

    while (ind1 >= 0 || ind2 >= 0)
    {
        if (text1[ind1] == text2[ind2])
        {
            char ch = text1[ind1];
            ans.push_back(ch);
            ind1--;
            ind2--;
            continue;
        }

        int val1 = ((ind1 == 0) ? (0) : (longest_sequence[ind1 - 1][ind2]));
        int val2 = ((ind2 == 0) ? (0) : (longest_sequence[ind1][ind2 - 1]));

        if (ind1 == ind2 && ind1 == 0)
        {
            break;
        }

        if (val1 >= val2)
        {
            ind1--;
        }

        else
        {
            ind2--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> longest_sequence(text1.size(), vector<int>(text2.size()));

    for (int ind1 = 0; ind1 < text1.size(); ind1++)
    {
        for (int ind2 = 0; ind2 < text2.size(); ind2++)
        {
            int len = (text1[ind1] == text2[ind2]);

            if (ind1 == 0 && ind2 == 0)
            {
                longest_sequence[ind1][ind2] = len;
                continue;
            }

            if (ind1 == 0)
            {
                longest_sequence[ind1][ind2] = max(longest_sequence[ind1][ind2 - 1], len);
                continue;
            }

            if (ind2 == 0)
            {
                longest_sequence[ind1][ind2] = max(longest_sequence[ind1 - 1][ind2], len);
                continue;
            }

            int len1 = longest_sequence[ind1 - 1][ind2];
            int len2 = longest_sequence[ind1][ind2 - 1];
            int len3 = longest_sequence[ind1 - 1][ind2 - 1] + len;

            longest_sequence[ind1][ind2] = max(len3, max(len1, len2));
        }
    }
    
    print_lcs(longest_sequence, text1, text2);
    return longest_sequence[text1.size() - 1][text2.size() - 1];
}

int main()
{

    return 0;
}