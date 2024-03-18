#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here if we replace 0 with -1 then the problem will be finding the maximum length subarray with its
sum as 0 . So, we can solve this problem by using a simple concept of cumulativeSum . We will store the index
of the cumulativeSum and whenever we get the same cumulativeSum again then it means that the index when it
occurred first to currIndex the whole subarray has a sum 0 only then the cumulativeSum will repeat . We can
calculate the length of the subarray & update maxLen . Then move forward then repeat the above statements .
We can use a map to store the index of the cumulativeSum or we can use an hashArray with size 2n + 1 .
But we can't use negative values as index in hashArray so we add n to cumulativeSum while storing and accessing
in the cumulativeSumIndex hashArray . In starting we have to put cumulativeSumIndex[0 + n] = -1 .
*/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size(), cumulativeSum = 0, maxSubbaryLen = 0;
        int INF = -2, *cumulativeSumIndex = new int[2 * n + 1];

        fill(cumulativeSumIndex, cumulativeSumIndex + 2 * n + 1, INF);
        cumulativeSumIndex[n] = -1;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            num = ((num == 0) ? -1 : num);

            cumulativeSum = cumulativeSum + num;
            int requiredSum = cumulativeSum + n;

            if (cumulativeSumIndex[requiredSum] != INF)
            {
                int startIndex = cumulativeSumIndex[requiredSum];
                int endIndex = ind;

                int len = endIndex - startIndex;
                maxSubbaryLen = max(maxSubbaryLen, len);
                continue;
            }

            cumulativeSumIndex[requiredSum] = ind;
        }

        delete[] cumulativeSumIndex;
        return maxSubbaryLen;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}