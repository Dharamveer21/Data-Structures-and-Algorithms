#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;

int parent[N], sz[N];

void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    // Path compression
    return find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }

        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> cities(N + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> cities[i].first >> cities[i].second;
    }

    vector<int> c(N + 1), k(N + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }

    vector<pair<long long, pair<int, int>>> edges;

    for (int i = 1; i <= n; i++)
    {

        edges.push_back({c[i], {0, i}});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            long long cost = (k[i] + k[j]) * 1LL * (dist);

            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i <= n; i++)
    {
        make(i);
    }

    vector<pair<int, int>> mini_tree;
    long long total_cost = 0;
    int total_power_stations = 0;
    int total_connections = 0;
    vector<int> power_stations;
    vector<pair<int, int>> connections;

    for (auto &edge : edges)
    {
        long long wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(u) != find(v))
        {
            Union(u, v);
            total_cost += wt;
            mini_tree.push_back({u, v});
        }
    }

    for (pair<int, int> &edge : mini_tree)
    {
        if (edge.first == 0 || edge.second == 0)
        {
            total_power_stations++;
            power_stations.push_back(edge.first + edge.second);
        }

        else
        {
            total_connections++;
            connections.push_back({edge.first, edge.second});
        }
    }

    sort(power_stations.begin(), power_stations.end());
    sort(connections.begin(), connections.end());

    cout << total_cost << endl;
    cout << total_power_stations << endl;

    for (int i = 0; i < total_power_stations; i++)
    {
        cout << power_stations[i] << " ";
    }

    cout << endl;
    cout << total_connections << endl;

    for (int i = 0; i < total_connections; i++)
    {
        cout << connections[i].first << " " << connections[i].second << endl;
    }

    return 0;
}