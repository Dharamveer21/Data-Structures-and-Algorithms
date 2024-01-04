#include <bits/stdc++.h>
using namespace std;

// lcm(a,b) * gcd(a,b) = a*b

int gcd(int a, int b)
{
    // a is dividend
    // a%b is remiander is next divisor
    // b is divisor which is next dividend

    // base condition if remiander is zero divisor is gcd
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    // euclid algo for finding gcd
    // divide upto remainder is not zero
    // then divisor is ans

    cout << gcd(12, 18) << endl;
    cout << __gcd(12, 18) << endl;
    return 0;
}