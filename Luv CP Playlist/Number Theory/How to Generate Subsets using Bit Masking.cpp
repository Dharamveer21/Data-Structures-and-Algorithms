#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> all_subsets;

        // pow(2,n) = (1<<n)

        for (int mask = 0; mask < (1 << n); mask++)
        {
            vector<int> subset;

            for (int j = 0; j < n; j++)
            {
                if (mask & (1 << j))
                {
                    subset.push_back(nums[j]);
                }
            }

            all_subsets.push_back(subset);
        }

        return all_subsets;
    }
}; // O(n * (2^n))

int main()
{

    return 0;
}