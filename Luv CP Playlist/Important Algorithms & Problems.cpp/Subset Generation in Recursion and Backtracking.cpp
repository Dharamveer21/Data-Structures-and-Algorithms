#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> all_subsets;

    void generate_subsets(int ind, vector<int> &subset, vector<int> &nums)
    {
        if (ind < 0)
        {
            all_subsets.push_back(subset);
            return;
        }
         
        // consider ind
        subset.push_back(nums[ind]);
        generate_subsets(ind - 1, subset, nums);
        subset.pop_back();

        // not consider ind
        generate_subsets(ind - 1, subset, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> subset;
        generate_subsets(nums.size() - 1, subset, nums);
        return all_subsets;
    }
};

int main()
{

    return 0;
}