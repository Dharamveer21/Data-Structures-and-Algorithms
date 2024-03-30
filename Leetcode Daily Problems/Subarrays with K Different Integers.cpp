#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here we can use a standard sliding window template but it will give us the subarrays count ending at
right pointer having unique elements <= k . Now , we can apply this sliding window again for <= k-1 . Finally we
can subtract subarraysCount (for unique <= k-1) from subarraysCount (for unique <= k) . It will be (for == k) .
*/

// Approach
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
// SC : O(1)

int main()
{

    return 0;
}