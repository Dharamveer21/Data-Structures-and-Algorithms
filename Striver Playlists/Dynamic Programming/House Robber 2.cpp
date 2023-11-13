#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // space optimization
    int loot(vector<int> &nums)
    {
        int n = nums.size();
        int curr, prev, sec_prev;
        sec_prev = nums[0];
        curr = prev = max(sec_prev, nums[1]);

        for (int ind = 2; ind < n; ind++)
        {
            // don't choose ind
            int loot_exc = prev;

            // choose ind
            int loot_inc = sec_prev + nums[ind];

            curr = max(loot_exc, loot_inc);

            sec_prev = prev;
            prev = curr;
        }

        return curr;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> temp1, temp2;

        for (int i = 0; i < n - 1; i++)
        {
            temp1.push_back(nums[i]);
        }

        for (int i = 1; i < n; i++)
        {
            temp2.push_back(nums[i]);
        }

        int ans1 = loot(temp1);
        int ans2 = loot(temp2);

        return max(ans1, ans2);
    }
};

int main()
{

    return 0;
}