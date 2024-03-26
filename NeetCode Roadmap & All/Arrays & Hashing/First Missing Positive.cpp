#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here we can see that the firstMissingPositive is between 1 <= FMP <= n+1 , where n is the size of the
array because atmost all numbers upto n present in the array then (n+1) is the max possible answer . So , all
numbers out of this range is useless , so mark all of them as (n+1) to ignore them while traversing .

Now , we use a simple technique we go to each element and take (element - 1) as index and go at that index and
mark the element as -ve . Now , when we traverse the updated array and which ever element is not negative its
index is the first index which is not present in the array . Hence it is the first missing positive element .
*/

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        int firstMissingPositiveNumber = n + 1;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            nums[ind] = ((num <= 0 || num > n) ? (n + 1) : num);
        }

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];

            if (abs(num) == n + 1)
                continue;
            
            int index = abs(num) - 1;
            nums[index] = (-1 * abs(nums[index]));
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int num = nums[ind], index = ind + 1;
            firstMissingPositiveNumber = ((num > 0) ? index : firstMissingPositiveNumber);
        }
        
        return firstMissingPositiveNumber;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}