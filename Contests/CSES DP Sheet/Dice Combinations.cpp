#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

/*
Approach - 1
dp[k] -- no of ways for getting the sum k
dp[k] =  dp[k-1] + dp[k-2] + dp[k-3] + dp[k-4] + dp[k-5] + dp[k-6]
base case dp[0] = 1 , we don't have to roll the dice
*/

int num_of_ways_1(int n)
{
    vector<int> ways(n + 1, 0);
    ways[0] = 1;

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= 6; ind2++)
        {
            if (ind1 >= ind2)
            {
                ways[ind1] = (ways[ind1] + 0LL + ways[ind1 - ind2]) % M;
            }
        }
    }

    return ways[n];
}

/*
Approach - 2
dp[k] -- no of ways for getting the sum n starting from intial sum k
dp[k] =  dp[k+1] + dp[k+2] + dp[k+3] + dp[k+4] + dp[k+5] + dp[k+6]
base case dp[n] = 1 , we don't have to roll the dice
*/

int num_of_ways_2(int n)
{
    vector<int> ways(n + 1);
    ways[n] = 1;

    for (int ind1 = n - 1; ind1 >= 0; ind1--)
    {
        for (int ind2 = 1; ind2 <= 6; ind2++)
        {
            if (ind1 + ind2 <= n)
            {
                ways[ind1] = (ways[ind1] + 0LL + ways[ind1 + ind2]) % M;
            }
        }
    }

    return ways[0];
}

int main()
{
    int n;
    cin >> n;

    int ans1 = num_of_ways_1(n) % M;
    int ans2 = num_of_ways_2(n) % M;

    int ans = ans1 = ans2;
    cout << ans << endl;

    return 0;
}