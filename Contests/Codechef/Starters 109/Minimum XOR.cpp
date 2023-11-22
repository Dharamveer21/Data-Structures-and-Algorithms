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
        int n;
        cin >> n;

        vector<int> arr;
        int XOR = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
            XOR = XOR ^ x;
        }

        int minXOR = XOR;

        for (int i = 0; i < n; i++)
        {
            int XOR_i = XOR ^ arr[i];
            minXOR = min(minXOR, XOR_i);
        }

        cout << minXOR << endl;
    }

    return 0;
}