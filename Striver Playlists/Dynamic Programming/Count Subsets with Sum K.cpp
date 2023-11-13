#include <bits/stdc++.h>
using namespace std;

// memoisation
int count_subsets(int ind, int target, vector<int> &nums, vector<vector<int>> &counts)
{
    if (target < 0)
    {
        return 0;
    }

    if (ind == 0)
    {
        return (target == 0 && nums[0] == 0) ? 2 : ((target == 0 || target == nums[0]) ? 1 : 0);
    }

    if (counts[ind][target] != -1)
    {
        return counts[ind][target];
    }

    int count = count_subsets(ind - 1, target, nums, counts) + count_subsets(ind - 1, target - nums[ind], nums, counts);
    return counts[ind][target] = count;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> counts(n, vector<int>(tar + 1, -1));
    return count_subsets(n - 1, tar, num, counts);
}

// tabulation
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> counts(n, vector<int>(tar + 1, 0));

    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            if (ind == 0)
            {
                counts[0][target] = (target == 0 && num[0] == 0) ? 2 : ((target == 0 || target == num[0]) ? 1 : 0);
                continue;
            }

            int count = counts[ind - 1][target] + ((target - num[ind] < 0) ? 0 : counts[ind - 1][target - num[ind]]);
            counts[ind][target] = count;
        }
    }

    return counts[n - 1][tar];
}

// space optimization
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev_counts(tar + 1);
    vector<int> curr_counts(tar + 1);

    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            if (ind == 0)
            {
                curr_counts[target] = (target == 0 && num[0] == 0) ? 2 : ((target == 0 || target == num[0]) ? 1 : 0);
                continue;
            }

            int count = prev_counts[target] + ((target - num[ind] < 0) ? 0 : prev_counts[target - num[ind]]);
            curr_counts[target] = count;
        }

        for (int target = 0; target <= tar; target++)
        {
            prev_counts[target] = curr_counts[target];
        }
    }

    return curr_counts[tar];
}

int main()
{

    return 0;
}