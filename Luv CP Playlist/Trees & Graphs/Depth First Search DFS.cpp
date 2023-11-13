#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex)
{
    // take action on vertex after entering the vertex

    if (vis[vertex])
    {
        return;
    }

    cout << vertex << endl;

    vis[vertex] = true;

    for (int child : g[vertex])
    {
        // take action before entering the child node
        cout << "par : " << vertex << "  child : " << child << endl;
        dfs(child);
        // take action after exiting the child node
    }

    // take action before exiting the vertex
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
    
    dfs(1);

    return 0;
}