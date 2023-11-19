#include <bits/stdc++.h>
using namespace std;

// Approach -- sort the array first , then as we know with each operation the count of new largest element is going to increase , and that many operations were required for it .
// so, we first sort all elements , take there frequencies & do a prefix sum from largest element's freq to smallest element's freq
// now we do a sum of that prefix sum array , excluding the smallest element as it is not going to convert into anything smaller
// so it doesn't require operations

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int n = nums.size(), num_operations = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        int prev = nums[0], curr = nums[0];

        for (int i = 0; i < n; i++)
        {
            curr = nums[i];

            if (curr != prev)
            {
                int cnt = i;
                num_operations += cnt;
            }

            prev = curr;
        }

        return num_operations;
    }
};

int main()
{

    return 0;
}