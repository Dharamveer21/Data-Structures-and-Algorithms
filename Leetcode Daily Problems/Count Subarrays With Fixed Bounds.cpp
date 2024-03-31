#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We just need to find all the valid subarrays ending at a particular index , suppose there are
minIndex , maxIndex and culpritIndex (minIndex is the index of the minK , maxIndex is the index of the maxK
and culprit index is the index of the number not between [minK,maxK]) and suppose we have curlprit index after
that maxIndex and then minIndex and at last our index "ind". Then the number of valid subarrays ending at ind
will be (smaller(minIndex , maxIndex) - culprit index) if this value is < 0 we add 0 otherwise its value .
*/

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long n = nums.size(), countSubarraysWithMinKAndMaxK = 0;
        int lastOutOfRangeNumberIndex = -1, maxNumberIndex = -1, minNumberIndex = -1;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];

            minNumberIndex = ((num == minK) ? ind : minNumberIndex);
            maxNumberIndex = ((num == maxK) ? ind : maxNumberIndex);
            lastOutOfRangeNumberIndex = ((num < minK || num > maxK) ? ind : lastOutOfRangeNumberIndex);

            int subarraysCountEndingAtInd = max(0, min(maxNumberIndex, minNumberIndex) - lastOutOfRangeNumberIndex);
            countSubarraysWithMinKAndMaxK = countSubarraysWithMinKAndMaxK + subarraysCountEndingAtInd;
        }

        return countSubarraysWithMinKAndMaxK;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}