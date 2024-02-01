#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We have to sort the array & then divide it into groups of three of consecutive elements from
starting . The reason for which the sorting is useful is that if array is -- 1 2 3 4 5 6

Then in this array the minimum difference is between any two pairs means if we take consecutive elements
in the array near to each other the difference is minimum & as we increase the gap the diff increases.
So , if is not satisfying for consective elements , it will not satisfy for any other arrangement
*/

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dividedArrays;
        sort(nums.begin(), nums.end());

        for (int ind = 0; ind < n; ind += 3)
        {
            if (nums[ind + 2] - nums[ind] > k)
            {
                continue;
            }

            vector<int> arr;

            arr.push_back(nums[ind]);
            arr.push_back(nums[ind + 1]);
            arr.push_back(nums[ind + 2]);

            dividedArrays.push_back(arr);
        }

        return dividedArrays;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}