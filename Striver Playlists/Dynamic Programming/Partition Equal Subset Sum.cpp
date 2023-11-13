#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    bool subset_with_target_sum(int ind, int target, vector<int> &arr, vector<vector<int>> &isPossible)
    {
        if (target == 0)
        {
            return true;
        }

        if (ind < 0 || target < 0)
        {
            return false;
        }

        if (isPossible[ind][target] != 0)
        {
            return (isPossible[ind][target] == 1);
        }

        if (subset_with_target_sum(ind - 1, target - arr[ind], arr, isPossible) || subset_with_target_sum(ind - 1, target, arr, isPossible))
        {
            isPossible[ind][target] = 1;
            return true;
        }

        isPossible[ind][target] = -1;
        return false;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);

        if (k & 1)
        {
            return false;
        }

        vector<vector<int>> isPossible(n, vector<int>((k / 2) + 1, 0));
        return subset_with_target_sum(n - 1, k / 2, nums, isPossible);
    }

    // tabulation
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);

        if (k & 1)
        {
            return false;
        }

        vector<vector<int>> isPossible(n, vector<int>((k / 2) + 1, 0));

        for (int ind = 0; ind < n; ind++)
        {
            for (int target = 0; target <= (k / 2); target++)
            {
                if (target == 0)
                {
                    isPossible[ind][target] = 1;
                    continue;
                }

                if (ind == 0)
                {
                    if (target == nums[ind])
                    {
                        isPossible[ind][target] = 1;
                        continue;
                    }

                    isPossible[ind][target] = -1;
                    continue;
                }

                int inc = -1, exc;

                if (target - nums[ind] >= 0)
                {
                    inc = isPossible[ind - 1][target - nums[ind]];
                }

                exc = isPossible[ind - 1][target];

                if (inc == 1 || exc == 1)
                {
                    isPossible[ind][target] = 1;
                    continue;
                }

                isPossible[ind][target] = -1;
            }
        }

        return isPossible[n - 1][k / 2] == 1;
    }

    // space optimization
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);

        if (k & 1)
        {
            return false;
        }

        vector<int> curr_isPossible((k / 2) + 1, 0);
        vector<int> prev_isPossible((k / 2) + 1, 0);

        for (int ind = 0; ind < n; ind++)
        {
            for (int target = 0; target <= k / 2; target++)
            {
                if (target == 0)
                {
                    curr_isPossible[target] = 1;
                    continue;
                }

                if (ind == 0)
                {
                    if (target == nums[ind])
                    {
                        curr_isPossible[target] = 1;
                        continue;
                    }

                    curr_isPossible[target] = -1;
                    continue;
                }

                int inc = -1, exc;

                if (target - nums[ind] >= 0)
                {
                    inc = prev_isPossible[target - nums[ind]];
                }

                exc = prev_isPossible[target];

                if (inc == 1 || exc == 1)
                {
                    curr_isPossible[target] = 1;
                    continue;
                }

                curr_isPossible[target] = -1;
            }

            for (int target = 0; target <= k / 2; target++)
            {
                prev_isPossible[target] = curr_isPossible[target];
            }
        }

        return curr_isPossible[k / 2] == 1;
    }
};

int main()
{

    return 0;
}