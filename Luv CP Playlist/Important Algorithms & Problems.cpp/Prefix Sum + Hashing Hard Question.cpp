#include <bits/stdc++.h>
using namespace std;

/*
Given a string we have certain queries , in each query we need to find whether it is possible to make the string palindrome or not using letters between any indexes l & r
*/

/*
Constaints
1 <= t <= 10 -- test cases
1 <= N,Q <= 10^5
1 <= L <= R <= N
'a' <= S[i] <= 'z' for 1 <= i <= N
*/

const int N = 1e5 + 10;
int hsh[26][N];

int main()
{
    /*
    // brute force
    // the simple logic for a given characters can create a palindrome string is possible or not :- the count for each letter must be even & only 1 letter can have odd count

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string str;
        cin >> str;

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            int hsh[26];

            for (int i = 0; i < 26; i++)
            {
                hsh[i] = 0;
            }

            l--, r--; // because our string is 0 based but l & r are 1 based

            // store count of each character in the string
            for (int i = l; i <= r; ++i)
            {
                hsh[str[i] - 'a']++;
            }

            int odd_cnt = 0;

            // no of characters having odd count
            for (int i = 0; i < 26; ++i)
            {
                if (hsh[i] & 1)
                {
                    odd_cnt++;
                }
            }

            if (odd_cnt > 1)
            {
                cout << "NO\n";
            }

            else
            {
                cout << "YES\n";
            }
        }
    }

    // time complexity-- O(t * (n + q * (26 + n + 26))) = O(t * q * n) = 10 * 10^5 * 10^5 = 10^11 -- tle
   */

    // Optimal Solution
    // Plaindrome logic and make a 2D array correrespond to each character of alphabets and then take prefix sum
    // it will work as we just put 1 or 0 if our character is present on that location or not in the array
    // finally we take prefix sum & use it to find the count of the character between any 2 indexes in O(1)

    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < N; j++)
            {
                hsh[i][j] = 0;
            }
        }

        int n, q;
        cin >> n >> q;
        string str;
        cin >> str;

        for (int i = 0; i < n; i++)
        {
            int ind1 = str[i] - 'a';
            int ind2 = i + 1;

            hsh[ind1][ind2]++;
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                hsh[i][j] += hsh[i][j - 1];
            }
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            int odd_cnt = 0;

            // no of characters having odd count
            for (int i = 0; i < 26; ++i)
            {
                int cnt = hsh[i][r] - hsh[i][l - 1];

                if (cnt & 1)
                {
                    odd_cnt++;
                }
            }

            if (odd_cnt > 1)
            {
                cout << "NO\n";
            }

            else
            {
                cout << "YES\n";
            }
        }
    }

    // time complexity-- O(t * (n * 26 + n + 26 + q * 26)) = O(t * (q + n)) = 10 * (10^5 + 10^5) = 10^6 -- tle

    return 0;
}