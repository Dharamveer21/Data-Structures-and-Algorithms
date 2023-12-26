#include <bits/stdc++.h>
using namespace std;

/* 
Approach -- Put the maximum element of the unsorted array at the last by adjacent swapping
after each iteration the max will come at last & unosorted array's size will be smaller by 1
*/

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();

        for (int ind1 = 0; ind1 < n; ind1++)
        {
            for (int ind2 = 0; ind2 < n - ind1 - 1; ind2++)
            {

            }
        }
    }
};

// TC : O(N ^ 2)
// SC : O(1)

int main()
{

    return 0;
}