#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // brute force
        int n = nums.size();
        int mx_sum = INT_MIN;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            mx_sum = mx_sum < sum ? sum : mx_sum;

            if (sum < 0)
            {
                sum = 0;
            }
        }

        return mx_sum;
    }
};

int main()
{

    return 0;
}