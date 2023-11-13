#include <bits/stdc++.h>
using namespace std;

/*
Formulae of Modular Airthematic

Addition -- (a + b) % M = ((a % M) + (b % M)) % M;

Subtraction -- (a - b) % M = ((a % M) - (b % M) + M) % M;

Multiplication -- (a *b) % M = ((a % M) * (b % M)) % M;

Division -- (a / b) % M = ((a % M) * (b ^ -1) % M) % M;

here b^-1 is modular multiplicative inverse of b
*/

/*
Given a number N , Print its factorial
Constraints
1 <= N <= 100

Print answer module M
where M = 47
*/

/*
it is working because the fact(10) = 1 * 2 * 3 * 4 ... * 9 * 10
so the fact(10) % M = 1 % M * 2 % M ..... 9 % M * 10 % M
which means that it doesn't matter if we take mod at each step or at last , answer will be same
*/

/*
Significance of M = 10^9 + 7
1. it is a prime number -- its multiplicative inverse is easy to find
2. very close to integer range
*/

int main()
{
    int n;
    cin >> n;

    long long fact = 1;

    for (int i = 2; i <= n; i++)
    {
        fact = (fact * i) % 47;
    }

    cout << fact;

    return 0;
}