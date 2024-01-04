#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we have to store the count of each element in the array , to find the number of operations needs
to delete them , now we can see that we need to delete every element with 3 deletes in one operation . So we
can see that when we divivde countNum by 3 , we can get 3 possible remainders

we need a hash map to store the count of each element

1. rem = 0 , means operations = countNum / 3
2. rem = 1 , means operations = (countNum - 4) / 3 + 2 --> 2 operations to delete that remaining 4
3. rem = 2 , means operations = (countNum - 2) / 3 + 1 --> 1 operation to delete that remaining 2

here we can observe that operations always equal to ceil value of (countNum/3)
if in case countNum == 1 , answer will be -1 because we cannot delete it
*/

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size(), minOperations = 0;
        unordered_map<int, int> countNum;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            countNum[num]++;
        }

        for (auto &node : countNum)
        {
            int numCount = node.second;

            if (numCount == 1)
            {
                minOperations = -1;
                break;
            }

            double count = (double)numCount;

            int operations = ceil(count / 3);
            minOperations += operations;
        }

        return minOperations;
    }
};

// TC : O(N) -- traversal of array & the map
// SC : O(N) -- store max N elements in map

int main()
{

    return 0;
}