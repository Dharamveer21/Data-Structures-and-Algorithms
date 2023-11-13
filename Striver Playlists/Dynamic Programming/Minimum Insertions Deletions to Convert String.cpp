#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tabulation
    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();

        int mini_operations_string_equal[n1][n2];

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                if (word1[ind1] == word2[ind2])
                {
                    int len1 = (ind1 == 0 || ind2 == 0) ? (ind1 + ind2) : mini_operations_string_equal[ind1 - 1][ind2 - 1];
                    mini_operations_string_equal[ind1][ind2] = len1;
                }

                else
                {
                    int len2 = (ind1 == 0) ? (ind2 + 1) : mini_operations_string_equal[ind1 - 1][ind2];
                    int len3 = (ind2 == 0) ? (ind1 + 1) : mini_operations_string_equal[ind1][ind2 - 1];

                    mini_operations_string_equal[ind1][ind2] = min(len2, len3) + 1;
                }
            }
        }

        return mini_operations_string_equal[n1 - 1][n2 - 1];
    }

    // space optimization
    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();

        int curr_mini_operations_string_equal[n2];
        int prev_mini_operations_string_equal[n2];

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                if (word1[ind1] == word2[ind2])
                {
                    int len1 = (ind1 == 0 || ind2 == 0) ? (ind1 + ind2) : prev_mini_operations_string_equal[ind2 - 1];
                    curr_mini_operations_string_equal[ind2] = len1;
                }

                else
                {
                    int len2 = (ind1 == 0) ? (ind2 + 1) : prev_mini_operations_string_equal[ind2];
                    int len3 = (ind2 == 0) ? (ind1 + 1) : curr_mini_operations_string_equal[ind2 - 1];

                    curr_mini_operations_string_equal[ind2] = min(len2, len3) + 1;
                }
            }

            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                prev_mini_operations_string_equal[ind2] = curr_mini_operations_string_equal[ind2];
            }
        }

        return curr_mini_operations_string_equal[n2 - 1];
    }
};

int main()
{

    return 0;
}