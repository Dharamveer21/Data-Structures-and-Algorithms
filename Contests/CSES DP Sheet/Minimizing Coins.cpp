#include <bits/stdc++.h>
using namespace std;
/*
Approach
dp[k] -- minimum no of coins to construct value k
dp[k] = min(dp[k-c1],dp[k-c2],....,dp[k-cn]) + 1
where c1,c2,c3,...cn are the possible coins
base case -- dp[0] = 0
*/

// TC : no of states * average transition times -- O(x) * O(n) = O(n*x) where x is the given value to be created & n is no of coins
// SC : no of states -- O(x)

int minimum_coins(int n, int x, vector<int> &coins)
{
    vector<int> coins_to_construct(x + 1, 1e9);
    coins_to_construct[0] = 0;

    for (int value = 1; value <= x; value++)
    {
        for (int &coin : coins)
        {
            if (value >= coin)
            {
                coins_to_construct[value] = min(coins_to_construct[value], coins_to_construct[value - coin] + 1);
            }
        }
    }

    return (coins_to_construct[x] == 1e9 ? -1 : coins_to_construct[x]);
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

    int ans = minimum_coins(n, x, coins);
    cout << ans << endl;

    return 0;
}