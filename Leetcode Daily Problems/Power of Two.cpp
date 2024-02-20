#include <bits/stdc++.h>
using namespace std;

/*
Approach -- There are many approaches to do this problem , divide it by 2 until it reduces to 1
Or we can count the setBits in the binary of the given number . But the best approach will be using the simple
concept that any number 'n' is power of two then it is of the form - 100000 (MSB is 1 and all other bits are 0)
then 'n-1' is of the form 011111 (MSB is 0 all others are 1) .

So, the bitwise & of n and n-1 is n & n-1 = 0 . if it is not zero it is not divisible by 2
*/

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return ((n <= 0) ? false : (((n & n - 1) == 0) ? true : false));
    }
};

// TC : O(1)
// SC : O(1)

int main()
{

    return 0;
}