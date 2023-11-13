#include <bits/stdc++.h>
using namespace std;

// memoisation
int fib_memo(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
}

// tabulation
int fib_tabu(int n, vector<int> &dp)
{
    dp[0] = 0, dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// space optimisation
int fib_space(int n)
{
    int curr, sec_prev = 0, prev = 1;

    for (int i = 2; i <= n; i++)
    {
        curr = prev + sec_prev;
        sec_prev = prev;
        prev = curr;
    }

    return curr;
}

int main()
{
    /*
      memoisation - recursion - store in array or matrix
      tabulation - directly store in array or matrix
      space optimization

      Fibbonaci - recursion tree

      overlapping sub problems - memoisation jumps in
      we tend to store the values of sub problems so we don't have to recompute them again & again

    */

    for (int n = 2; n < 30; n++)
    {
        vector<int> dp(n + 1, -1);

        int ans1 = fib_memo(n, dp);
        int ans2 = fib_tabu(n, dp);
        int ans3 = fib_space(n);

        cout << ans1 << " " << ans2 << " " << ans3 << endl;
    }

    return 0;
}