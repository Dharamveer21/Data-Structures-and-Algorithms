#include <bits/stdc++.h>
using namespace std;

// coin change 1 
class Solution
{
public:
    int min_coins(int amount, vector<int> &coins, int min_coin[])
    {
        if (min_coin[amount] != -1)
        {
            return min_coin[amount];
        }
         
        int ans = INT_MAX;

        for (int coin : coins)
        {
            if (amount - coin >= 0)
            {
                ans = min(ans + 0LL, min_coins(amount - coin, coins, min_coin) + 1LL);
            }
        }

        return min_coin[amount] = ans;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        const int N = 1e4 + 10;
        int min_coin[N] = {0};

        for (int i = 1; i < N; i++)
        {
            min_coin[i] = -1;
        }

        int ans = min_coins(amount, coins, min_coin);
        return (ans == INT_MAX ? -1 : ans);
    }
};

// coin change 2 
class Solution
{
public:
    int ways[301][5001];

    int possible_ways(int ind, int amount, vector<int> &coins)
    {
        if (amount == 0)
        {
            return 1;
        }

        if (ind < 0)
        {
            return 0;
        }

        if (ways[ind][amount] != -1)
        {
            return ways[ind][amount];
        }

        int total_ways = 0;

        for (int coin = 0; coin <= amount; coin += coins[ind])
        {
            if (amount - coin >= 0)
            { 
                total_ways += possible_ways(ind - 1, amount - coin, coins);
            }
        }

        return ways[ind][amount] = total_ways;
    }

    int change(int amount, vector<int> &coins)
    {
        for (int i = 0; i < 301; i++)
        {
            for (int j = 0; j < 5001; j++)
            {
                ways[i][j] = -1;
            }
        }

        int total_ways = possible_ways(coins.size() - 1, amount, coins);
        return total_ways;
    }
};

int main()
{

    return 0;
}