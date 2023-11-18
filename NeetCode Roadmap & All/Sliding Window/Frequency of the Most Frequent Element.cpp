#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Consider the array as the heights of the building , we can only increase the heights of building in each operation but cannot decrease it
Hence all buinding shorter than a particular building can have a chance to become equal to it
So, in this case each building needs building shorter than itself
Also if someone wants to increase height of other building , it should increase the building closest to its height
hence we sort the array in ascending order

After sorting we know that for any building i -- if the maximum range for its heights equals is till some j , j < i
then any building on i+1 , i+2 , ... will have atmost range upto j , it will never go less than j
hence there is a window which keeps on increasing on right side for each next element
but it also started decreasing from left & become short
Hence we use concept of sliding window & for interdependency of new elements in window we use prefix sum

for any window size form l to r , we need to find the no of blocks required to make it equal to height at r is :
height(r) * (r-l) - sum of heights from (l to r-1) if it is greater than k , then we shift window from l to l + 1
otherwise we will not shift it from l side
for sum from l to r we need a prefix array
It will shift from r side each time i increments
*/

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();

        // edge case
        if (n == 1)
        {
            return 1;
        }
         
        sort(nums.begin(), nums.end());
        vector<long long> heights_sum(n, nums[0]);
        int left = 0, max_freq = 1, freq = 1;

        for (int i = 1; i < n; i++)
        {
            heights_sum[i] = nums[i] + heights_sum[i - 1];
        }

        for (int build_num = 1; build_num < n; build_num++)
        {
            long long blocks_sum = heights_sum[build_num] - ((left == 0) ? 0LL : heights_sum[left - 1]);
            long long blocks_req = nums[build_num] * 1LL * (build_num - left + 1) - blocks_sum;

            while (blocks_req > (k * 1LL))
            {
                left++;
                blocks_req = blocks_req - (nums[build_num] - nums[left - 1]);
            }

            freq = (build_num - left + 1);
            max_freq = max(max_freq, freq);
        }

        return max_freq;
    }
};

// TC : O(n * logn) + O(n) + O(n) = O(n * logn)

int main()
{

    return 0;
}