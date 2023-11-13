#include <bits/stdc++.h>
using namespace std;

/*
sum of ways to ways to reach the elements smaller than it && elements with seq length exactly 1 less than it before it
*/

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int long_inc_seq[n];
        int ways_to_reach[n];
        int num_of_subseq = 0;
        int max_len = 0;

        for (int i = 0; i < n; i++)
        {
            int len = 0;
            long_inc_seq[i] = 1;

            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    len = max(len, long_inc_seq[j]);
                }
            }

            long_inc_seq[i] += len;
            max_len = max(max_len, long_inc_seq[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (long_inc_seq[i] == 1)
            {
                ways_to_reach[i] = 1;
                continue;
            }

            ways_to_reach[i] = 0;
            int ways = 0;

            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && long_inc_seq[j] == long_inc_seq[i] - 1)
                {
                    ways += ways_to_reach[j];
                }
            }

            ways_to_reach[i] = ways;
        }

        for (int i = 0; i < n; i++)
        {
            if (long_inc_seq[i] == max_len)
            {
                num_of_subseq += ways_to_reach[i];
            }
        }

        return num_of_subseq;
    }
};

int main()
{

    return 0;
}