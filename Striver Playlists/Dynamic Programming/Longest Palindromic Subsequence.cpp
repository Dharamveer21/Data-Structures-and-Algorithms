#include <bits/stdc++.h>
using namespace std;

/*
Two approaches -- 1st is reverse the string & find the longest common subsequence between s & reverse s
2nd approach -- using conecpt of palindrome start from first & last element
*/

class Solution
{
public:
    // tabulation
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        int longest_palindrome[n][n];

        for (int ind1 = n - 1; ind1 >= 0; ind1--)
        {
            for (int ind2 = 0; ind2 < n; ind2++)
            {
                if (ind1 > ind2)
                {
                    longest_palindrome[ind1][ind2] = 0;
                    continue;
                }

                if ((s[ind1] == s[ind2]))
                {
                    int len1 = ((ind1 == n - 1 || ind2 == 0) ? 0 : longest_palindrome[ind1 + 1][ind2 - 1]);
                    longest_palindrome[ind1][ind2] = len1 + (s[ind1] == s[ind2]) + (ind1 != ind2);
                }

                else
                {
                    longest_palindrome[ind1][ind2] = max(longest_palindrome[ind1 + 1][ind2], longest_palindrome[ind1][ind2 - 1]);
                }
            }
        }

        return longest_palindrome[0][n - 1];
    }

    // space optimization
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        int curr_longest_palindrome[n];
        int prev_longest_palindrome[n];

        for (int ind1 = n - 1; ind1 >= 0; ind1--)
        {
            for (int ind2 = 0; ind2 < n; ind2++)
            {
                if (ind1 > ind2)
                {
                    curr_longest_palindrome[ind2] = 0;
                    continue;
                }

                if ((s[ind1] == s[ind2]))
                {
                    int len1 = ((ind1 == n - 1 || ind2 == 0) ? 0 : prev_longest_palindrome[ind2 - 1]);
                    curr_longest_palindrome[ind2] = len1 + (s[ind1] == s[ind2]) + (ind1 != ind2);
                }

                else
                {
                    curr_longest_palindrome[ind2] = max(prev_longest_palindrome[ind2], curr_longest_palindrome[ind2 - 1]);
                }
            }

            for (int ind2 = 0; ind2 < n; ind2++)
            {
                prev_longest_palindrome[ind2] = curr_longest_palindrome[ind2];
            }
        }

        return curr_longest_palindrome[n - 1];
    }
};

int main()
{

    return 0;
}