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
private:
    bool is_valid(int row, int col, int &rows, int &cols, vector<vector<bool>> &vis)
    {
        if (row < 0 || row == rows || col < 0 || col == cols || !vis[row][col])
        {
            return false;
        }

        return true;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        vector<int> islands;
        int island_cnt = 0;
        DisjointSet *ds = new DisjointSet((m * n));

        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];

            if (vis[row][col])
            {
                islands.push_back(island_cnt);
                continue;
            }

            int island_num = row * m + col;
            vis[row][col] = true;

            island_cnt++;

            unordered_set<int> st;

            // neighbours of this island
            for (int j = 0; j < 4; j++)
            {
                int new_row = row + moments[j].first;
                int new_col = col + moments[j].second;

                if (is_valid(new_row, new_col, m, n, vis))
                {
                    int new_island_num = new_row * m + new_col;
                    int par = ds->findPar(new_island_num);
                    st.insert(par);
                }
            }

            int extra = st.size();
            island_cnt = island_cnt - extra;

            for (auto it : st)
            {
                ds->union_by_rank(it, island_num);
            }

            islands.push_back(island_cnt);
        }

        return islands;
    }
};

int main()
{

    return 0;
}