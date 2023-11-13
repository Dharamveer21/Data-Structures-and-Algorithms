#include <bits/stdc++.h>
using namespace std;

/* 
   longest increasing subsequnece from start & end
   use them to find the longest bitonic subsequnec
*/

int longestBitonicSequence(vector<int> &arr, int n)
{
    int long_inc_start[n];
    int long_inc_end[n];
    int long_bitonic[n];
    int max_len = 0;

    for (int i = 0; i < n; i++)
    {
        int len = 0;
        long_inc_start[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                len = max(len, long_inc_start[j]);
            }
        }

        long_inc_start[i] += len;
    }

    for (int i = n - 1; i > -1; i--)
    {
        int len = 0;
        long_inc_end[i] = 1;

        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
            {
                len = max(len, long_inc_end[j]);
            }
        }

        long_inc_end[i] += len;
    }

    for (int i = 0; i < n; i++)
    {
        long_bitonic[i] = long_inc_start[i] + long_inc_end[i] - 1;
        max_len = max(long_bitonic[i], max_len);
    }

    return max_len;
}

int main()
{

    return 0;
}