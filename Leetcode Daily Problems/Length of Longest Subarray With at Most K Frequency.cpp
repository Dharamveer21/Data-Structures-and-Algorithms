#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- This problem can be solved using standard sliding window template . We need only three steps :
  i) in each iteration add a new element in the window (right++) and add 1 to its freq in the map
 ii) check whether currWindow is valid or not by freq of curr right element is under k if not move left forward
     until the current window becomes valid and remove 1 from freq of the leftMostElement
iii) finally calculate the length of current valid window and compare its len with maxLength .

Approach 2 -- We can solve this problem in one pass also , The concept is that whenever we find a valid window
we store its length and if our window becomes invalid due to addition of the new element the length of the
subarray is increased by 1 but we also remove the element from the window from left side . So, we add from
right and remove from left so whenver we find a valid window its size must be equal to last valid window .
So, our approach will work and when we find a valid window we can check its size and then move right pointer
and if curr window is valid we will find a longer subarray then previous one . We will use culpritCount to get
the count of the culprit numbers whose freq is k+1 means there are new culprits and whenever we remove element
from left side we check if its freq is k then it was the culprit and we decrease the culprit count . If culprit
count is 0 means it is the valid window and we update the maxLength of the subarray comparing it with window .
*/

// Approach 1
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqMap;
        int maxSubarrayLengthWithFreqUnderK = 0;
        int n = nums.size(), left = 0, right = 0;

        while (right < n)
        {
            int num = nums[right++];
            freqMap[num] += 1;

            while (left < right && freqMap[num] > k)
            {
                int leftMostElement = nums[left++];
                freqMap[leftMostElement] -= 1;
            }

            int lengthOfSubarr = (right - left);
            maxSubarrayLengthWithFreqUnderK = max(maxSubarrayLengthWithFreqUnderK, lengthOfSubarr);
        }

        return maxSubarrayLengthWithFreqUnderK;
    }
};

// TC : O(N)
// SC : O(N)

// Approach 2
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int culpritNumberCount = 0;
        unordered_map<int, int> freqMap;
        int maxSubarrayLengthWithFreqUnderK = 0;
        int n = nums.size(), left = 0, right = 0;

        while (right < n)
        {
            int num = nums[right++];
            freqMap[num] += 1;

            if (freqMap[num] == k + 1)
                culpritNumberCount++;

            if (culpritNumberCount > 0)
            {
                int leftMostElement = nums[left++];
                freqMap[leftMostElement] -= 1;

                if (freqMap[leftMostElement] == k)
                    culpritNumberCount--;
            }

            if (culpritNumberCount == 0)
            {
                int lengthOfSubarr = (right - left);
                maxSubarrayLengthWithFreqUnderK = max(maxSubarrayLengthWithFreqUnderK, lengthOfSubarr);
            }
        }

        return maxSubarrayLengthWithFreqUnderK;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}