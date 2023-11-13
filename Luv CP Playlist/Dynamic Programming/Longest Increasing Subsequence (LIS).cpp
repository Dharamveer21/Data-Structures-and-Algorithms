#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int long_incre_subs(int i, vector<int> &nums, int lis[])
    {
        if (lis[i] != -1)
        {
            return lis[i];
        }

        int ans = 1;

        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                ans = max(ans, long_incre_subs(j, nums, lis) + 1);
            }
        }

        return lis[i] = ans;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int lis[n];
        int len_long_incr_subs = 1;

        for (int i = 1; i < n; i++)
        {
            lis[i] = -1;
        }

        lis[0] = 0;

        for (int i = 0; i < n; i++)
        {
            len_long_incr_subs = max(len_long_incr_subs, long_incre_subs(i, nums, lis));
        }

        return len_long_incr_subs;
    }
};

int main()
{

    return 0;
}