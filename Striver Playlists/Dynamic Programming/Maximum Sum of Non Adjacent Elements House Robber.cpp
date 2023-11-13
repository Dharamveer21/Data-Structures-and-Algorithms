#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int max_loot(int ind, vector<int> &nums, vector<int> &loot)
    {
        if (loot[ind] != -1)
        {
            return loot[ind];
        }
        
        // don't choose ind
        int loot_exc = max_loot(ind - 1, nums, loot);
          
        // choose ind
        int loot_inc = max_loot(ind - 2, nums, loot) + nums[ind];

        return loot[ind] = max(loot_exc, loot_inc);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        vector<int> loot(n, -1);
        loot[0] = nums[0];
        loot[1] = max(loot[0], nums[1]);

        return max_loot(n - 1, nums, loot);
    }

    // tabulation
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        vector<int> loot(n, -1);
        loot[0] = nums[0];
        loot[1] = max(loot[0], nums[1]);

        for (int ind = 2; ind < n; ind++)
        {
            // don't choose ind
            int loot_exc = loot[ind - 1];
            
            // choose ind
            int loot_inc = loot[ind - 2] + nums[ind];

            loot[ind] = max(loot_exc, loot_inc);
        }

        return loot[n - 1];
    }

    // space optimization
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

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
};

int main()
{

    return 0;
}