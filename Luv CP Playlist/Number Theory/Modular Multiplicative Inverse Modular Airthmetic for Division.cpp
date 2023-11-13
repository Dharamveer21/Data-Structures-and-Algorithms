#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
int fact[N];

int bin_exp(int a, int b, int m)
{
    int ans = 1;

    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % m;
        }

        a = (a * 1LL * a) % M;
        b = b >> 1;
    }

    return ans;
}

int main()
{
    // (a / b) % M = (a % M * MMI(b) % M) % M;
    // where MMI(b) is modular multiplicative inverse of b

    /*
      as we know if a * b == 1 b is multiplicative inverse of a
      and if a % b == 1 then b is MMI of a


      Fermet theorem (A ^ (M-1)) % M = 1
      where M is prime and A is not a multiple of M

      then (A ^ (M-2)) % M = A^(-1)

      then MMI of any A is ((A ^ (M-2)) % M)
      binexp(A,M-2)
      which can be calculated using binary exponentiation
    */

    /*
      N children and k tofees , K < N count no fo ways to distribute toffies among n childern
      ans = nCk;
      N <= 10^6, K <= N
     */

    fact[0] = 1;

    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % M;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int n, k;
        cin >> n >> k;

        int ans = fact[n];
        int div = (fact[k] * 1LL * fact[n - k]) % M;
        ans = (ans * 1LL * bin_exp(div, M - 2, M)) % M;
        cout << ans << endl;
    }

    return 0;
}