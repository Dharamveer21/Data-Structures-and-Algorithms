#include <bits/stdc++.h>
using namespace std;

/* using front partition otherwise it will give us tle*/
/*find 1st palindrome parts and pass on recurrsion the next one*/
/*1D DP Problem*/

/* using front partition otherwise it will give us tle*/
/*find 1st palindrome parts and pass on recurrsion the next one*/

class Solution
{
public:
    // memoisation
    bool is_palindrome(int lo, int hi, string &str)
    {
        int start = lo, end = hi;

        while (start <= end)
        {
            if (str[start++] != str[end--])
            {
                return false;
            }
        }

        return true;
    }

    int mini_partition(int ind, string &str, vector<int> &min_cut)
    {
        int n = str.size();

        if (ind == n)
        {
            return -1;
        }

        if (min_cut[ind] != -1)
        {
            return min_cut[ind];
        }

        int mini_part = n - ind - 1;

        for (int part = ind; part < n; part++)
        {
            if (is_palindrome(ind, part, str))
            {
                mini_part = min(mini_part, (1 + mini_partition(part + 1, str, min_cut)));
            }
        }

        return min_cut[ind] = mini_part;
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<int> min_cut(n, -1);
        return mini_partition(0, s, min_cut);
    }

    // tabulation
    int minCut(string s)
    {
        int n = s.size();
        int min_cut[n];

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int mini_part = n - ind - 1;

            for (int part = ind; part < n; part++)
            {
                if (is_palindrome(ind, part, s))
                {
                    mini_part = min(mini_part, (1 + ((part == n - 1) ? -1 : min_cut[part + 1])));
                }
            }

            min_cut[ind] = mini_part;
        }

        return min_cut[0];
    }
};

int main()
{

    return 0;
}