#include <bits/stdc++.h>
using namespace std;

/*
simple approach --> either match with char or ? but in case of * we try by match with curr or curr & prev and so on
*/

class Solution
{
public:
    // memoisation
    bool is_match(int ind1, int ind2, string &s, string &p, vector<vector<int>> &is_Match)
    {
        if (ind1 == -1 && ind2 == -1)
        {
            return true;
        }

        else if (ind2 == -1)
        {
            return false;
        }

        else if (ind1 == -1)
        {
            return ((count(p.begin(), p.begin() + ind2 + 1, '*') == ind2 + 1) ? true : false);
        }

        if (is_Match[ind1][ind2] != -1)
        {
            return (is_Match[ind1][ind2] == 1);
        }

        if (s[ind1] == p[ind2] || p[ind2] == '?')
        {
            bool ans = is_match(ind1 - 1, ind2 - 1, s, p, is_Match);
            is_Match[ind1][ind2] = (ans == true);
            return ans;
        }

        else if (p[ind2] == '*')
        {
            if (is_match(ind1 - 1, ind2, s, p, is_Match))
            {
                is_Match[ind1][ind2] = 1;
                return true;
            }

            bool ans = is_match(ind1, ind2 - 1, s, p, is_Match);
            is_Match[ind1][ind2] = (ans == true);
            return ans;
        }

        is_Match[ind1][ind2] = 0;
        return false;
    }

    bool isMatch(string s, string p)
    {
        vector<vector<int>> is_Match(s.size(), vector<int>(p.size(), -1));
        return is_match(s.size() - 1, p.size() - 1, s, p, is_Match);
    }

    // tabulation
    bool isMatch(string s, string p)
    {
        int n1 = s.size(), n2 = p.size();

        if (n2 == 0)
        {
            return (n1 == 0);
        }

        bool is_all_star[n2];
        bool is_first = false;

        for (int ind2 = 0; ind2 < n2; ind2++)
        {
            if (is_first || p[ind2] != '*')
            {
                is_first = true;
                is_all_star[ind2] = false;
                continue;
            }

            is_all_star[ind2] = true;
        }

        if (n1 == 0)
        {
            return is_all_star[n2 - 1];
        }

        bool does_match[n1][n2];

        for (int ind2 = 0; ind2 < n2; ind2++)
        {
            if (is_first || p[ind2] != '*')
            {
                is_first = true;
                is_all_star[ind2] = false;
                continue;
            }

            is_all_star[ind2] = true;
        }

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                if (s[ind1] == p[ind2] || p[ind2] == '?')
                {
                    does_match[ind1][ind2] = (ind2 == 0) ? ((ind1 == 0) ? true : false) : ((ind1 == 0) ? (is_all_star[ind2 - 1]) : does_match[ind1 - 1][ind2 - 1]);
                    continue;
                }

                else if (p[ind2] == '*')
                {
                    bool val1 = (ind1 == 0) ? (is_all_star[ind2]) : does_match[ind1 - 1][ind2];
                    bool val2 = (ind2 == 0) ? false : does_match[ind1][ind2 - 1];
                    does_match[ind1][ind2] = (val1 || val2);
                    continue;
                }

                does_match[ind1][ind2] = false;
            }
        }

        return does_match[n1 - 1][n2 - 1];
    }

    // space optimization
    bool isMatch(string s, string p)
    {
        int n1 = s.size(), n2 = p.size();

        if (n2 == 0)
        {
            return (n1 == 0);
        }

        bool is_all_star[n2];
        bool is_first = false;

        for (int ind2 = 0; ind2 < n2; ind2++)
        {
            if (is_first || p[ind2] != '*')
            {
                is_first = true;
                is_all_star[ind2] = false;
                continue;
            }

            is_all_star[ind2] = true;
        }

        if (n1 == 0)
        {
            return is_all_star[n2 - 1];
        }

        bool curr_does_match[n2];
        bool prev_does_match[n2];

        for (int ind1 = 0; ind1 < n1; ind1++)
        {
            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                if (s[ind1] == p[ind2] || p[ind2] == '?')
                {
                    curr_does_match[ind2] = (ind2 == 0) ? ((ind1 == 0) ? true : false) : ((ind1 == 0) ? (is_all_star[ind2 - 1]) : prev_does_match[ind2 - 1]);
                    continue;
                }

                else if (p[ind2] == '*')
                {
                    bool val1 = (ind1 == 0) ? (is_all_star[ind2]) : prev_does_match[ind2];
                    bool val2 = (ind2 == 0) ? false : curr_does_match[ind2 - 1];
                    curr_does_match[ind2] = (val1 || val2);
                    continue;
                }

                curr_does_match[ind2] = false;
            }

            for (int ind2 = 0; ind2 < n2; ind2++)
            {
                prev_does_match[ind2] = curr_does_match[ind2];
            }
        }

        return curr_does_match[n2 - 1];
    }
};

int main()
{

    return 0;
}