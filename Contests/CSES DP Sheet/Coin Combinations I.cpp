#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

/*
Approach
dp[k] -- number of ways of creating a sum
dp[k] = dp[k-c1] + dp[k-c2] + dp[k-c3] + .. + dp[k-cn]
base case -- dp[0] = 1;
*/

// TC : O(x) * O(n) = O(x*n)
// SC : O(x)

int all_possible_ways(int n, int x, vector<int> &coins)
{
    vector<int> ways(x + 1, 0);
    ways[0] = 1;

    for (int value = 1; value <= x; value++)
    {
        for (int &coin : coins)
        {
            if (value >= coin)
            {
                ways[value] = (ways[value] + 0LL + ways[value - coin]) % M;
            }
        }
    }

    return (ways[x] % M);
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

    int total_ways = all_possible_ways(n, x, coins);
    cout << total_ways;

    return 0;
}