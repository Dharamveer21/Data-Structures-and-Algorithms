#include <bits/stdc++.h>
using namespace std;

void DFS(int vertex, int par, vector<int> tree[], vector<int> &Subtree_sum, vector<int> &val)
{
    for (int child : tree[vertex])
    {
        if (child == par)
        {
            continue;
        }

        DFS(child, vertex, tree, Subtree_sum, val);

        Subtree_sum[vertex] += Subtree_sum[child];
    }

    Subtree_sum[vertex] += val[vertex];
}

int deleteEdge(vector<int> &A, vector<vector<int>> &B)
{
    int N = A.size();
    vector<int> tree[N];

    for (int i = 0; i < N - 1; i++)
    {
        int v1 = B[i][0] - 1;
        int v2 = B[i][1] - 1;

        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    vector<int> Subtree_sum(N, 0);
    DFS(0, -1, tree, Subtree_sum, A);
    int total = Subtree_sum[0];
    long long mx_product = -1;

    for (int i = 1; i < N; i++)
    {
        int value = Subtree_sum[i];

        if (mx_product < (value) * (1LL) * (total - value))
        {
            mx_product = (value) * (1LL) * (total - value);
        }
    }
    const int M = 1e9 + 7;
    return ((mx_product) % (M));
}

int main()
{

    return 0;
}
