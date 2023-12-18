#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- Sorting the nums array & find the minimum last_two as (a,b) and first_two as (c,d)

Approach 2 -- FirstMaximum & SecondMaximum and FirstMinimum & SecondMinimum with using for loop
*/

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int firstMax = INT_MIN, secondMax = INT_MIN;
        int firstMin = INT_MAX, secondMin = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];

            // for maximum
            if (num > firstMax)
            {
                secondMax = firstMax;
                firstMax = num;
            }

            else
            {
                secondMax = max(num, secondMax);
            }

            // for minimum
            if (num < firstMin)
            {
                secondMin = firstMin;
                firstMin = num;
            }
            
            else
            {
                secondMin = min(num, secondMin);
            }
        }

        int result = (firstMax * secondMax) - (firstMin * secondMin);
        return result;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}