#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

/*
Given Q Queries , Q <= 10^5
In each query given V,
Print subtree  sum of V & Number of even numbers in a subtree of V
*/

vector<int> g[N];
int subtree_sum[N];
int even_count[N];

void dfs(int vertex, int par = 0)
{
    for (int child : g[vertex])
    {
        if (child == par)
        {
            continue;
        }

        dfs(child, vertex);

        subtree_sum[vertex] += subtree_sum[child];
        even_count[vertex] += even_count[child];
    }

    subtree_sum[vertex] += vertex;

    if (vertex % 2 == 0)
    {
        even_count[vertex] += 1;
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

    for (int i = 1; i < n; i++)
    {
        cout << i << endl;
        cout << "subtree sum : " << subtree_sum[i] << endl;
        cout << "even count : " << even_count[i] << endl;
        cout << endl;
    }

    /*
    int q;
    cin >> q;

    while (q--)
    {
        int v;
        cin >> v;
        cout << "subtree sum : " << subtree_sum[v] << endl;
        cout << "even count : " << even_count[v] << endl;
    }
    */
    return 0;
}