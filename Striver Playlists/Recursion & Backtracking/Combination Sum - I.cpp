#include <bits/stdc++.h>
using namespace std;

// take not take method
class Solution
{
public:
    void combinations(int ind, int target, vector<int> &combination, vector<int> &candidates, vector<vector<int>> &allcombinations)
    {
        if (target == 0)
        {
            allcombinations.push_back(combination);
            return;
        }

        if (target < 0 || ind == candidates.size())
        {
            return;
        }

        int num = candidates[ind];

        // we include ind again
        combination.push_back(num);
        combinations(ind, target - num, combination, candidates, allcombinations);
        combination.pop_back();

        // we don't include this one
        combinations(ind + 1, target, combination, candidates, allcombinations);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> combination;
        vector<vector<int>> allcombinations;
        combinations(0, target, combination, candidates, allcombinations);
        return allcombinations;
    }
};

// every time has full array to select but in this case there are repeating cases like 1 2 3 and 2 3 1
class Solution
{
public:
    void combinations(int target, vector<int> &combination, vector<int> &candidates, vector<vector<int>> &allcombinations)
    {
        if (target < 0)
        {
            return;
        }

        if (target == 0)
        {
            allcombinations.push_back(combination);
            return;
        }

        for (int i = 0; i < candidates.size(); i++)
        {
            int num = candidates[i];

            combination.push_back(num);
            combinations(target - num, combination, candidates, allcombinations);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> combination;
        vector<vector<int>> allcombinations;
        combinations(target, combination, candidates, allcombinations);
        return allcombinations;
    }
};

// first finish all possibilities of a element
class Solution
{
public:
    void combinations(int ind, int target, vector<int> &combination, vector<int> &candidates, vector<vector<int>> &allcombinations)
    {
        if (target == 0)
        {
            allcombinations.push_back(combination);
            return;
        }

        if (ind == candidates.size() || target < 0)
        {
            return;
        }

        int sum = 0;
        int num = candidates[ind];
        combinations(ind + 1, target, combination, candidates, allcombinations);

        while (sum + num <= target)
        {
            sum += num;
            combination.push_back(num);
            combinations(ind + 1, target - sum, combination, candidates, allcombinations);
        }

        while (combination.size() != 0 && num == combination[combination.size() - 1])
        {
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> combination;
        vector<vector<int>> allcombinations;
        combinations(0, target, combination, candidates, allcombinations);
        return allcombinations;
    }
};

int main()
{

    return 0;
}