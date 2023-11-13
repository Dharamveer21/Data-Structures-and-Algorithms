#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

bool vis[8][8];
int level[8][8];

int getX(string s)
{
    return (s[0] - 'a');
}

int getY(string s)
{
    return (s[1] - '1');
}

vector<pair<int, int>> moments = {
    {-2, -1},
    {+2, +1},
    {-2, +1},
    {+2, -1},
    {-1, -2},
    {-1, +2},
    {+1, +2},
    {+1, -2},
};

int BFS(string source, string dest)
{
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destX = getX(dest);
    int destY = getY(dest);

    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    vis[sourceX][sourceY] = true;

    while (!q.empty())
    {
        pair<int, int> cur_v = q.front();
        q.pop();

        for (auto moment : moments)
        {
            int childX = cur_v.first + moment.first;
            int childY = cur_v.second + moment.second;

            if (childX < 0 || childY < 0 || childX >= 8 || childY >= 8)
            {
                continue;
            }
            
            if (!vis[childX][childY])
            {
                q.push({childX, childY});
                vis[childX][childY] = true;
                level[childX][childY] = level[cur_v.first][cur_v.second] + 1;
            }

            if (vis[destX][destY])
            {
                return level[destX][destY];
            }
        }
    }

    return level[destX][destY];
}

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
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
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << BFS(s1, s2) << endl;
    }

    return 0;
}