#include <bits/stdc++.h>
using namespace std;

/*
Here 1337 is not a prime number hence we need to calculate ETF for it
Means it will have value -- fi(1337) = 1337 * (1 - 1 / 7) * (1 - 1 / 191) = 1140

now our questions is juts (a ^ b) % 1337 = ((a) ^ (b % 1140)) % 1337
*/

class Solution
{
    int binaryExponentiation(int a, int b, int M)
    {
        int ans = 1;

        while (b)
        {
            if (b & 1)
            {
                ans = (ans * 1LL * a) % M;
            }

            a = (a * 1LL * a) % M;
            b = b >> 1;
        }

        return ans;
    }

public:
    int superPow(int a, vector<int> &b)
    {
        int power = 0, ans;
        int n = b.size();

        for (int i = 0; i < n; i++)
        {
            int ind = n - i - 1;
            power = power + (b[ind] * 1LL * binaryExponentiation(10, i, 1140)) % 1140;
        }

        ans = binaryExponentiation(a, power, 1337);
        return ans;
    }
};

int main()
{

    return 0;
}