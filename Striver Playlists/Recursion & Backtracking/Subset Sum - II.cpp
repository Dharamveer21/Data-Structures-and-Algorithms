#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate_subsets(int ind, vector<int> &subset, vector<int> &arr, unordered_map<int, int> &element_count, vector<vector<int>> &all_subsets)
    {
        if (ind == arr.size())
        {
            all_subsets.push_back(subset);
            return;
        }

        // not use the element
        generate_subsets(ind + 1, subset, arr, element_count, all_subsets);

        // use upto complete
        int num = arr[ind];
        int n = element_count[num];

        for (int i = 0; i < n; i++)
        {
            subset.push_back(num);
            generate_subsets(ind + 1, subset, arr, element_count, all_subsets);
        }

        for (int i = 0; i < n; i++)
        {
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr;
        vector<int> subset;
        unordered_map<int, int> element_count;
        vector<vector<int>> all_subsets;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            element_count[num]++;
        }

        for (auto &it : element_count)
        {
            int num = it.first;
            arr.push_back(num);
        }

        sort(arr.begin(), arr.end());
        generate_subsets(0, subset, arr, element_count, all_subsets);
        return all_subsets;
    }
};

int main()
{

    return 0;
}