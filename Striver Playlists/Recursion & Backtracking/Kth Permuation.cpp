#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Kth_permutation(int n, int k, vector<bool> &digits, vector<int> &fact, string &ans)
    {
        if (n == 0)
        {
            return;
        }

        int val = fact[n - 1];
        int to_jump = k / val;
        int new_k = k % val;

        int count = 0;

        for (int i = 0; i < digits.size(); i++)
        {
            if (count == to_jump && !digits[i])
            {
                digits[i] = true;
                char ch = '0' + (i + 1);
                ans.push_back(ch);
                Kth_permutation(n - 1, new_k, digits, fact, ans);
                break;
            }

            if (!digits[i])
            {
                count++;
            }
        }
    }

    string getPermutation(int n, int k)
    {
        vector<bool> digits(n, false);
        vector<int> fact(n, 1);
        string ans;

        for (int i = 1; i <= n - 1; i++)
        {
            fact[i] = i * fact[i - 1];
        }

        Kth_permutation(n, k - 1, digits, fact, ans);
        return ans;
    }
};