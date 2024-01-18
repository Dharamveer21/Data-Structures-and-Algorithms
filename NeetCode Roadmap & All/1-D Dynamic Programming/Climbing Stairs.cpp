#include <bits/stdc++.h>
using namespace std;

/*
Approach -- To reach at step n , we can come from (n-1) in 1 step jump & (n-2) in 2 step jump
So, the number of ways to reach 'n' will be ways(n-1) + ways(n-2)
*/

class Solution
{
public:
    // tabulation
    int climbStairs(int n)
    {
        vector<int> ways(n + 1, 1);

        for (int ind = 2; ind <= n; ind++)
        {
            ways[ind] = ways[ind - 1] + ways[ind - 2];
        }

        return ways[n];
    }

    // space optimisation
    int climbStairs(int n)
    {
        int allWays = 1, waysFromStep1 = 1, waysFromStep2 = 1;

        for (int ind = 2; ind <= n; ind++)
        {
            allWays = waysFromStep1 + waysFromStep2;
            waysFromStep2 = waysFromStep1;
            waysFromStep1 = allWays;
        }

        return allWays;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}