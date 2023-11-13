#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // Path Compression
    int findPar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findPar(parent[node]);
    }

    void union_by_rank(int u, int v)
    {
        int ultimate_par_u = findPar(u);
        int ultimate_par_v = findPar(v);

        if (ultimate_par_u == ultimate_par_v)
        {
            return;
        }

        if (rank[ultimate_par_u] == rank[ultimate_par_v])
        {
            rank[ultimate_par_u]++;
            parent[ultimate_par_v] = ultimate_par_u;
        }

        else if (rank[ultimate_par_u] > rank[ultimate_par_v])
        {
            parent[ultimate_par_v] = ultimate_par_u;
        }

        else
        {
            parent[ultimate_par_u] = ultimate_par_v;
        }
    }

    void union_by_size(int u, int v)
    {
        int ultimate_par_u = findPar(u);
        int ultimate_par_v = findPar(v);

        if (ultimate_par_u == ultimate_par_v)
        {
            return;
        }

        if (size[ultimate_par_u] >= size[ultimate_par_v])
        {
            parent[ultimate_par_v] = ultimate_par_u;
            size[ultimate_par_u] += size[ultimate_par_v];
        }

        else
        {
            parent[ultimate_par_u] = ultimate_par_v;
            size[ultimate_par_v] += size[ultimate_par_u];
        }
    }
};

class Solution
{
public:
    // using Disjoint Set
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int province_cnt = 0;
        int n = isConnected.size();
        DisjointSet *ds = new DisjointSet(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    ds->union_by_size(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (ds->findPar(i) == i)
            {
                province_cnt++;
            }
        }

        return province_cnt;
    }
};

int main()
{

    return 0;
}