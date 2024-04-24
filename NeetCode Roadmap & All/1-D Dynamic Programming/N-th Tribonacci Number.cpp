#include <bits/stdc++.h>
using namespace std;

// Recursion & Memoisation
class Solution
{
protected:
    int generateNthTermOfTribonacci(int n, vector<int> &termsOfTheTribonacciSeries)
    {
        if (termsOfTheTribonacciSeries[n] != -1)
            return termsOfTheTribonacciSeries[n];

        int nMinus3thTerm = generateNthTermOfTribonacci(n - 3, termsOfTheTribonacciSeries);
        int nMinus2thTerm = generateNthTermOfTribonacci(n - 2, termsOfTheTribonacciSeries);
        int nMinus1thTerm = generateNthTermOfTribonacci(n - 1, termsOfTheTribonacciSeries);

        int nthTerm = nMinus3thTerm + nMinus2thTerm + nMinus1thTerm;
        return termsOfTheTribonacciSeries[n] = nthTerm;
    }

public:
    int tribonacci(int n)
    {
        if (n == 0 || n == 1)
            return n;

        vector<int> termsOfTheTribonacciSeries(n + 1, -1);

        termsOfTheTribonacciSeries[0] = 0;
        termsOfTheTribonacciSeries[1] = 1;
        termsOfTheTribonacciSeries[2] = 1;

        int nthTerm = generateNthTermOfTribonacci(n, termsOfTheTribonacciSeries);
        return nthTerm;
    }
};

// TC : O(N)
// SC : O(N)

// Tabulation
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0 || n == 1)
            return n;

        vector<int> termsOfTheTribonacciSeries(n + 1, -1);

        termsOfTheTribonacciSeries[0] = 0;
        termsOfTheTribonacciSeries[1] = 1;
        termsOfTheTribonacciSeries[2] = 1;

        for (int term = 3; term <= n; term++)
        {
            int currTerm = termsOfTheTribonacciSeries[term - 3];
            currTerm += termsOfTheTribonacciSeries[term - 2];
            currTerm += termsOfTheTribonacciSeries[term - 1];

            termsOfTheTribonacciSeries[term] = currTerm;
        }

        int nthTerm = termsOfTheTribonacciSeries[n];
        return nthTerm;
    }
};

// TC : O(N)
// SC : O(N)

// Space Optimization
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0 || n == 1)
            return n;

        vector<int> termsOfTheTribonacciSeries(3, -1);

        termsOfTheTribonacciSeries[0] = 0;
        termsOfTheTribonacciSeries[1] = 1;
        termsOfTheTribonacciSeries[2] = 1;

        for (int term = 3; term <= n; term++)
        {
            int currTerm = termsOfTheTribonacciSeries[2];
            currTerm += termsOfTheTribonacciSeries[1];
            currTerm += termsOfTheTribonacciSeries[0];

            termsOfTheTribonacciSeries[0] = termsOfTheTribonacciSeries[1];
            termsOfTheTribonacciSeries[1] = termsOfTheTribonacciSeries[2];
            termsOfTheTribonacciSeries[2] = currTerm;
        }

        int nthTerm = termsOfTheTribonacciSeries[2];
        return nthTerm;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}