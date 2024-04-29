#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- Here we can use a standard sliding window template but it will give us the subarrays count ending
at right pointer having unique elements <= k . Now , we can apply this sliding window again for <= k-1 .Finally
we can subtract subarraysCount (for unique <= k-1) from subarraysCount (for unique <= k) . It will (for == k) .

Approach 2 -- We just need to find the smallest valid subarray ending at right pointer and the pointer to the
left of the largest valid subarray ending at right pointer . We just add (left Pointer - pointer to left of
largest subarray + 1) for finding all valid subarrays ending at right pointer . We can find it for every right
pointer using the sliding window technique . Finally return the ans for all valid subarrays (distinct == k) .
*/

// Approach 1
class Solution
{
protected:
    int subarraysWithLessThanOrEqualToKDistinct(vector<int> &arr, int maxUniqueElements)
    {
        unordered_map<int, int> freqMap;
        int leftPointer = 0, rightPointer = 0;
        int n = arr.size(), subarraysCount = 0;

        while (rightPointer < n)
        {
            int num = arr[rightPointer++];
            freqMap[num] += 1;

            while (leftPointer < rightPointer && freqMap.size() > maxUniqueElements)
            {
                int leftMostElement = arr[leftPointer++];
                freqMap[leftMostElement] -= 1;

                if (freqMap[leftMostElement] == 0)
                    freqMap.erase(leftMostElement);
            }

            int validSubarraysEndingAtRightPointer = (rightPointer - leftPointer);
            subarraysCount = subarraysCount + validSubarraysEndingAtRightPointer;
        }

        return subarraysCount;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int maxUniqueElements1 = k, maxUniqueElements2 = k - 1;
        int subarraysCount1 = subarraysWithLessThanOrEqualToKDistinct(nums, maxUniqueElements1);
        int subarraysCount2 = subarraysWithLessThanOrEqualToKDistinct(nums, maxUniqueElements2);

        int subarraysCountForExactlyKDistinctElements = subarraysCount1 - subarraysCount2;
        return subarraysCountForExactlyKDistinctElements;
    }
};

// TC : O(N)
// SC : O(N)

// Approach 2
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqMap;
        int maxUniqueElements1 = k, subarraysCountForExactlyKDistinctElements = 0;
        int n = nums.size(), lastLeftPointer = 0, leftPointer = 0, rightPointer = 0;

        while (rightPointer < n)
        {
            int num = nums[rightPointer++];
            freqMap[num] += 1;

            while (freqMap.size() > k)
            {
                int leftMostElement = nums[leftPointer++];
                freqMap[leftMostElement] -= 1;

                if (freqMap[leftMostElement] == 0)
                    freqMap.erase(leftMostElement);

                lastLeftPointer = leftPointer;
            }

            while (freqMap[nums[leftPointer]] > 1)
                freqMap[nums[leftPointer++]] -= 1;

            if (freqMap.size() == k)
            {
                int validSubarraysCountEndingAtRightPointer = leftPointer - lastLeftPointer + 1;
                subarraysCountForExactlyKDistinctElements += validSubarraysCountEndingAtRightPointer;
            }
        }

        return subarraysCountForExactlyKDistinctElements;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}