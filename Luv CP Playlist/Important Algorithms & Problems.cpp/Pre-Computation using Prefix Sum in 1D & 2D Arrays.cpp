#include <bits/stdc++.h>
using namespace std;

//  to print the sum of the 1D - array from index l to r in multiple queries , we first do the thing that we take
// the prefix sum of the array before executing the queries , now for any given query the sum between l & r is sum[r] - sum[l-1]

/*
Given 2D array arr of N*N integers . Given Q queries and in each query given a , b , c and d print sum of square
represented by (a,b) as top left corner & (c,d) as bottom right corner

Constraints
1 <= N <= 10^3
1 <= arr[i][j] <= 10^9
1 <= Q <= 10^5
1 <= a,b,c,d <=N
*/

const int N = 1e3 + 10;
int arr[N][N];
int pf[N][N];

int main()
{
    /*
    brute force solution

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b, c, d;
        cin >> a, b, c, d;

        long long sum = 0;

        for (int x = a; x <= c; x++)
        {
            for (int y = b; y <= d; y++)
            {
                sum += arr[x][y];
            }
        }

        cout << sum << endl;
    }

    its complexity is O(N^2) + O(Q*N^2) = 10^5 * 10^6 = 10^11 which gives tle
    */

    /*
    Optimised Solution , use 1 based indexing in prefix sum problems

    we first define the prefix sum of any cell (i,j) is the value of the sum of rectangle made between (1,1) and (i,j)
    so in this way the prefix sum of any (i,j) in terms of recursion of cells before it will be , here pf denotes the prefix sum
    pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1]

    for sum between (a,b) & (c,d) in query we can make it in terms of pf as :-
    sum = pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1]
    */

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b, c, d;
        cin >> a, b, c, d;

        long long sum = 0;
        sum = pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1];

        cout << sum << endl;
    }

    // its complexity  O(N*N) + O(N) = 10^6 + 10^5 = 10^6 , it is optimal

    return 0;
}