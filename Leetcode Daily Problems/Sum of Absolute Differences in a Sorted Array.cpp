#include <bits/stdc++.h>
using namespace std;

/*
Approach -- the elements before index i are to be subtracted from nums[i]
and nums[i] is to be subtracted the elements after index i
use a prefix sum array & a suffix sum array for the calculation in O(1) time
*/

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixSum(n, 0), suffixSum(n, 0);
        vector<int> ans;

        prefixSum[0] = nums[0];
        suffixSum[n - 1] = nums[n - 1];

        for (int ind = 1; ind < n; ind++)
        {
            prefixSum[ind] = prefixSum[ind - 1] + nums[ind];
        }

        cout << endl;

        for (int ind = n - 2; ind >= 0; ind--)
        {
            suffixSum[ind] = nums[ind] + suffixSum[ind + 1];
        }

        for (int ind = 0; ind < n; ind++)
        {
            int leftLen = ind;
            int rightLen = n - ind - 1;

            int leftSum = ((ind == 0) ? 0 : ((leftLen * nums[ind]) - (prefixSum[ind - 1])));
            int rightSum = ((ind == n - 1) ? 0 : ((suffixSum[ind + 1]) - (rightLen * nums[ind])));

            int absSum = (leftSum) + (rightSum);
            ans.push_back(absSum);
        }

        return ans;
    }
};

// TC : O(N + N + N) = O(N)
// SC : O(N + N + N) = O(N)

int main()
{

    return 0;
}