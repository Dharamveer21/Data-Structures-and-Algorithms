#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;

int val[N][N];
bool vis[N][N];
int level[N][N];
int n, m;

vector<pair<int, int>> moments = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};

bool is_valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return false;
    }

    else
    {
        return true;
    }
}

int bfs()
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, val[i][j]);
        }
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mx == val[i][j])
            {
                q.push({i, j});
                level[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }

    int ans = 0;

    while (!q.empty())
    {
        pair<int, int> cur_v = q.front();
        q.pop();

        for (auto child : moments)
        {
            int child_x = cur_v.first + child.first;
            int child_y = cur_v.second + child.second;

            if (!is_valid(child_x, child_y))
            {
                continue;
            }

            if (vis[child_x][child_y])
            {
                continue;
            }

            q.push({child_x, child_y});
            vis[child_x][child_y] = true;
            level[child_x][child_y] = level[cur_v.first][cur_v.second] + 1;
            ans = max(ans, level[child_x][child_y]);
        }
    }

    return ans;
}

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
            level[i][j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        reset();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> val[i][j];
            }
        }

        cout << bfs() << endl;
    }

    return 0;
}