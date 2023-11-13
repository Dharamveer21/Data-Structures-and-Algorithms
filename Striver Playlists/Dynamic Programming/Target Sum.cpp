#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // one way is by recursion
    int total_ways(int ind, int tar, vector<int> &nums)
    {
        if (ind < 0)
        {
            return ((tar == 0) ? 1 : 0);
        }

        int ways = 0, num = nums[ind];
        ways += total_ways(ind - 1, tar - num, nums) + total_ways(ind - 1, tar + num, nums);
        return ways;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        return total_ways(n - 1, target, nums);
    }

    /*
    but we can solve this problem by another method where we can find divide the array into two subsets
    whereas one will contain all elements with positive sign & other will contain all elements with negative sign
    means it will convert into a problem of subset difference
    */

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int tar = (sum + target) / 2;

        if ((tar < 0) || ((sum - target) < 0) || (target & 1) != (sum & 1))
        {
            return 0;
        }

        vector<int> prev_counts(tar + 1);
        vector<int> curr_counts(tar + 1);

        for (int ind = 0; ind < n; ind++)
        {
            for (int targ = 0; targ <= tar; targ++)
            {
                if (ind == 0)
                {
                    curr_counts[targ] = ((targ == 0 && nums[ind] == 0) ? 2 : ((targ == 0 || targ == nums[ind]) ? 1 : 0));
                    continue;
                }

                int count = ((prev_counts[targ]) + (((targ - nums[ind]) < 0) ? 0 : prev_counts[targ - nums[ind]]));
                curr_counts[targ] = count;
            }

            for (int targ = 0; targ <= tar; targ++)
            {
                prev_counts[targ] = curr_counts[targ];
            }
        }

        return curr_counts[tar];
    }
};

int main()
{

    return 0;
}