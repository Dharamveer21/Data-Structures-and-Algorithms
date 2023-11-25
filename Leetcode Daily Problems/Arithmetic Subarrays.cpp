#include <bits/stdc++.h>
using namespace std;

/*
Approach -- store the array from l[i] to r[i]
sort it & check airthematic by traversing
*/

class Solution
{
public:
    bool checkAirthematic(vector<int> &arr)
    {
        if (arr.size() == 2)
        {
            return true;
        }

        int diff = arr[1] - arr[0];

        for (int i = 2; i < arr.size(); i++)
        {
            int num = arr[i - 1] + diff;

            if (num != arr[i])
            {
                return false;
            }
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int m = l.size();
        vector<int> query;
        vector<bool> Arithmetics(m);

        for (int ind = 0; ind < m; ind++)
        {
            query.clear();

            for (int i = l[ind]; i <= r[ind]; i++)
            {
                query.push_back(nums[i]);
            }

            sort(query.begin(), query.end());
            bool isArithmetic = checkAirthematic(query);
            Arithmetics[ind] = isArithmetic;
        }

        return Arithmetics;
    }
};

// TC : O(N * (N * log(N) + N)) = O(N^2 * log(N))
// SC : O(N + N) = O(N)

int main()
{

    return 0;
}