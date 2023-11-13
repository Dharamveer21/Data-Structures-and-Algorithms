#include <bits/stdc++.h>
using namespace std;

int wt[101], val[105];
long long dp[101][100001];

long long mini_weight(int ind, int value_left)
{
    if (value_left == 0)
    {
        return 0;
    }

    if (ind < 0)
    {
        return (1e15);
    }

    if (dp[ind][value_left] != -1)
    {
        return dp[ind][value_left];
    }
    
    // don't choose
    long long ans = mini_weight(ind - 1, value_left);

    // choose
    if (value_left - val[ind] >= 0)
    {
        ans = min(ans, mini_weight(ind - 1, value_left - val[ind]) + wt[ind]);
    }

    return dp[ind][value_left] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        int w1, v1;
        cin >> wt[i] >> val[i];
    }

    int max_value = 1e5;

    for (int i = max_value; i >= 0; i--)
    {
        if (mini_weight(n - 1, i) <= w)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}