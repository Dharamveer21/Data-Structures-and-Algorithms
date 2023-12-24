#include <bits/stdc++.h>
using namespace std;

/*
Approach -- the final strings will be either starting with 0 or starting with 1
we calculate the difference between starting with 0 array with original array & starting with 1 array with original array
we just have to calulate operations for array starting with 0 & operations for array starting with 1 will be arr length - operation for
array starying with 0 and we just have to written maximum of them
*/

class Solution
{
public:
    int minOperations(string s)
    {
        int operationsForStartingWith0 = 0;
        int operationsForStartingWith1 = 0;
        int minOperations = 0, n = s.length();

        for (int ind = 0; ind < n; ind++)
        {
            char ch = s[ind];

            if (ind & 1)
            {
                operationsForStartingWith0 += (ch != '1');
            }

            else
            {
                operationsForStartingWith0 += (ch != '0');
            }
        }

        operationsForStartingWith1 = n - operationsForStartingWith0;
        minOperations = min(operationsForStartingWith0, operationsForStartingWith1);
        return minOperations;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}