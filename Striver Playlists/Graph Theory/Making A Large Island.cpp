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
private:
    bool is_valid(int row, int col, int &rows, int &cols, vector<vector<int>> &vis)
    {
        if (row < 0 || row == rows || col < 0 || col == cols || vis[row][col] == 0)
        {
            return false;
        }

        return true;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int cnt_1 = 0;

        DisjointSet *ds = new DisjointSet(n * n);
        vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                {
                    cnt_1++;
                    int island_num = row * n + col;

                    if (row != n - 1 && grid[row + 1][col] == 1)
                    {
                        ds->union_by_size(island_num, island_num + n);
                    }

                    if (col != n - 1 && grid[row][col + 1] == 1)
                    {
                        ds->union_by_size(island_num, island_num + 1);
                    }
                }
            }
        }

        if (cnt_1 == n * n)
        {
            return (n * n);
        }

        if (cnt_1 == 0)
        {
            return 1;
        }

        int max_area = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                {
                    continue;
                }

                unordered_set<int> st;
                int total_area = 0;

                // neighbours of this island
                for (int i = 0; i < 4; i++)
                {
                    int new_row = row + moments[i].first;
                    int new_col = col + moments[i].second;

                    if (is_valid(new_row, new_col, n, n, grid))
                    {
                        int new_island_num = new_row * n + new_col;
                        int par = ds->findPar(new_island_num);
                        st.insert(par);
                    }
                }

                for (auto it : st)
                {
                    int area = ds->findSize(it);
                    total_area += area;
                }

                max_area = max(max_area, total_area);
            }
        }

        return (max_area + 1);
    }
};

int main()
{

    return 0;
}