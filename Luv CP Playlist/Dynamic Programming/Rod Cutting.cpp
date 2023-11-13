#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001];
    int max_value(int len, int price[], int n)
    {
        if (len == 0)
        {
            return 0;
        }

        if (dp[len] != -1)
        {
            return dp[len];
        }

        int ans = 0;

        for (int len_to_cut = 1; len_to_cut <= n; len_to_cut++)
        {
            if (len - len_to_cut >= 0)
            {
                ans = max(ans, max_value(len - len_to_cut, price, n) + price[len_to_cut - 1]);
            }
        }

        return dp[len] = ans;
    }

    int cutRod(int price[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return max_value(n, price, n);
    }
};

int main()
{

    return 0;
}
