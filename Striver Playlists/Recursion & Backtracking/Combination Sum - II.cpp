#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // using map
    void combinations(int ind, int sum, vector<int> &combination, int &target, vector<int> &candidate, unordered_map<int, int> &element_count, vector<vector<int>> &all_combinations)
    {
        if (sum == target)
        {
            all_combinations.push_back(combination);
            return;
        }

        if (sum > target)
        {
            return;
        }

        if (ind == candidate.size())
        {
            return;
        }

        int num = candidate[ind];

        // not pick the element
        combinations(ind + 1, sum, combination, target, candidate, element_count, all_combinations);

        // pick upto limit
        for (int i = 0; i < element_count[num]; i++)
        {
            combination.push_back(num);
            combinations(ind + 1, sum + num, combination, target, candidate, element_count, all_combinations);
        }

        for (int i = 0; i < element_count[num]; i++)
        {
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        unordered_map<int, int> element_count;
        vector<int> candidate, combination;
        vector<vector<int>> all_combinations;

        for (int i = 0; i < candidates.size(); i++)
        {
            int num = candidates[i];
            element_count[num]++;
        }

        for (auto it : element_count)
        {
            candidate.push_back(it.first);
        }

        sort(candidate.begin(), candidate.end());

        combinations(0, 0, combination, target, candidate, element_count, all_combinations);
        return all_combinations;
    }
};

int main()
{

    return 0;
}