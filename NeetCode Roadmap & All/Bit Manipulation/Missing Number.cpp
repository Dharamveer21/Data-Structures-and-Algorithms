#include <bits/stdc++.h>
using namespace std;

/*
Approach -- As the distinct numbers present in the array is in the range 0 to n and size of array is n means
exactly one element is not present in the array . Hence we can use the property of XOR that a^a = 0 . as we
take a variable with XOR of all numbers from 0 to n & then do it XOR with all elements of the array , Each
element comes twice except the missing element hence its only it will remains all other will be 0 .
So , a^0 = a hence we got the missing number & return it .
*/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int missingNum = 0, n = nums.size();

        for (int ind = 0; ind < n; ind++)
        {
            int num1 = ind, num2 = nums[ind];
            missingNum = missingNum ^ num1 ^ num2;
        }

        missingNum = missingNum ^ n;
        return missingNum;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}