#include <bits/stdc++.h>
using namespace std;

/*
in this problem we first find the last row of tabulation will give us that every num between 0 & sum/2
is possible to be made as subset sum from the given array
among them which are possible are used to cal the minimum diff
*/

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int k = sum / 2;

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

    int min_diff = INT_MAX;

    for (int target = 0; target <= k; target++)
    {
        if (curr_isPossible[target] == 1)
        {
            int diff = abs(2 * target - sum);
            min_diff = min(min_diff, diff);
        }
    }
    
    return min_diff;
}

int main()
{

    return 0;
}