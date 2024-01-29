#include <bits/stdc++.h>
using namespace std;

/*
Approach -- here we can use brute force way with precompuatation to understand the thought process & finally
the optimised method is also do the same in an optimised manner

Let us store the prefix sum of array in a sumArr . Now we can consider each index as start & end to generate
all substrings . when we reach any index we consider all substrings ending at that index & check with all
possible starting points which array have the sum equal to target , store the count .

number of subarrays having sum k ending at index ind is = count(sum{start,ind} == k) , where 0 <= start <= (ind)

Now to optimise this approach , we can store the prefix sum in a map , while adding the prefix sum we can
simuntaneously consider current index as ending index & check if there is any sum still in the map having sum
equal to (cummSum - k) if it exists increase the countofSubarr & add cummSum in the map . prefixSum is cummSum

In the map we add {sum,number of times it occurrs} to calculate number of subarrays , map has already {0,1}
because if we consider only 1 element == k we should put a {0} sum in the map .
*/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), target = k;
        unordered_map<int, int> prefixSum;

        prefixSum.insert({0, 1});
        int subarrCount = 0, cummSum = 0;

        for (int ind = 0; ind < n; ind++)
        {
            int currVal = nums[ind];
            cummSum = cummSum + currVal;
            int reqSum = cummSum - target;

            if (prefixSum.find(reqSum) != prefixSum.end())
            {
                int reqSumCount = prefixSum.at(reqSum);
                subarrCount += reqSumCount;
            }

            prefixSum[cummSum] += 1;
        }

        return subarrCount;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}