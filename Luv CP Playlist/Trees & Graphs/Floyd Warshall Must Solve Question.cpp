#include <bits/stdc++.h>
using namespace std;

const int N = 501;
long long dist[N][N];

int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }
    
    vector<int> deleted_nodes(n);
    vector<long long> ans(n, 0);
    int ct = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> deleted_nodes[i];
    }

    reverse(deleted_nodes.begin(), deleted_nodes.end());

    for (int k = 0; k < n; k++)
    {
        int k_v = deleted_nodes[k];

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                long long new_dist = dist[i][k_v] + dist[k_v][j];
                dist[i][j] = min(dist[i][j], new_dist);
            }
        }

        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                ans[ct] += dist[deleted_nodes[i]][deleted_nodes[j]];
            }
        }

        ct++;
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}