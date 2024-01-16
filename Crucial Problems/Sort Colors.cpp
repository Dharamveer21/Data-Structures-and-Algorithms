#include <bits/stdc++.h>
using namespace std;

/*
Approach -- use Dutch National Flag Algorithm . n -- size of the array
We consider four positions , low , mid , high , n .

We assume that there is an hypothetical array of size 'n' where ,
1. 0 to low - 1 is array of '0'
2. low to mid - 1 is array of '1'
3. mid to high is array of random unsorted numbers
4. high + 1 to n - 1 is array of '2'

we have to sort the array between mid & high . We just have to consider all the senarios with arr[mid] & update the values till mid is less than or equal to high
*/

class Solution
{
protected:
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0;
        int high = n - 1;

        while (mid <= high)
        {
            int val = nums[mid];

            switch (val)
            {
            case 0:
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(nums[mid], nums[high]);
                high--;
                break;
            }
        }
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}