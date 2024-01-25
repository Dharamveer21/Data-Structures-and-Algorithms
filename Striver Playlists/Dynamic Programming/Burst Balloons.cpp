#include <bits/stdc++.h>
using namespace std;

/*
Partition Dp burst left balloons , right balloons & at last burst my own baloon so that i won't affect other parts
*/

class Solution
{
public:
    // memoisation
    int max_coins(int lo, int hi, vector<int> &nums, vector<vector<int>> &maxi_coins)
    {
        if (lo > hi)
        {
            return 0;
        }

        if (maxi_coins[lo][hi] != -1)
        {
            return maxi_coins[lo][hi];
        }

        int maxcoins = 0;

        for (int burst = lo; burst <= hi; burst++)
        {
            int left_burst = max_coins(lo, burst - 1, nums, maxi_coins);
            int right_burst = max_coins(burst + 1, hi, nums, maxi_coins);

            int coins = ((lo == 0) ? 1 : nums[lo - 1]) * nums[burst] * ((hi == nums.size() - 1) ? 1 : nums[hi + 1]);
            coins += left_burst + right_burst;

            maxcoins = max(maxcoins, coins);
        }

        return maxi_coins[lo][hi] = maxcoins;
    }

    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> maxi_coins(n, vector<int>(n, -1));
        return max_coins(0, n - 1, nums, maxi_coins);
    }

    // tabulation
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        int maxi_coins[n][n];

        for (int lo = n - 1; lo >= 0; lo--)
        {
            for (int hi = lo; hi < n; hi++)
            {
                int maxcoins = 0;

                for (int burst = lo; burst <= hi; burst++)
                {
                    int left_burst = ((burst == lo) ? 0 : maxi_coins[lo][burst - 1]);
                    int right_burst = ((burst == hi) ? 0 : maxi_coins[burst + 1][hi]);

                    int coins = ((lo == 0) ? 1 : nums[lo - 1]) * nums[burst] * ((hi == n - 1) ? 1 : nums[hi + 1]);
                    coins += left_burst + right_burst;

                    maxcoins = max(maxcoins, coins);
                }

                maxi_coins[lo][hi] = maxcoins;
            }
        }

        return maxi_coins[0][n - 1];
    }
};

int main()
{

    return 0;
}