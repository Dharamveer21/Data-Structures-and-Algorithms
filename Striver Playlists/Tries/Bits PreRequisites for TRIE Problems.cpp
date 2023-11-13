#include <bits/stdc++.h>
using namespace std;

int getXOR(int a, int b)
{
    int ans = 0;

    for (int i = 0; i < 31; i++)
    {
        int bit_a = ((a >> i) & 1);
        int bit_b = ((b >> i) & 1);

        int bit = abs(bit_a - bit_b);

        if (bit == 1)
        {
            ans = (ans | (1 << i));
        }
    }

    return ans;
}

int getBit(int c, int d)
{
    int bit = ((d >> c) & 1);
    return (bit == 1);
}

int setBit(int e, int f)
{
    f = (f | (1 << e));
    return f;
}

int main()
{

    return 0;
}