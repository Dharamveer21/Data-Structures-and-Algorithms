#include <bits/stdc++.h>
using namespace std;

// memoisation
class Solution
{
public:
    int all_ways(int n, vector<int> &ways)
    {
        if (ways[n] != -1)
        {
            return ways[n];
        }

        return ways[n] = all_ways(n - 1, ways) + all_ways(n - 2, ways);
    }

    int climbStairs(int n)
    {
        vector<int> ways(n + 1, -1);
        ways[0] = ways[1] = 1;
        all_ways(n, ways);
        return ways[n];
    }
};

// tabulation
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> ways(n + 1, -1);
        ways[0] = ways[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            ways[i] = ways[i - 1] + ways[i - 2];
        }

        return ways[n];
    }
};

// space optimization
class Solution
{
public:
    int climbStairs(int n)
    {
        int prev = 1;
        int sec_prev = 1;
        int curr = 1;

        for (int i = 2; i <= n; i++)
        {
            curr = prev + sec_prev;
            sec_prev = prev;
            prev = curr;
        }

        return curr;
    }
};

int main()
{
    /*
    In 1D Dp Problem

    1. try to represent the problem in terms of index
    2. Do all possible stuff on that ind in accordance to problem statement
    3. sum of all stuffs - count all ways , min(of all ways) , max(all ways) - apply dp
     */

    return 0;
}