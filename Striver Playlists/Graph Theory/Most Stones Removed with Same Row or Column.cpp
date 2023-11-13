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

    int findSize(int node)
    {
        return size[node];
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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int rows = 0, cols = 0;
        int component_cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int row = stones[i][0];
            int col = stones[i][1];

            rows = max(row, rows);
            cols = max(col, cols);
        }

        rows = rows + 1;
        cols = cols + 1;
        DisjointSet *ds = new DisjointSet(rows + cols);

        for (int i = 0; i < n; i++)
        {
            int row = stones[i][0];
            int col = stones[i][1];

            ds->union_by_size(row, col + rows);
        }

        for (int node = 0; node < rows + cols; node++)
        {
            int par = ds->findPar(node);
            int size = ds->findSize(node);

            if (size == 1)
            {
                continue;
            }
             
            if (par == node)
            {
                component_cnt++;
            }
        }

        return (n - component_cnt);
    }
};

int main()
{

    return 0;
}