#include <bits/stdc++.h>
using namespace std;

/*
In these type of problems express recursion in terms of ind & target
there are two possibilities whether the element at that index is part of subsequence or not
*/

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

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> isPossible(n, vector<int>(k + 1, 0));
    return subset_with_target_sum(n - 1, k, arr, isPossible);
}

// tabulation
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> isPossible(n, vector<int>(k + 1, 0));

    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            if (target == 0)
            {
                isPossible[ind][target] = 1;
                continue;
            }

            if (ind == 0)
            {
                if (target == arr[ind])
                {
                    isPossible[ind][target] = 1;
                    continue;
                }

                isPossible[ind][target] = -1;
                continue;
            }

            int inc = -1, exc;

            if (target - arr[ind] >= 0)
            {
                inc = isPossible[ind - 1][target - arr[ind]];
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

    return isPossible[n - 1][k] == 1;
}

// space optimization
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<int> curr_isPossible(k + 1, 0);
    vector<int> prev_isPossible(k + 1, 0);

    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            if (target == 0)
            {
                curr_isPossible[target] = 1;
                continue;
            }

            if (ind == 0)
            {
                if (target == arr[ind])
                {
                    curr_isPossible[target] = 1;
                    continue;
                }

                curr_isPossible[target] = -1;
                continue;
            }

            int inc = -1, exc;

            if (target - arr[ind] >= 0)
            {
                inc = prev_isPossible[target - arr[ind]];
            }

            exc = prev_isPossible[target];

            if (inc == 1 || exc == 1)
            {
                curr_isPossible[target] = 1;
                continue;
            }

            curr_isPossible[target] = -1;
        }

        for (int target = 0; target <= k; target++)
        {
            prev_isPossible[target] = curr_isPossible[target];
        }
    }

    return curr_isPossible[k] == 1;
}

int main()
{

    return 0;
}