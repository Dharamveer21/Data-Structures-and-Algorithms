#include <bits/stdc++.h>
using namespace std;

/*all partitions upto 1 to k*/

class Solution
{
public:
    // memoisation
    int maximum_sum(int ind, int &k, vector<int> &arr, vector<int> &maxSum)
    {
        if (maxSum[ind] != -1)
        {
            return maxSum[ind];
        }

        int n = arr.size();
        int maxi = 0;
        int max_sum = 0;

        for (int part = ind; part < min(ind + k, n); part++)
        {
            maxi = max(maxi, arr[part]);
            int sum = (((part - ind + 1) * (maxi)) + maximum_sum(part + 1, k, arr, maxSum));
            max_sum = max(max_sum, sum);
        }

        return maxSum[ind] = max_sum;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> maxSum(n + 1, -1);
        return maximum_sum(0, k, arr, maxSum);
    }

    // tabulation
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        int maxSum[n + 1];

        for (int ind = n; ind >= 0; ind--)
        {
            int maxi = 0;
            int max_sum = 0;

            for (int part = ind; part < min(ind + k, n); part++)
            {
                maxi = max(maxi, arr[part]);
                int sum = ((part - ind + 1) * (maxi)) + maxSum[part + 1];
                max_sum = max(max_sum, sum);
            }

            maxSum[ind] = max_sum;
        }

        return maxSum[0];
    }
};

int main()
{

    return 0;
}