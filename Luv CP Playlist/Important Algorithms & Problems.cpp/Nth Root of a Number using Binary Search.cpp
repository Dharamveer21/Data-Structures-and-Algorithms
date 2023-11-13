#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6;

double multiply(double mid, int n)
{
    double ans = 1;

    while (n--)
    {
        ans = ans * mid;
    }

    return ans;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;

    double lo = 1, hi = x, mid;

    // binary search
    while (hi - lo > eps)
    {
        mid = (lo + hi) / 2;

        if (multiply(mid, n) < x)
        {
            lo = mid;
        }

        else
        {
            hi = mid;
        }
    }

    cout << setprecision(10) << lo << " " << hi << endl;
    cout << pow(x, 0.5) << endl;

    return 0;
}