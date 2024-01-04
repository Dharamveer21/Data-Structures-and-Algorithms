#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e18 + 7;

// if M = 10^18 then a * a is overflow so we use binary multiplication
// a * a = a + a + a ... a times so we can take stepwise modulas
// to do a + a + a ... a times in O(log n) time using binary multiplication

int binMultiply(long long a, long long b)
{
    long long ans = 0;

    while (b)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        
        a = (a + a) % M;
        b = b >> 1;
    }

    return ans;
}

int bin_exp_itr(long long a, int b)
{
    // if a <= 10^18 we just have to take a % M first
    int ans = 1;

    while (b)
    {
        if (b & 1)
        {
            ans = binMultiply(ans, a);
        }

        a = binMultiply(a, a);
        b = b >> 1;
    }

    return ans;
}

int main()
{

    return 0;
}