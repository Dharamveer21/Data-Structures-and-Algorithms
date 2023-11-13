#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tabulation
    int matrixMultiplication(vector<int> &arr, int N)
    {
        vector<vector<int>> mini_opr(N, vector<int>(N));

        for (int lo = N - 2; lo >= 0; lo--)
        {
            for (int hi = lo + 1; hi < N; hi++)
            {
                if (lo + 1 == hi)
                {
                    mini_opr[lo][hi] = 0;
                    continue;
                }

                int min_total = INT_MAX;

                for (int cut = lo + 1; cut < hi; cut++)
                {
                    int left_opr = mini_opr[lo][cut];
                    int right_opr = mini_opr[cut][hi];
                    int join_opr = arr[lo] * arr[cut] * arr[hi];

                    int total_opr = left_opr + right_opr + join_opr;
                    min_total = min(min_total, total_opr);
                }

                mini_opr[lo][hi] = min_total;
            }
        }

        return mini_opr[0][N - 1];
    }

    // space optimization
    int matrixMultiplication(vector<int> &arr, int N)
    {
        vector<vector<int>> mini_opr(N, vector<int>(N, -1));

        for (int lo = N - 2; lo >= 0; lo--)
        {
            for (int hi = lo + 1; hi < N; hi++)
            {
                if (lo + 1 == hi)
                {
                    mini_opr[lo][hi] = 0;
                    continue;
                }

                int min_total = INT_MAX;

                for (int cut = lo + 1; cut < hi; cut++)
                {
                    int left_opr = mini_opr[lo][cut];
                    int right_opr = mini_opr[cut][hi];
                    int join_opr = arr[lo] * arr[cut] * arr[hi];

                    int total_opr = left_opr + right_opr + join_opr;
                    min_total = min(min_total, total_opr);
                }

                mini_opr[lo][hi] = min_total;
            }
        }

        return mini_opr[0][N - 1];
    }
};

int main()
{

    return 0;
}