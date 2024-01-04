#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, true);

int main()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int num;
        cin >> num;

        if (isPrime[num] == true)
        {
            cout << "Prime " << endl;
        }

        else
        {
            cout << "Not Prime " << endl;
        }
    }

    // O(N * log(logN))

    return 0;
}