#include<bits/stdc++.h>
using namespace std;

/*
   use the 1D array for which you check all prev_seq which can be part of that sequence
   we can print the lis using this array by hash_array
*/

class Solution
{
public:
    void PrintLIS(vector<int> &nums)
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

        // printing lis
        while (index != -1)
        {
            long_inc_subseq.push_back(nums[index]);
            index = hash_arr[index];
        }
        
        reverse(long_inc_subseq.begin(), long_inc_subseq.end());

        for (int it : long_inc_subseq)
        {
            cout << it << " ";
        }
    }
};

int main()
{
    
    return 0;
}