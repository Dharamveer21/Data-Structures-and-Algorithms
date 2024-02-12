#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Moore's Voting Algorithm where we pick the first element as the current index as the majority
element then we cnt++ if we find that element & cnt-- if we find another element .
if cnt == 0, we pick the element at current index & again implement the above one
So, we call the majority element element which is last one whose sum still not perishes

This works because the majority element is present more than (n/2) times means even if it is at the alternate
positions , even then atleast at one position its sum will not perish due to more than (n/2) occurrenece

There is an observation :-
                           1 majority element if n/2 occurrence
                           2 majority element if n/3 occurrence
                           3 majority element if n/4 occurrence
                           4 majority element if n/5 occurrence
                       (k-1) majority element if n/k occurrence

here we need to take two majority element but when we got an element which is not Equal to any majority Element
& the count of each majortiy Element is nonZero in that case we can decrease the count of both Elements .
*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> majorityElements;

        int count1 = 0, majority1 = INT_MAX;
        int count2 = 0, majority2 = INT_MIN;

        for (int ind = 0; ind < n; ind++)
        {
            int currElement = nums[ind];

            if (majority1 == currElement)
            {
                count1++;
            }

            else if (majority2 == currElement)
            {
                count2++;
            }

            else if (count1 == 0)
            {
                majority1 = currElement;
                count1++;
            }

            else if (count2 == 0)
            {
                majority2 = currElement;
                count2++;
            }

            else
            {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;

        for (int ind = 0; ind < n; ind++)
        {
            int currElement = nums[ind];

            if (currElement == majority1)
            {
                count1++;
            }

            else if (currElement == majority2)
            {
                count2++;
            }
        }

        if (count1 > n / 3)
        {
            majorityElements.push_back(majority1);
        }

        if (count2 > n / 3)
        {
            majorityElements.push_back(majority2);
        }

        return majorityElements;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}