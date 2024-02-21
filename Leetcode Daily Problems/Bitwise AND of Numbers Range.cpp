#include <bits/stdc++.h>
using namespace std;

/*
Approach -- This is an observation based question here we can see that if we take 4 numbers --

9  -- 0000001001
10 -- 0000001010
11 -- 0000001011
12 -- 0000001100
   == 0000001000
here we can see that we need to find the largest common prefix between left & right value
*/

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int shiftCount = 0;

        while (left != right)
        {
            left = left >> 1;
            right = right >> 1;

            shiftCount++;
        }

        int largestCommonPrefix = left;
        int bitwiseAndOfAllNum = largestCommonPrefix << shiftCount;

        return bitwiseAndOfAllNum;
    }
};

// TC : O(log(N)) , N = right
// SC : O(1)

int main()
{

    return 0;
}