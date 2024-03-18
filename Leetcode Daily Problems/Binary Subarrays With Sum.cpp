#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- Cumulative Sum Approach , here we will consider each element at a index as the ending index of
the subarray & count how many times we get (Cumulative Sum - goal) before and add that value in answerCount .
Becasue the value means that there are same number of subarrays ending at current index which has sum equal to
goal . Take a map to store the count of cummulativeSum & initially put zero in the map with count as 1 .

Approach 2 -- It is a sliding Window Approach , We will update right pointer until we get windowSum equal to or
greater than the goal . Now if the sum is equal to goal we will update countOfSubarrayWithSum with 1 but we
also know that if the window is greater than the goal , we have to clear it from left Side and subtract values
from window and update left pointer . But we also have to consider the fact of prefixZeros in this problem
Suppose we a array is 000110 & goal is 2 . Then the first three prefix zeros are very important as we have
to increase their count each time we get same goal . So we also update left if nums[leftInd] == 0 and count
it as prefixZeros until we get window <= goal && nums[leftInd] == 1 . If we get into while loop with window >
goal but nums[leftInd] == 1 in that case we will update prefixZeros to 0 again as continouous 0 breaked .
*/

// Approach 1
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int countOfSubarraysWithSum = 0;
        int n = nums.size(), currSum = 0;

        unordered_map<int, int> cumulativeSumCount;
        cumulativeSumCount.insert({0, 1});

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            currSum = currSum + num;

            int requiredSum = currSum - goal;
            int count = cumulativeSumCount[requiredSum];

            countOfSubarraysWithSum += count;
            cumulativeSumCount[currSum] += 1;
        }

        return countOfSubarraysWithSum;
    }
};

// TC : O(N)
// SC : O(N)

// Approach 2
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int prefixCountOfZeros = 0, n = nums.size(), windowSum = 0;
        int countOfSubarraysWithSum = 0, leftInd = 0, rightInd = 0;

        while (rightInd < n)
        {
            int num = nums[rightInd];
            windowSum += num;

            while (leftInd < rightInd && (nums[leftInd] == 0 || windowSum > goal))
            {
                if (nums[leftInd] == 0)
                    prefixCountOfZeros++;

                else
                    prefixCountOfZeros = 0;

                windowSum -= nums[leftInd];
                leftInd++;
            }

            if (windowSum == goal)
                countOfSubarraysWithSum += prefixCountOfZeros + 1;

            rightInd++;
        }

        return countOfSubarraysWithSum;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}