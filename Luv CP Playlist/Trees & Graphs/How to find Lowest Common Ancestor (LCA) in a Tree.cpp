#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int parent[N];

void dfs(int vertex, int par = 0)
{
    for (int child : g[vertex])
    {
        if (child == par)
        {
            continue;
        }

        parent[child] = vertex;
        dfs(child, vertex);
    }
}

vector<int> path(int vertex)
{
    vector<int> ans;

    while (vertex != 0)
    {
        ans.push_back(vertex);
        vertex = parent[vertex];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);

    int LCA;
    int x, y;
    cin >> x >> y;

    vector<int> path_x = path(x);
    vector<int> path_y = path(y);

    for (int i = 0; i < min(path_x.size(), path_y.size()); i++)
    {
        if (path_x[i] == path_y[i])
        {
            LCA = path_x[i];
        }

        else
        {
            break;
        }
    }

    cout << "LCA of " << x << " , " << y << " is : " << LCA << endl;

    return 0;
}