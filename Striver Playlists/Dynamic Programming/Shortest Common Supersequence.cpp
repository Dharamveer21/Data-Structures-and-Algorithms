#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> longest_common_subsequnece(string &str1, string &str2)
    {
        int n1 = str1.size(), n2 = str2.size();
        int longest_subsequence[n1][n2];

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                if (str1[ind1] == str2[ind2])
                {
                    int len1 = (ind1 == 0 || ind2 == 0) ? 0 : longest_subsequence[ind1 - 1][ind2 - 1];
                    longest_subsequence[ind1][ind2] = len1 + 1;
                }

                else
                {
                    int len2 = (ind1 == 0) ? 0 : longest_subsequence[ind1 - 1][ind2];
                    int len3 = (ind2 == 0) ? 0 : longest_subsequence[ind1][ind2 - 1];

                    longest_subsequence[ind1][ind2] = max(len2, len3);
                }
            }
        }

        int ind1 = n1 - 1, ind2 = n2 - 1;
        vector<pair<int, int>> long_comm_seq;

        while (ind1 >= 0 && ind2 >= 0)
        {
            if (str1[ind1] == str2[ind2])
            {
                long_comm_seq.push_back({ind1, ind2});
                ind1--;
                ind2--;
            }

            else
            {
                int val1 = (ind1 == 0) ? 0 : longest_subsequence[ind1 - 1][ind2];
                int val2 = (ind2 == 0) ? 0 : longest_subsequence[ind1][ind2 - 1];

                if (val1 >= val2)
                {
                    ind1--;
                }

                else
                {
                    ind2--;
                }
            }
        }

        reverse(long_comm_seq.begin(), long_comm_seq.end());
        return long_comm_seq;
    }

    string shortestCommonSupersequence(string str1, string str2)
    {
        vector<pair<int, int>> long_comm_seq = longest_common_subsequnece(str1, str2);
        int n1 = str1.size(), n2 = str2.size();
        int ind1 = 0, ind2 = 0;
        string ans;

        for (auto &it : long_comm_seq)
        {
            int index1 = it.first;
            int index2 = it.second;

            while (ind1 < index1)
            {
                char ch = str1[ind1];
                ans.push_back(ch);
                ind1++;
            }

            while (ind2 < index2)
            {
                char ch = str2[ind2];
                ans.push_back(ch);
                ind2++;
            }

            char ch = str1[index1];
            ans.push_back(ch);
            ind1++;
            ind2++;
        }

        while (ind1 < n1)
        {
            char ch = str1[ind1];
            ans.push_back(ch);
            ind1++;
        }

        while (ind2 < n2)
        {
            char ch = str2[ind2];
            ans.push_back(ch);
            ind2++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}