#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
int fact[N];

int bin_exp(int a, int b)
{
    int result = 1;

    while (b)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % M;
        }

        a = (a * 1LL * a) % M;
        b = b >> 1;
    }

    return result;
}

int main()
{
    fact[0] = 1;
    
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % M;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        // kPn % M
        // k ! / (k-n)!

        int ans = fact[k];
        ans = (ans * 1LL * bin_exp(fact[k - n], M - 2)) % M;

        cout << ans << endl;
    }

    return 0;
}