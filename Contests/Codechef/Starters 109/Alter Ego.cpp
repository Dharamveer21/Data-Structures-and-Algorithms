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

        vector<int> arrA1, arrA2, ans(n);
        int oddCount = 0, halfSize = n / 2;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (x & 1)
            {
                oddCount++;
                arrA1.push_back(x);
            }

            else
            {
                arrA2.push_back(x);
            }
        }

        if (oddCount & 1)
        {
            cout << -1 << endl;
            continue;
        }

        sort(arrA1.begin(), arrA1.end());
        sort(arrA2.begin(), arrA2.end());

        int n1 = (arrA1.size() / 2);
        int n2 = (arrA2.size() / 2);

        for (int i = 0; i < n1; i++)
        {
            int diff = arrA1[i];
            int sum = arrA1[n1 + i];

            int num1 = ((sum + diff) / 2);
            int num2 = ((sum - diff) / 2);

            ans[i] = num1;
            ans[halfSize + i] = num2;
        }

        for (int i = 0; i < n2; i++)
        {
            int diff = arrA2[i];
            int sum = arrA2[n2 + i];

            int num1 = ((sum + diff) / 2);
            int num2 = ((sum - diff) / 2);

            ans[i + n1] = num1;
            ans[halfSize + i + n1] = num2;
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}