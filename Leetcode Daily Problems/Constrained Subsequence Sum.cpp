#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- we use dynamic programming in this problem , as the subsequence cannot be empty
we must consider each element each time & then use a loop of k for next k elements
its like a pick not pick for the next k elements , either we want to choose first k elements or not
but its time complexity is O(N*K) which will give us a time limit exceeded

Approach 2 -- here we use a tabulation dp approach where we call that a dp[ind] means that the maxSum
of the subarray from index 0 to ind , it must include index ind
Given relation will be max(nums[ind] , nums[ind] + max(dp[ind-1] , dp[ind-2] , dp[ind-3] , ... , dp[ind-k]))

here the max(dp[ind-1] , dp[ind-2] , ... do[ind-k]) can be found using heap & we can use a sliding window to get
the last k elements , we cannot pop the leftmost element each time from heap so we will put element with index
in the heap such that we only accept the max element if its index is in last k range otherwise pop it out
*/

class Solution
{
public:
    // tabulation
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxSum = INT_MIN;
        vector<int> maxSubsetSum(n);
        priority_queue<pair<int, int>> maxSumHeap;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            maxSubsetSum[ind] = num;

            while ((!maxSumHeap.empty()) && ((maxSumHeap.top().second) < (ind - k)))
            {
                maxSumHeap.pop();
            }

            if (!maxSumHeap.empty())
            {
                int sum = maxSumHeap.top().first;
                maxSubsetSum[ind] = max(maxSubsetSum[ind], num + sum);
            }

            maxSumHeap.push({maxSubsetSum[ind], ind});
            maxSum = max(maxSum, maxSubsetSum[ind]);
        }

        return maxSum;
    }

    // space optimisation
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size(), maxSum = INT_MIN;
        priority_queue<pair<int, int>> maxSumHeap;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            int maxSubsetSum = num;

            while ((!maxSumHeap.empty()) && ((maxSumHeap.top().second) < (ind - k)))
            {
                maxSumHeap.pop();
            }

            if (!maxSumHeap.empty())
            {
                int sum = maxSumHeap.top().first;
                maxSubsetSum = max(maxSubsetSum, num + sum);
            }

            maxSumHeap.push({maxSubsetSum, ind});
            maxSum = max(maxSum, maxSubsetSum);
        }

        return maxSum;
    }
};

// TC : O(N * log(n)) -- max size of heap will be O(N)
// SC : (N + N) = O(N) -- size of dp & heap

int main()
{

    return 0;
}