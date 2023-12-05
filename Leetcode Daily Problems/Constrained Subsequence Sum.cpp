#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- we use dynamic programming in this problem , as the subsequence cannot be empty
we must consider each element each time & then use a loop of k for next k elements
its like a pick not pick for the next k elements , either we want to choose first k elements or not
but its time complexity is O(N*K) which will give us a time limit exceeded

Approach 2 --  
*/

class Solution
{
public:
    int maxSubsetSum(int ind, int k, vector<int> &nums, vector<int> &maxSubsetSums)
    {
        const int N = 1e9 + 7;
        int n = nums.size();

        if (ind >= n)
        {
            return 0;
        }

        if (maxSubsetSums[ind] != N)
        {
            return maxSubsetSums[ind];
        }

        int maxSum = INT_MIN;

        for (int i = ind; i < min(n, ind + k); i++)
        {
            int num = nums[i];
            maxSum = max(maxSum, num);

            int sum = num + maxSubsetSum(i + 1, k, nums, maxSubsetSums);
            maxSum = max(maxSum, sum);
        }

        return (maxSubsetSums[ind] = maxSum);
    }

    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxSum = INT_MIN;
        vector<int> maxSubsetSums(n, 1e9 + 7);

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            maxSum = max(maxSum, num);

            int sum = num + maxSubsetSum(ind + 1, k, nums, maxSubsetSums);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

int main()
{

    return 0;
}