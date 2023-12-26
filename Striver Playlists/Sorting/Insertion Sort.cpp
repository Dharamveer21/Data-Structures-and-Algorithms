#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Put the element to its correct position in the sorted array
take element at index ind , swap it with left until element is smaller than or equal to it
*/

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();

        for (int ind1 = 1; ind1 < n; ind1++)
        {
            int ind2 = ind1;

            while (ind2 > 0 && nums[ind2 - 1] > nums[ind2])
            {
                swap(nums[ind2 - 1], nums[ind2]);
                ind2--;
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