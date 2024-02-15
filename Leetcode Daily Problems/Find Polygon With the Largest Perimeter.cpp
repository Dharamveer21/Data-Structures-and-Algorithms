#include <bits/stdc++.h>
using namespace std;

/*
Approach -- If we consider any side as the longest side we need to check the sum of all sides smaller than the
given side or not . We have to sort the array now we can take a cummSum as the prefix sum & for every val in
nums we have check if this could be the largest side of the polygon or not . Then store sum as Permeter .
*/

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        long long n = nums.size(), maxPerimeter = -1;
        long long remainingSidesSum = nums[0] + nums[1];

        for (int ind = 2; ind < n; ind++)
        {
            long long largestSide = nums[ind];
            long long perimeter = remainingSidesSum + largestSide;

            bool isPoygonPossible = (largestSide < remainingSidesSum);
            maxPerimeter = ((isPoygonPossible) ? perimeter : maxPerimeter);
            remainingSidesSum = remainingSidesSum + largestSide;
        }

        return maxPerimeter;
    }
};

// TC : O(N * log(N))
// SC : O(1)

int main()
{

    return 0;
}