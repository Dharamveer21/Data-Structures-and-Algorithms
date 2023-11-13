#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int longest_common_subsequence(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &longest_sequence)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }

        if (longest_sequence[ind1][ind2] != -1)
        {
            return longest_sequence[ind1][ind2];
        }

        int len1 = longest_common_subsequence(ind1 - 1, ind2, str1, str2, longest_sequence);
        int len2 = longest_common_subsequence(ind1, ind2 - 1, str1, str2, longest_sequence);
        int len3 = longest_common_subsequence(ind1 - 1, ind2 - 1, str1, str2, longest_sequence) + (str1[ind1] == str2[ind2]);

        return longest_sequence[ind1][ind2] = max(len3, max(len1, len2));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> longest_sequence(text1.size(), vector<int>(text2.size(), -1));
        return longest_common_subsequence(text1.size() - 1, text2.size() - 1, text1, text2, longest_sequence);
    }

    // tabulation
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

        return longest_sequence[text1.size() - 1][text2.size() - 1];
    }

    // space optimization
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<int> prev_seq(text2.size());
        vector<int> curr_seq(text2.size());

        for (int ind1 = 0; ind1 < text1.size(); ind1++)
        {
            for (int ind2 = 0; ind2 < text2.size(); ind2++)
            {
                int len = (text1[ind1] == text2[ind2]);

                if (ind1 == 0 && ind2 == 0)
                {
                    curr_seq[ind2] = len;
                    continue;
                }

                if (ind1 == 0)
                {
                    curr_seq[ind2] = max(curr_seq[ind2 - 1], len);
                    continue;
                }

                if (ind2 == 0)
                {
                    curr_seq[ind2] = max(prev_seq[ind2], len);
                    continue;
                }

                int len1 = prev_seq[ind2];
                int len2 = curr_seq[ind2 - 1];
                int len3 = prev_seq[ind2 - 1] + len;

                curr_seq[ind2] = max(len3, max(len1, len2));
            }

            for (int ind2 = 0; ind2 < text2.size(); ind2++)
            {
                prev_seq[ind2] = curr_seq[ind2];
            }
        }

        return curr_seq[text2.size() - 1];
    }
};

int main()
{

    return 0;
}