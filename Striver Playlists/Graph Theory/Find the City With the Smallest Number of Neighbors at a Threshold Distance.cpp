#include <bits/stdc++.h>
using namespace std;

// simple floyd
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        const long long INF = 1e9 + 10;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        for (int i = 0; i < edges.size(); i++)
        {
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            int wt = edges[i][2];

            dist[v1][v2] = wt;
            dist[v2][v1] = wt;
            dist[v1][v1] = 0;
            dist[v2][v2] = 0;
        }

        // travel via all nodes
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][via] + dist[via][j], dist[i][j]);
                }
            }
        }

        int min_reach = INT_MAX, ans = 0;

        for (int i = 0; i < n; i++)
        {
            int reach = 0;

            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= (distanceThreshold + 0LL))
                {
                    reach++;
                }
            }

            if (reach <= min_reach)
            {
                min_reach = reach;
                ans = i;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}