#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Moore's Voting Algorithm where we pick the first element as the current index as the majority
element then we cnt++ if we find that element & cnt-- if we find another element .
if cnt == 0, we pick the element at current index & again implement the above one
So, we call the majority element element which is last one whose sum still not perishes

This works because the majority element is present more than (n/2) times means even if it is at the alternate
positions , even then atleast at one position its sum will not perish due to more than (n/2) occurence
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size(), cnt = 0;
        int majorityElement = -1;

        for (int ind = 0; ind < n; ind++)
        {
            int element = nums[ind];

            if (cnt == 0)
            {
                majorityElement = element;
                cnt++;
            }

            else if (element == majorityElement)
            {
                cnt++;
            }

            else
            {
                cnt--;
            }
        }

        return majorityElement;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}