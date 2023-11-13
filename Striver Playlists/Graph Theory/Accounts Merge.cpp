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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int nodes = accounts.size();
        DisjointSet *ds = new DisjointSet(nodes);
        unordered_map<string, int> map_Mail_nodes;

        for (int name = 0; name < nodes; name++)
        {
            for (int email = 1; email < accounts[name].size(); email++)
            {
                string mail = accounts[name][email];

                if (map_Mail_nodes.find(mail) == map_Mail_nodes.end())
                {
                    map_Mail_nodes[mail] = name;
                }

                else
                {
                    ds->union_by_rank(name, map_Mail_nodes[mail]);
                }
            }
        }

        vector<string> merged_accounts[nodes];

        for (auto it : map_Mail_nodes)
        {
            string email = it.first;
            int name = it.second;
            name = ds->findPar(name);

            merged_accounts[name].push_back(email);
        }

        vector<vector<string>> ans;

        for (int name = 0; name < nodes; name++)
        {
            vector<string> all_mails;

            if (merged_accounts[name].size() == 0)
            {
                continue;
            }
            
            string person = accounts[name][0];
            all_mails.push_back(person);
             
            sort(merged_accounts[name].begin(), merged_accounts[name].end());

            for (int i = 0; i < merged_accounts[name].size(); i++)
            {
                all_mails.push_back(merged_accounts[name][i]);
            }

            ans.push_back(all_mails);
        }
        
        return ans;
    }
};

int main()
{

    return 0;
}