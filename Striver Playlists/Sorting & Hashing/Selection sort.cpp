#include <bits/stdc++.h>
using namespace std;

/*
Suppose array is sorted till index "ind - 1" Now take element at index "ind"
Select the minimum element in the rest of the array (from "ind" to last) & replace
it with first element of unsorted array that is with "ind"
Repeat the above steps until ind will increase upto size - 1 of the array
*/

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();

        for (int ind1 = 0; ind1 < n; ind1++)
        {
            int minElementInd = ind1;
            int minElement = nums[ind1];

            for (int ind2 = ind1 + 1; ind2 < n; ind2++)
            {
                if (nums[ind2] < minElement)
                {
                    minElement = nums[ind2];
                    minElementInd = ind2;
                }
            }

            swap(nums[ind1], nums[minElementInd]);
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