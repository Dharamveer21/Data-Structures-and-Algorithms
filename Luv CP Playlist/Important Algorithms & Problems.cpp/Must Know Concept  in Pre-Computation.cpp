#include <bits/stdc++.h>
using namespace std;

// There is an array arr with all elements as 0 , we have Q queries in each query we should add the a num k for elements between index a & b
// After all query operations are done then return the maximum element of the array

/*
Constraints
3 <= n <= 10^7 -- size of the array
1 <= m <= 2 *10^5 -- queries
1 <= a <= b <= n -- indexces a,b in each query
0 <= k <= 10^9 -- value added to all elements between index a & index b in each query
*/

const int N = 1e7 + 10;
long long arr[N];

int main()
{
    /*
    brute force code

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b, k;
        cin >> a >> b >> k;

        for (int i = a; i <= b; i++)
        {
            arr[i] + k;
        }
    }

    long long mx = -1;

    for (int i = 1; i <= n; i++)
    {
        if (mx < arr[i])
        {
            mx = arr[i];
        }
    }

    cout << mx << endl;

    time complexity = O(m*n + n) = 2 * 10^5 * 10^7 = 2 * 10^12 -- tle
    */

    // Optimal Solution
    /*
      for any query l to r if we simply do add k at arr[l] and subtract k from arr[r + 1] then when we take prefix sum
      elements before l will not be added with k , because they will not have k before them
      elements between l and r will be added with k each
      elements after r will be added with k & subtracted with k also means they also remains same

      that means by this method when we take prefix sum of the array we got the final arr after the operations
      all queries are independent of each other , so we can generalise it over & after all queries

      so in each query we just have to do arr[l] = arr[l] + k and arr[r+1] = arr[r+1] - k
    */

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        arr[a] += k;
        arr[b + 1] -= k;
    }

    // prefix sum
    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }

    long long mx = -1;

    for (int i = 1; i <= n; i++)
    {
        if (mx < arr[i])
        {
            mx = arr[i];
        }
    }

    cout << mx << endl;

    // time complexity = O(m + n) = 2 * 10 ^ 5 + 10 ^ 7 ~ 10 ^ 7
    return 0;
}