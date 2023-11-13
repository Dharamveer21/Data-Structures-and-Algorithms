#include <bits/stdc++.h>
using namespace std;

// how to find connected components using DFS
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex)
{
    vis[vertex] = true;
    current_cc.push_back(vertex);

    for (int child : g[vertex])
    {
        if (vis[child])
        {
            continue;
        }

        dfs(child);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);
        }
    }

    cout << cc.size() << endl;

    for (auto c_cc : cc)
    {
        for (int vertex : c_cc)
        {
            cout << vertex << " ";
        }

        cout << endl;
    }

    return 0;
}

// How to find cycles using DFS
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int par)
{
    bool is_loop_exists = false;
    vis[vertex] = true;

    for (int child : g[vertex])
    {
        if (vis[child] && child == par)
        {
            continue;
        }

        if (vis[child])
        {
            return true;
        }

        is_loop_exists |= dfs(child, vertex);
    }

    return is_loop_exists;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bool is_loop_exists = false;

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }

        if (dfs(i, 0))
        {
            is_loop_exists = true;
            break;
        }
    }

    cout << is_loop_exists << endl;

    return 0;
}