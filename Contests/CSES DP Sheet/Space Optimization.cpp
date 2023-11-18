#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

// Only focus on the required states discard the other ones

// Coin Combination II in spcae optmization
int distinct_ways(int n, int x, vector<int> &coins)
{
    // vector<vector<int>> ways(n + 1, vector<int>(x + 1));
    vector<int> next(x + 1, 0);
    vector<int> curr(x + 1, 0);
    next[0] = 1, curr[0] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int value = 1; value <= x; value++)
        {
            int coin = coins[i];
            int skip = next[value] % M;
            int pick = 0;

            if (value >= coin)
            {
                pick = curr[value - coin] % M;
            }
            
            curr[value] = (skip + 0LL + pick) % M;
        }

        next = curr;
    }

    return (next[x] % M);
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
