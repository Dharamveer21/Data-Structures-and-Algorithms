#include <bits/stdc++.h>
using namespace std;

/*
Approach -- there is a pattern in the given table
the nth row is generated on the basis of (n-1)th row
if nth row : its first half is (n-1)th row & second half is complement of (n-1)th row

that means we just have to find the curr k position ,
if it is present in first half of curr row with ind i -- it will also present on i index on prev row
if it is present in second half of curr row with ind i -- we have to find its index in first row & corresponding complement

n should be 0-based & k should be one based for ease of calculations
*/

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        int ind = k;
        n = n - 1;
        bool complement = false;

        while (n > 0)
        {
            int size = (1 << n);
            int halfSize = size / 2;
            n = n - 1;

            if (ind <= halfSize)
            {
                continue;
            }

            ind = ind - halfSize;
            complement = !complement;
        }

        return (complement);
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}