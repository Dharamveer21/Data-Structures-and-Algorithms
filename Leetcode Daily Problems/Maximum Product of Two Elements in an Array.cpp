#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we can use 2 loops , else we can sort but the best solution would be just taking to variables biggest & secondBiggest
find their values while iterating over the array
*/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int biggest = 0, secondBiggest = 0;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];

            if (num > biggest)
            {
                secondBiggest = biggest;
                biggest = num;
            }

            else
            {
                secondBiggest = max(secondBiggest, num);
            }
        }

        int ans = (biggest - 1) * (secondBiggest - 1);
        return ans;
    }
};

// TC : O(N)
// TC : O(1)

int main()
{

    return 0;
}