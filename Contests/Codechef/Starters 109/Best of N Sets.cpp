#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;

        cout << ((2 * max(x, y)) - 1) << endl;
    }

    return 0;
}