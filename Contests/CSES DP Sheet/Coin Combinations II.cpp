#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

/*
Approach -- here we think of order of coins , c1 will never occur before c2

dp[i,k] -- no of distinct ways of making sum 'k' using all coins from (ci to cn)
dp[i,k] = dp[i,k-ci] (pick) + dp[i+1,k] (not pick)
base case -- dp[i,0] = 1
*/

// TC : O(n*x) * O(1) = O(n*x)
// SC : O(n*x)

int distinct_ways(int n, int x, vector<int> &coins)
{
    vector<vector<int>> ways(n + 1, vector<int>(x + 1));

    for (int i = 0; i < n; i++)
    {
        ways[i][0] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int value = 1; value <= x; value++)
        {
            int coin = coins[i];
            int skip = ways[i + 1][value] % M;
            int pick = 0;

            if (value >= coin)
            {
                pick = ways[i][value - coin] % M;
            }

            ways[i][value] = (skip + 0LL + pick) % M;
        }
    }

    return (ways[0][x] % M);
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int ans = distinct_ways(n, x, coins);
    cout << ans << endl;

    return 0;
}