#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate_permutations(int ind, vector<int> &nums, vector<vector<int>> &all_permutations)
    {
        if (ind == nums.size())
        {
            all_permutations.push_back(nums);
        }

        int n = nums.size();

        for (int i = ind; i < n; i++)
        {
            swap(nums[ind], nums[i]);
            generate_permutations(ind + 1, nums, all_permutations);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> all_permutations;
        generate_permutations(0, nums, all_permutations);
        return all_permutations;
    }
};

int main()
{

    return 0;
}