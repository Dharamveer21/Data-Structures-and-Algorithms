#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int power(int x, int n)
{

    if (n == 0)
    {
        return 1;
    }

    int cal = power(x, n / 2);

    if (n & 1)
    {
        return (x * ((cal * 1LL * cal) % M) % M);
    }

    else
    {
        return ((cal * 1LL * cal) % M);
    }
}

int main()
{
    cout << power(3, 6) << endl;
    return 0;
}