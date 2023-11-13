#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    int ct = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            if (n % i == 0)
            {

                cout << i << " " << n / i << endl;
                ct += 1;
                sum += i;

                if (n / i != i)
                {
                    ct += 1;
                    sum += i;
                }
            }
        }
    }

    cout << ct << " " << sum << endl;

    return 0;
}

/*

x = p1^n1 * p2^n2 * p3^n3

x = p * p1 * p1 ... n1 times * p2 *p2 *p2 ... n2 times * p3 *p3 *p3 .... n3 times

any subset of these prime factors will give us a divisor of x
the empty subset is 1

to find no of divisors we can select any of the prime factor p1 n1 times and so with others or not it

count of divisors = (n1+1) * (n2 +1) * (n3+1) .....

sum of all diviors is --> add all divisors

= (1 + p1 + p1^2 +p1^3 + ....p1^n1) * (1+p2 + p2^2 + ... + p2^n2) * (1+p3 + p2^3 + ... + p3^n3) ...
these are Geometric progression

((p1^(n1 +1) - 1)/(p1 - 1)) * ((p2^(n2 +1) - 1)/(p2 - 1)) * ((p3^(n3 +1) - 1)/(p3 - 1)) ....

*/