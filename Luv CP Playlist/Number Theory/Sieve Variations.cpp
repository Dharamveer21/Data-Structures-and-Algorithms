#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> isPrime(N, true);
vector<int> lowest_prime(N, 0), highest_prime(N, 0);

int main()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            lowest_prime[i] = highest_prime[i] = i;

            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                highest_prime[j] = i;

                if (lowest_prime[j] == 0)
                {
                    lowest_prime[j] = i;
                }
            }
        }
    }

    for (int i = 2; i < 100; i++)
    {
        cout << lowest_prime[i] << " " << highest_prime[i] << endl;
    }

    // prime factors using sieve
    int num;
    cin >> num;
    vector<int> prime_factors;

    while (num > 1)
    {
        int factor = highest_prime[num];

        while (num % factor == 0)
        {
            prime_factors.push_back(factor);
            num /= factor;
        }
    }

    for (int &prime : prime_factors)
    {
        cout << prime << " ";
    }

    cout << endl;

    // to find all divisors
    vector<int> divisors[N];

    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divisors[j].push_back(i);
        }
    }

    for (int i = 1; i < 100; i++)
    {
        for (int &divisor : divisors[i])
        {
            cout << divisor << " ";
        }

        cout << endl;
    }

    return 0;
}