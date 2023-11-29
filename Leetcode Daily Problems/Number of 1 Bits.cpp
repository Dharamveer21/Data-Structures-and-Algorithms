#include <bits/stdc++.h>
using namespace std;

/*
Approach -- use rightshift to remove bits from last and use bitwise '&' for getting the bit value
if it is 0 it will not change hammingWeight , if 1 it will increase it by 1
*/

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int hWeight = 0;

        for (int ind = 0; ind < 32; ind++)
        {
            int bit = ((n >> ind) & 1);
            hWeight += bit;
        }

        return hWeight;
    }
};

// TC : log(n)
// SC : O(1)

int main()
{

    return 0;
}