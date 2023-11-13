#include <bits/stdc++.h>
using namespace std;

/*Disjoint Set*/

/*It solves in constant time*/
/*function -- find_par() & union(by size ot by rank)*/
/*It can find if the two nodes are connected or not in constant time*/

// it has time complexity as O(4 alpha) nearly equal to O(1)
// aplpha is close to 1

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

int main()
{
    DisjointSet *ds = new DisjointSet(7);
    ds->union_by_rank(1, 2);
    ds->union_by_rank(2, 3);
    ds->union_by_rank(4, 5);
    ds->union_by_rank(6, 7);
    ds->union_by_rank(5, 6);

    // 3 & 7 belong to same component or not

    if (ds->findPar(3) == ds->findPar(7))
    {
        cout << "same" << endl;
    }

    else
    {
        cout << "not same" << endl;
    }

    ds->union_by_rank(3, 7);

    if (ds->findPar(3) == ds->findPar(7))
    {
        cout << "same" << endl;
    }

    else
    {
        cout << "not same" << endl;
    }

    return 0;
}

int main()
{
    DisjointSet *ds = new DisjointSet(7);
    ds->union_by_size(1, 2);
    ds->union_by_size(2, 3);
    ds->union_by_size(4, 5);
    ds->union_by_size(6, 7);
    ds->union_by_size(5, 6);

    // 3 & 7 belong to same component or not

    if (ds->findPar(3) == ds->findPar(7))
    {
        cout << "same" << endl;
    }

    else
    {
        cout << "not same" << endl;
    }

    ds->union_by_size(3, 7);

    if (ds->findPar(3) == ds->findPar(7))
    {
        cout << "same" << endl;
    }

    else
    {
        cout << "not same" << endl;
    }

    return 0;
}