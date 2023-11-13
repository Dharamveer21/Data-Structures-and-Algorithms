#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int graph1[N][N];

vector<pair<int, int>> graph2[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        graph1[v1][v2] = wt;
        graph1[v2][v1] = wt;

        graph2[v1].push_back({v2, wt});
        graph2[v2].push_back({v1, wt});
    }

    // O(N^2) - space complexity of adjacency matrix
    // 0(N+M) - space complexity of adjacency list
    // check connected & find weights

    /* if i,j are connected ? wt ?

    if(graph1[i][j] == 1)
    {
        connected;
    }

    cout << graph[i][j] - weight;

    for(pair<int,int> child : graph2[i]])
    {
        if(child.first == j)
        {
            connected;
            cout << child.second; -- weight
        }
    }
    
    */
    return 0;
}