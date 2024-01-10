#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];

void dfs(int vertex, int par = 0)
{
    for (int child : g[vertex])
    {
        if (child == par)
            continue;

        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
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

    int mx_depth = -1;
    int mx_depth_node1;

    for (int i = 1; i <= n; i++)
    {
        if (mx_depth < depth[i])
        {
            mx_depth = depth[i];
            mx_depth_node1 = i;
        }
        
        depth[i] = 0;
    }

    dfs(mx_depth_node1);
    int mx_depth_node2;
    mx_depth = -1;

    for (int i = 1; i <= n; i++)
    {
        if (mx_depth < depth[i])
        {
            mx_depth = depth[i];
            mx_depth_node2 = i;
        }
    }

    cout << "Node1 : " << mx_depth_node1 << " Node2 : " << mx_depth_node2 << endl;
    cout << "Diameter : " << mx_depth << endl;

    return 0;
}