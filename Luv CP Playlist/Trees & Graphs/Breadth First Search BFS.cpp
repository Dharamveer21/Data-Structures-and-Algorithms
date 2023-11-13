#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

bool vis[N];
int level[N];

void BFS(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = true;
    
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
         
        for (int child : g[cur_v])
        {
            if (!vis[child])
            { 
                q.push(child);
                vis[child] = true;
                level[child] = level[cur_v] + 1;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    BFS(1);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << level[i] << endl;
    }

    return 0;
}