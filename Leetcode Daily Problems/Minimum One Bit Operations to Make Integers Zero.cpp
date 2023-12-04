#include <bits/stdc++.h>
using namespace std;

/*
Approach -- consider the example of 1000 , 2^n type of number
1000 - 1001 - 1011 - 1010 - 1110 - 1111 - 1101 - 1100 - 0100 it took 8 steps for getting from 1000 to 100
because it has most significant bit at position 3 (0-indexed) -- means 2^3 , now we need to convert 100 to 10
which needs 2^2 steps , then it becomes 10 it needs 2^1 steps to convert to 1 , then 2^0 steps to convert to 0

hence position of most significant bit (1) for given number is n , then it takes 2^(n) + 2^(n-1) + 2^(n-2) + ... + 1
operations for converting it to 0 , now it is like an binary tree with nodes 1 , 2 , 4 , ... 2^n nodes which has total 2^(n+1) - 1
steps , now we need to convert the number from given state to 2^n , which i like converting 1101 to 1000 , but it is like going
backwards , thats why total steps will be 2^(n+1) - steps (to convert 101 to 000 means 0) it is a new subproblem of the same type thats
why we can use a recursive function to call it for the remaining part & we can get the remaining part by XOR it with 1000

we will first find the most significant bit & than we will XOR it with to find the rest part & use recursion to find its value
*/

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        if (n == 0)
        {
            return 0;
        }

        int mostSignificantBit = 0;

        for (int ind = 31; ind >= 0; ind--)
        {
            int bit = ((n >> ind) & 1);

            if (bit == 1)
            {
                mostSignificantBit = ind;
                break;
            }
        }

        int newNumber = (1 << mostSignificantBit);
        long long steps = (2 * 1LL * newNumber) - 1;
        steps -= minimumOneBitOperations(n ^ newNumber);
        return steps;
    }
};

// TC : O(log(n) * log(n)) = O((log(n))^2)
// SC : O (log(n)) -- stack space

int main()
{

    return 0;
}