#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;

// if M ,= 10^18 then a*a is overflow so we use binary multiplication
// a * a= a+a+a... a times so we can take stepwise modulas
// to do a+a+a...a times in O(log n) time using binary multiplication

int binMultiply(long long a, long long b, int m)
{
    long long ans = 0;

    while (b)
    {
        if (b & 1)
        {
            ans = (ans + a) % m;
        }

        a = (a + a) % m;
        b = b >> 1;
    }

    return ans;
}

/* 
if b <= very large like (50)^(64^32)
then we have to use eular theorem

eular totient function -->

fi(n) = n * (1-1/p) * (1-1/p1) * .. where p ,p1 ... are all distinct prime factors of n
now for a prime no n --> fi(n) = n * (1 - 1 / n) = n-1

and according to eular theorem
(a^b) % M = (a ^ (b % fi(M)) % M  if M is prime fi(M) = M-1
^ --> power symbol

*/
int bin_exp_itr(long long a, long long b, int m)
{
    // if a <= 10^18 we just have to take a % M first
    int ans = 1;

    while (b)
    {
        if (b & 1)
        {
            ans = binMultiply(ans, a, m);
        }

        a = binMultiply(a, a, m);
        b = b >> 1;
    }

    return ans;
}

int main()
{
    // 50 ^ (64 ^ 32) % M

    cout << bin_exp_itr(50, bin_exp_itr(64, 32, M - 1), M);

    return 0;
}