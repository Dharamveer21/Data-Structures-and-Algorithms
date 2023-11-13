#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;

    while (t--)
    {
        int rows, cols, row, col;
        cin >> rows >> cols;
        cin >> row >> col;

        long long ans = max((max(row - 1, rows - row)) * 1LL * cols, (max(col - 1, cols - col)) * 1LL * rows);
        cout << ans << endl;
    }

    return 0;
}