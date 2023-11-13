#include <bits/stdc++.h>
using namespace std;

/*
Three approaches
1st -- use prev_ind & ind to find the solution
*/

class Solution
{
public:
    // memoisation
    int long_inc_subseq(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &long_inc_seq)
    {
        int n = nums.size();
        
        if (ind == -1)
        {
            return 0;
        }

        if (long_inc_seq[ind][prev_ind] != -1)
        {
            return long_inc_seq[ind][prev_ind];
        }

        int take_len = 0, not_take_len = 0;

        // take it
        int curr_val = nums[ind];
        int prev_val = (prev_ind == n) ? INT_MAX : nums[prev_ind];

        if (curr_val < prev_val)
        {
            take_len = 1 + long_inc_subseq(ind - 1, ind, nums, long_inc_seq);
        }

        // not take
        not_take_len = long_inc_subseq(ind - 1, prev_ind, nums, long_inc_seq);

        int len = max(take_len, not_take_len);
        return long_inc_seq[ind][prev_ind] = len;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> long_inc_seq(n, vector<int>(n + 1, -1));
        return long_inc_subseq(n - 1, n, nums, long_inc_seq);
    }
    
    // tabulation
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(INT_MAX);
        int long_inc_seq[n][n + 1];

        for (int ind = 0; ind < n; ind++)
        {
            for (int prev_ind = ind + 1; prev_ind <= n; prev_ind++)
            {
                int take_len = ((nums[ind] >= nums[prev_ind]) ? 0 : 1 + ((ind == 0) ? 0 : long_inc_seq[ind - 1][ind]));
                int not_take_len = ((ind == 0) ? 0 : long_inc_seq[ind - 1][prev_ind]);

                long_inc_seq[ind][prev_ind] = max(take_len, not_take_len);
            }
        }

        return long_inc_seq[n - 1][n];
    }

    // space optimization
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(INT_MAX);
        int prev_long_inc_seq[n + 1];
        int curr_long_inc_seq[n + 1];

        for (int ind = 0; ind < n; ind++)
        {
            for (int prev_ind = ind + 1; prev_ind <= n; prev_ind++)
            {
                int take_len = ((nums[ind] >= nums[prev_ind]) ? 0 : 1 + ((ind == 0) ? 0 : prev_long_inc_seq[ind]));
                int not_take_len = ((ind == 0) ? 0 : prev_long_inc_seq[prev_ind]);

                curr_long_inc_seq[prev_ind] = max(take_len, not_take_len);
            }

            for (int prev_ind = ind + 1; prev_ind <= n; prev_ind++)
            {
                prev_long_inc_seq[prev_ind] = curr_long_inc_seq[prev_ind];
            }
        }

        return curr_long_inc_seq[n];
    }
};

/*
   2nd -- use the 1D array for which you check all prev_seq which can be part of that sequence
   we can print the lis using this array by hash_array
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int long_inc_seq[n], hash_arr[n];
        int max_len = 1, index = -1;
        vector<int> long_inc_subseq;

        for (int ind = 0; ind < n; ind++)
        {
            int long_len = 0;
            long_inc_seq[ind] = 1;
            hash_arr[ind] = -1;

            for (int prev_ind = 0; prev_ind < ind; prev_ind++)
            {
                if (nums[prev_ind] >= nums[ind])
                {
                    continue;
                }

                if (long_inc_seq[prev_ind] >= long_len)
                {
                    long_len = long_inc_seq[prev_ind];
                    hash_arr[ind] = prev_ind;
                }
            }

            long_inc_seq[ind] += long_len;

            if (long_inc_seq[ind] >= max_len)
            {
                max_len = long_inc_seq[ind];
                index = ind;
            }
        }
        
        return max_len;
    }
};

int main()
{

    return 0;
}