#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we can do it using while loop by dividing it with 4 until it becomes 1
but there is another method which uses property of log
n == 4^x then log4 (n) == x , we just have to check whether x is integer or not
*/

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
        {
            return false;
        }

        if (n == 1)
        {
            return true;
        }
         
        double base = log(n) / log(4);
        return (base == (int)base);
    }
};

// TC : O(log4 (n))
// TC : O(1)

int main()
{

    return 0;
}