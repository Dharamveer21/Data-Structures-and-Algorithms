#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[201][10001];

    bool possible_subset(int ind, int sum, vector<int> &nums)
    {
        if (sum == 0)
        {
            return true;
        }

        if (ind < 0)
        {
            return false;
        }

        if (dp[ind][sum] != -1)
        {
            return dp[ind][sum];
        }

        bool ans = false;

        // don't choose ind
        ans = possible_subset(ind - 1, sum, nums);
        
        if (sum - nums[ind] >= 0)
        {
            // choose ind
            ans = ((ans) || (possible_subset(ind - 1, sum - nums[ind], nums)));
        }

        return dp[ind][sum] = ans;
    }

    bool canPartition(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
        {
            return false;
        }

        sum = sum / 2;
        return possible_subset(nums.size() - 1, sum, nums);
    }
};

int main()
{

    return 0;
}