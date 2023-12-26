#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Put the maximum element of the unsorted array at the last by adjacent swapping
after each iteration the max will come at last & unosorted array's size will be smaller by 1
*/

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();

        for (int ind1 = 0; ind1 < n - 1; ind1++)
        {
            for (int ind2 = 0; ind2 < n - ind1 - 1; ind2++)
            {
                if (nums[ind2] > nums[ind2 + 1])
                {
                    swap(nums[ind2], nums[ind2 + 1]);
                }
            }
        }

        return nums;
    }
};

// TC : O(N ^ 2)
// SC : O(1)

int main()
{

    return 0;
}