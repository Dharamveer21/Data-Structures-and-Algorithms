#include <bits/stdc++.h>
using namespace std;

// sorting , as the to minimise the sum , we need to add most large value with least value
// so first half was added to second half in reverse order -- like 1st with last , 2nd with second last

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int n = nums.size();
        int min_max_pair = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n / 2; i++)
        {
            int first = nums[i];
            int second = nums[n - i - 1];
            int pair_sum = first + second;
            min_max_pair = max(pair_sum, min_max_pair);
        }

        return min_max_pair;
    }
};

int main()
{

    return 0;
}