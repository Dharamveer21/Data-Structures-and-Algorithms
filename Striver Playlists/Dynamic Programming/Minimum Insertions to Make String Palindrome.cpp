#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tabulation
    int minInsertions(string s)
    {
        int n = s.size();
        int mini_steps_palindrome[n][n];

        for (int ind1 = n - 1; ind1 >= 0; ind1--)
        {
            for (int ind2 = 0; ind2 < n; ind2++)
            {
                if (ind1 > ind2)
                {
                    mini_steps_palindrome[ind1][ind2] = 0;
                    continue;
                }

                if ((s[ind1] == s[ind2]))
                {
                    mini_steps_palindrome[ind1][ind2] = ((ind1 == n - 1 || ind2 == 0) ? 0 : mini_steps_palindrome[ind1 + 1][ind2 - 1]);
                }

                else
                {
                    mini_steps_palindrome[ind1][ind2] = min(mini_steps_palindrome[ind1 + 1][ind2], mini_steps_palindrome[ind1][ind2 - 1]) + 1;
                }
            }
        }

        return mini_steps_palindrome[0][n - 1];
    }

    // space optimization
    int minInsertions(string s)
    {
        int n = s.size();
        int curr_mini_steps_palindrome[n];
        int prev_mini_steps_palindrome[n];

        for (int ind1 = n - 1; ind1 >= 0; ind1--)
        {
            for (int ind2 = 0; ind2 < n; ind2++)
            {
                if (ind1 > ind2)
                {
                    curr_mini_steps_palindrome[ind2] = 0;
                    continue;
                }

                if ((s[ind1] == s[ind2]))
                {
                    curr_mini_steps_palindrome[ind2] = ((ind1 == n - 1 || ind2 == 0) ? 0 : prev_mini_steps_palindrome[ind2 - 1]);
                }

                else
                {
                    curr_mini_steps_palindrome[ind2] = min(prev_mini_steps_palindrome[ind2], curr_mini_steps_palindrome[ind2 - 1]) + 1;
                }
            }

            for (int ind2 = 0; ind2 < n; ind2++)
            {
                prev_mini_steps_palindrome[ind2] = curr_mini_steps_palindrome[ind2];
            }
        }

        return curr_mini_steps_palindrome[n - 1];
    }
};

int main()
{

    return 0;
}