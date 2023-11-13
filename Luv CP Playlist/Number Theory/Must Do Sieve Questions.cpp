#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int multiplies_count[N];
int element_ct[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        element_ct[x]++;
    }

    // iterate over multiples and store there count

    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            if (element_ct[j] != 0)
            {
                multiplies_count[i] += element_ct[j];
            }
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int p, q;
        cin >> p >> q;

        long long lcm_p_q = ((p * 1LL * q) / (__gcd(p, q)));
        int mult_ct_p = multiplies_count[p];
        int mult_ct_q = multiplies_count[q];

        int ans = mult_ct_p + mult_ct_q;

        if (lcm_p_q < N)
        {
            int multi_ct_p_q = multiplies_count[lcm_p_q];
            ans -= multi_ct_p_q;
        }

        cout << ans << endl;
    }

    return 0;
}