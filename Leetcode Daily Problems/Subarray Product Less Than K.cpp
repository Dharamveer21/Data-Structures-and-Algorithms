#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can solve this problem using standard sliding window technique , We will take two left and right
Pointers , now we want all subarrays ending at a particular right pointer & satisfying the product constraint .
We will multiply each new element and increase the right pointer then we check the lowest left Pointer which is
making the window valid under constraint and then just add the number of subarray between left & right ending at
the right pointer . If we find window's product greater then required we just start dividing elements from left
side & increase the left pointer until the product is greater than K or left is less than right Pointer .
*/

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int leftPointer = 0, rightPointer = 0;
        int n = nums.size(), productOfSubarray = 1;
        int numberOfSubarraysWithProductLessThanK = 0;

        while (rightPointer < n)
        {
            int num = nums[rightPointer++];
            productOfSubarray *= num;

            while (leftPointer < rightPointer && productOfSubarray >= k)
            {
                int leftMostElement = nums[leftPointer++];
                productOfSubarray /= leftMostElement;
            }

            int countOfSubarrayEndingAtRightPointer = (rightPointer - leftPointer);
            numberOfSubarraysWithProductLessThanK += countOfSubarrayEndingAtRightPointer;
        }

        return numberOfSubarraysWithProductLessThanK;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}