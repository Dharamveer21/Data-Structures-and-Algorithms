#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> Ropes;
        long long minRopeCost = 0;

        for (int ind = 0; ind < n; ind++)
        {
            int ropeLen = arr[ind];
            Ropes.push(ropeLen);
        }

        while (Ropes.size() != 1)
        {
            long long firstRope = Ropes.top();
            Ropes.pop();

            long long secondRope = Ropes.top();
            Ropes.pop();

            long long finalRopeLen = firstRope + secondRope;

            long long cost = finalRopeLen;
            minRopeCost += cost;

            Ropes.push(finalRopeLen);
        }

        return minRopeCost;
    }
};

// TC : O(N * log(N) + N * 3 * log(N)) = O(N * log(N))
// SC : O(N)

int main()
{

    return 0;
}