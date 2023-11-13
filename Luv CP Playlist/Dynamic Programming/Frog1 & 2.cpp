#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long mini_cost_n[N];

// Frog 1
long long mini_cost(int n, vector<int> &height)
{
    if (mini_cost_n[n] != -1)
    {
        return mini_cost_n[n];
    }
    
    long long mini_cost_n_1 = mini_cost(n - 1, height);
    long long mini_cost_n_2 = mini_cost(n - 2, height);
    
    int cost_n_1 = abs(height[n] - height[n - 1]);
    int cost_n_2 = abs(height[n] - height[n - 2]);
    
    return mini_cost_n[n] = min(mini_cost_n_1 + cost_n_1, mini_cost_n_2 + cost_n_2);
}

int main()
{
    memset(mini_cost_n, -1, sizeof(mini_cost_n));

    int n;
    cin >> n;

    vector<int> height(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> height[i];
    }

    mini_cost_n[1] = 0;
    mini_cost_n[2] = abs(height[2] - height[1]);

    cout << mini_cost(n, height) << endl;

    return 0;
}

// Frog 2
long long mini_cost(int i, vector<int> &h, int k, long long min_cost[])
{
    if (min_cost[i] != -1)
    {
        return min_cost[i];
    }

    long long cost = LLONG_MAX;

    for (int j = max(i - k, 1); j < i; j++)
    {
        long long cost_j = mini_cost(j, h, k, min_cost) + abs(h[i] - h[j]);
        cost = cost > cost_j ? cost_j : cost;
    }

    return min_cost[i] = cost;
}

//O(N*K)
int main()
{
    int n, k;
    cin >> n >> k;

    long long min_cost[n + 1];
    memset(min_cost, -1, sizeof(min_cost));
    vector<int> h(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    min_cost[1] = 0;
    cout << mini_cost(n, h, k, min_cost) << endl;

    return 0;
}