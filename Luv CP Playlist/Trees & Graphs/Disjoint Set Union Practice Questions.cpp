#include <bits/stdc++.h>
using namespace std;

// City & Flood Questions
const int N = 1e5 + 10;
int parent[N];
int size[N];

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }

    // path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    while (k--)
    {
        int x, y;
        cin >> x >> y;

        Union(x, y);
    }

    int connect_cp = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i == find(i))
        {
            connect_cp += 1;
        }
    }

    cout << connect_cp << endl;

    return 0;
}

// Campers Question
const int N = 1e5 + 10;
int par[N];
int size[N];
multiset<int> sizes;

void make(int v)
{
    par[v] = v;
    size[v] = 1;
    sizes.insert(size[v]);
}

int find(int v)
{
    if (par[v] == v)
    {
        return v;
    }

    // path compression
    return par[v] = find(par[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }

        int old_size_a = size[a];
        int old_size_b = size[b];

        // merge by size comparison
        par[b] = a;
        size[a] += size[b];

        auto it = sizes.find(old_size_a);
        sizes.erase(it);
        it = sizes.find(old_size_b);
        sizes.erase(it);
        sizes.insert(size[a]);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        Union(x, y);

        int mx = *(--sizes.end());
        int mn = *(sizes.begin());
        
        cout << (mx - mn) << endl;
    }

    return 0;
}