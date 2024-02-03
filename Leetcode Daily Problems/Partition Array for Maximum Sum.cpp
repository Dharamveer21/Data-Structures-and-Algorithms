#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a DP problem here we can think it in way of a funtion f having argument as index
f(ind) -- maximum sum of the array after partitioning from index "ind" to "n-1" means full array from "ind"
*/

class Solution
{
protected:
    // memoisation
    int maxSumParition(int ind, int len, vector<int> &arr, vector<int> &maxSumArr)
    {
        int n = arr.size(), maxElement = 0, maxSumPart = 0;

        if (maxSumArr[ind] != -1)
        {
            return maxSumArr[ind];
        }

        for (int i = ind; i < min(ind + len, n); i++)
        {
            int timesToSum = (i - ind + 1);
            maxElement = max(maxElement, arr[i]);

            int sum = (maxElement * timesToSum) + ((i + 1 == n) ? 0 : maxSumParition(i + 1, len, arr, maxSumArr));
            maxSumPart = max(maxSumPart, sum);
        }

        return maxSumArr[ind] = maxSumPart;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> maxSumArr(n, -1);

        int ans = maxSumParition(0, k, arr, maxSumArr);
        return ans;
    }

    // tabulation
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size(), len = k;
        vector<int> maxSumArr(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int maxElement = 0, maxSumPart = 0;

            for (int i = ind; i < min(ind + len, n); i++)
            {
                int timesToSum = (i - ind + 1);
                maxElement = max(maxElement, arr[i]);

                int sum = (maxElement * timesToSum) + maxSumArr[i + 1];
                maxSumPart = max(maxSumPart, sum);
            }

            maxSumArr[ind] = maxSumPart;
        }

        return maxSumArr[0];
    }
};

// TC : O(N * K)
// SC : O(N)

int main()
{

    return 0;
}