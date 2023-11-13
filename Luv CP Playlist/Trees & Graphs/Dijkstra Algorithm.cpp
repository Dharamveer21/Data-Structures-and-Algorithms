#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];
vector<int> dist(N, INF);

void dijkstra(int source)
{
    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty())
    {
        auto cur_v = *st.begin();
        int v = cur_v.second;
        int dist_v = cur_v.first;
        st.erase(st.begin());

        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;

            if (dist_v + wt < dist[child_v])
            {
                dist[child_v] = dist_v + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++)
        {
            int v1, v2, wt;
            cin >> v1 >> v2 >> wt;

            g[v1].push_back({v2, wt});
        }

        dijkstra(1);
        int ans = -1;

        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INF)
            {
                ans = -1;
                break;
            }

            ans = max(ans, dist[i]);
        }

        cout << ans << endl;
    }

    return 0;
}

// Network Delay Time
class Solution
{
public:
    const int N = 1e5 + 10;
    const int INF = 1e9 + 10;

    void dijkstra(int source, vector<pair<int, int>> g[], vector<int> &dist)
    {
        set<pair<int, int>> st;
        dist[source] = 0;
        st.insert({0, source});

        while (!st.empty())
        {
            auto cur_v = *st.begin();
            int v = cur_v.second;
            int dist_v = cur_v.first;
            st.erase(st.begin());

            for (auto child : g[v])
            {
                int child_v = child.first;
                int wt = child.second;

                if (dist_v + wt < dist[child_v])
                {
                    dist[child_v] = dist_v + wt;
                    st.insert({dist[child_v], child_v});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> g[N];
        vector<int> dist(N, INF);

        for (auto vec : times)
        {
            int v1, v2, wt;

            v1 = vec[0];
            v2 = vec[1];
            wt = vec[2];

            g[v1].push_back({v2, wt});
        }

        dijkstra(k, g, dist);
        int ans = -1;

        for (int i = 1; i <= n; i++)
        {
            if(dist[i] == INF)
            {
                return -1;
            }

            ans = max(ans,dist[i]);
        }

        return ans;
    }
};
