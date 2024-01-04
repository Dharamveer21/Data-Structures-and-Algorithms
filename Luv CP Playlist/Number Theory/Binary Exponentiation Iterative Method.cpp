#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 10;

// a <= 19^9 , b <= 10^9 M = 10^9

int bin_exp_itr(int a, int b)
{
    int ans = 1;

    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }

        a = (a * 1LL * a) % M;
        b = b >> 1;
    }

    return ans;
}

int main()
{

    return 0;
}