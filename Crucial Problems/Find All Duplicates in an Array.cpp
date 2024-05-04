#include <bits/stdc++.h>
using namespace std;

/*
Approach -- In this problem the constarints are [1,n] and size of array is n means indexes are in range [0,n-1]
so we can use (element-1) as valid index in the array . So , the solution is simple whenever we traversing the
array we just take (element-1) as index and mark the value at that index at -ve of it . This negative means
we have visited (index + 1) element before in the array . Now suppose if we come at this index again and saw
this value is negative then we were sure that the (index + 1) is repeated in the array thats why its negative .
*/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> allDuplicates;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            int index = abs(num) - 1;
             
            if (nums[index] < 0)
            {
                int repeatedNumber = index + 1;
                allDuplicates.push_back(repeatedNumber);
            }

            nums[index] = (-1) * abs(nums[index]);
        }

        return allDuplicates;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}