#include <bits/stdc++.h>
using namespace std;

long long dp[100001][101];

long long max_value(int ind, int cap, vector<pair<int, int>> &weight_value)
{
    if (cap == 0)
    {
        return 0;
    }

    if (ind < 0)
    {
        return 0;
    }

    if (dp[cap][ind] != -1)
    {
        return dp[cap][ind];
    }
    
    // do not include ind
    long long ans = max_value(ind - 1, cap, weight_value);

    int wt = weight_value[ind].first;
    int val = weight_value[ind].second;

    if (cap - wt >= 0)
    {
        // do include
        ans = max(ans, val + max_value(ind - 1, cap - wt, weight_value));
    }

    return dp[cap][ind] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, capacity;
    cin >> n >> capacity;

    vector<pair<int, int>> weight_value;

    for (int i = 0; i < n; i++)
    {
        int w1, v1;
        cin >> w1 >> v1;

        weight_value.push_back({w1, v1});
    }

    cout << max_value(n - 1, capacity, weight_value);

    return 0;
}