#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We will use the simple idea that , if numbers are from 1 to n , then 0 <= (number-1) <= n-1
means number-1 is a valid index , also if all numbers were different each number will give a different index
so when we got a index we go at that index & make the number '-ve' to mark it as visited , now if any number is
repeated that means we have to go at index (num-1) two times , which is already visited
so that num is the repeated number , also due to this a index will not become '-ve' ever if there is no
number present in the array equal to (index + 1) . We check which value is still not zero & go to its index
*/

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        int repeatedNumber = 0;
        int missingNumber = 0;

        for (int ind = 0; ind < n; ind++)
        {
            int num = abs(nums[ind]);
            int index = (num - 1);

            if (nums[index] > 0)
            {
                nums[index] = (-1 * nums[index]);
                continue;
            }

            repeatedNumber = num;
        }

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];

            if (nums[ind] > 0)
            {
                missingNumber = ind + 1;
                break;
            }
        }

        return {repeatedNumber, missingNumber};
    }
};

// TC : O(N + N) = O(N)
// SC : O(1 + 1) = O(1)

int main()
{

    return 0;
}