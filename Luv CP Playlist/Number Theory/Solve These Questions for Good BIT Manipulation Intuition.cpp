#include <bits/stdc++.h>
using namespace std;

// Monk & His Father Question
int setbit_ct(unsigned long long int num)
{
    int ct = 0;

    while (num)
    {
        if (num & 1)
        {
            ct++;
        }

        num = num >> 1;
    }

    return ct;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        unsigned long long int p;
        cin >> p;

        int mini_coins = setbit_ct(p);
        cout << mini_coins << "\n";
    }

    return 0;
}

// A XOR Challenge Question
int main()
{
    int c;
    cin >> c;

    int bit_ct = (int)log2(c) + 1;
    int a = 0, b = 0;
    vector<int> set_bits;

    for (int i = 0; i < bit_ct; i++)
    {
        // check 20th bit of c is set or upset

        if (c & (1 << i))
        {
            set_bits.push_back(i);
        }

        else
        {
            a = a | (1 << i);
            b = b | (1 << i);
        }
    }

    int sz = (1 << set_bits.size());
    long long ans = 0;

    for (int mask = 0; mask < sz; mask++)
    {
        int a1 = a, b1 = b;

        for (int i = 0; i < set_bits.size(); i++)
        {
            if (mask & (1 << i))
            {
                a1 |= (1 << set_bits[i]);
            }

            else
            {
                b1 |= (1 << set_bits[i]);
            }
        }

        long long product = a1 * b1;
        ans = ans > product ? ans : product;
    }

    cout << (c == 0 ? 1 : ans) << endl;

    return 0;
}