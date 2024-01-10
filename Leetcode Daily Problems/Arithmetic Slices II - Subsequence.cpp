#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a dp problem in this dp the tabulation is way easy then
*/

class Solution
{
protected:
    // memoisation
    int numberOfAp(int ind, long long diff, vector<int> &nums, vector<pair<int, long long>> &numAp)
    {
        int n = nums.size();

        int firstTerm = nums[ind];
        long long nextTerm = firstTerm + 0LL + diff;

        int totalApSequences = 0;

        for (int i = ind + 1; i < n; i++)
        {
            long long num = nums[i];

            if (num == nextTerm)
            {
                totalApSequences += numberOfAp(i, diff, nums, numAp) + 1;
            }
        }

        return totalApSequences;
    }

public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size(), totalApSequences = 0;
        vector<pair<int, long long>> numAp;

        for (int ind1 = 0; ind1 < n; ind1++)
        {
            for (int ind2 = ind1 + 1; ind2 < n; ind2++)
            {
                long long diff = nums[ind2] + 0LL - nums[ind1];
                totalApSequences += numberOfAp(ind2, diff, nums, numAp);
            }
        }

        return totalApSequences;
    }
};

// TC : O()
// SC : O()

int main()
{

    return 0;
}