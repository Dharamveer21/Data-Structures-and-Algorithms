#include <bits/stdc++.h>
using namespace std;

/*
Approach -- as we see the constraints are nums[i] <= nums.size() <= 200
which means we can use a hash array to find the count of each element while traversing

we will put the element in the row equal to its count , means if any element has count = 0
we put it in 0th row , if its count = 2 means it has already appeared in row 0 & 1 hence we put it in row = 2

we take a freq array & update its count each item & put the element in row == new freq
*/

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> freq(n + 1, -1);
        vector<vector<int>> ans;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            int row = ++freq[num];

            if (row == ans.size())
            {
                ans.push_back({});
            }

            ans[row].push_back(num);
        }

        return ans;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}