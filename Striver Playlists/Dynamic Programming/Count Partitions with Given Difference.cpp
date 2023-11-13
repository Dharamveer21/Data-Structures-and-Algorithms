#include <bits/stdc++.h>
using namespace std;

// memoisation
int mod = 1e9 + 7;
int count_subsets(int ind, int target, vector<int> &arr, vector<vector<int>> &counts)
{
    if (target < 0)
    {
        return 0;
    }

    if (ind == 0)
    {
        return ((target == 0 && arr[ind] == 0) ? 2 : ((target == 0 || target == arr[ind]) ? 1 : 0));
    }

    if (counts[ind][target] != -1)
    {
        return counts[ind][target];
    }

    int count = ((count_subsets(ind - 1, target, arr, counts)) % mod + (count_subsets(ind - 1, target - arr[ind], arr, counts)) % mod) % mod;
    return counts[ind][target] = count;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (((sum - d) < 0) || (d & 1) != (sum & 1))
    {
        return 0;
    }

    int tar = (sum + d) / 2;
    vector<vector<int>> counts(n, vector<int>(tar + 1, -1));
    return count_subsets(n - 1, tar, arr, counts);
}

// tabulation
int countPartitions(int n, int d, vector<int> &arr)
{
    int mod = 1e9 + 7;
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (((sum - d) < 0) || (d & 1) != (sum & 1))
    {
        return 0;
    }

    int tar = (sum + d) / 2;
    vector<vector<int>> counts(n, vector<int>(tar + 1, -1));

    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            if (ind == 0)
            {
                counts[ind][target] = ((target == 0 && arr[ind] == 0) ? 2 : ((target == 0 || target == arr[ind]) ? 1 : 0));
                continue;
            }

            int count = ((counts[ind - 1][target]) % mod + (((target - arr[ind]) < 0) ? 0 : counts[ind - 1][target - arr[ind]]) % mod) % mod;
            counts[ind][target] = count;
        }
    }

    return counts[n - 1][tar];
}

// space optimization
int countPartitions(int n, int d, vector<int> &arr)
{
    int mod = 1e9 + 7;
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (((sum - d) < 0) || (d & 1) != (sum & 1))
    {
        return 0;
    }

    int tar = (sum + d) / 2;
    vector<int> prev_counts(tar + 1);
    vector<int> curr_counts(tar + 1);

    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            if (ind == 0)
            {
                curr_counts[target] = ((target == 0 && arr[ind] == 0) ? 2 : ((target == 0 || target == arr[ind]) ? 1 : 0));
                continue;
            }

            int count = ((prev_counts[target]) % mod + (((target - arr[ind]) < 0) ? 0 : prev_counts[target - arr[ind]]) % mod) % mod;
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
