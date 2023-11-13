#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> prime_factors;

    for (int i = 2; i * i <= n; i++)
    {
        // find minimuum prime factor and finish it
        // then update the number afcter removing all occurence of that factor
        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n = n / i;
        }
    }

// O(sqrt(N))

    if (n > 1)
    {
        prime_factors.push_back(n);
    }

    for (int &prime : prime_factors)
    {
        cout << prime << " ";
    }

    return 0;
}

/*
  the minimum divisor of any number after 1 is always a prime number
  like 91 has first divisor 7 which is prime

  for a composite no atleast 1 factor exists before or equal to sqrt(N)
  but not for a prime number
*/