#include <bits/stdc++.h>
using namespace std;

// memoisation
int min_operation(vector<int> &arr, int lo, int hi, vector<vector<int>> &mini_opr)
{
    if (lo + 1 == hi)
    {
        return 0;
    }

    if (mini_opr[lo][hi] != -1)
    {
        return mini_opr[lo][hi];
    }

    int min_total = INT_MAX;

    for (int cut = lo + 1; cut < hi; cut++)
    {
        int left_opr = min_operation(arr, lo, cut, mini_opr);
        int right_opr = min_operation(arr, cut, hi, mini_opr);
        int join_opr = arr[lo] * arr[cut] * arr[hi];

        int total_opr = left_opr + right_opr + join_opr;
        min_total = min(min_total, total_opr);
    }

    return mini_opr[lo][hi] = min_total;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> mini_opr(N, vector<int>(N, -1));
    return min_operation(arr, 0, N - 1, mini_opr);
}

int main()
{

    return 0;
}