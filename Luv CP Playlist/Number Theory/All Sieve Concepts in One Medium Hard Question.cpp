#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;

int hp[N];
bool canRemove[N];

vector<int> distinctPF(int x)
{
    vector<int> pf;

    while (x > 1)
    {
        int prime = hp[x];
        pf.push_back(prime);

        while (x % prime == 0)
        {
            x /= prime;
        }
    }

    return pf;
}

int main()
{
    for (int i = 2; i < N; i++)
    {
        if (hp[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                hp[j] = i;
            }
        }
    }

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        canRemove[x] = true;
    }

    for (int i = 2; i < N; i++)
    {
        if (canRemove[i] == true)
        {
            for (long long j = i; j < N; j = j * i)
            {
                canRemove[j] = true;
            }
        }
    }

    canRemove[1] = true;

    while (q--)
    {
        int x;
        cin >> x;

        if (x == 0 || x == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        vector<int> pf = distinctPF(x);
        bool isPossible = false;

        for (int i = 0; i < pf.size(); i++)
        {
            for (int j = i; j < pf.size(); j++)
            {
                int product = pf[i] * pf[j];

                if (i == j && x % product != 0)
                {
                    continue;
                }

                int toRemove = x / product;

                if (canRemove[toRemove] || toRemove == 1)
                {
                    isPossible = true;
                    break;
                }
            }

            if (isPossible)
            {
                break;
            }
        }

        cout << (isPossible == true ? "YES\n" : "NO\n");
    }

    return 0;
}