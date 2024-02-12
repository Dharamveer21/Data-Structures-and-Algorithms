#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a DP Problem , where the function f will return us the largest divisible subset upto index
"ind" . We must sort the array because when we have a sorted array & we have a largest divisible subset of upto
any index "ind" . We can easily check if our new element can be added to that subset or not by just dividing the
last element of the subset . In this way we can find the maximum subset .

In these types of problems we should use tabulation method as it is more simple & less space consuming & faster
than memoisation recursion .

Also we will maintain an hash array to keep the index of the previous largest subset we encountered
*/

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> largestDivisibleSubset;

        int *divisibleSubsetLen = new int[n];
        int *prevDivisibleIndex = new int[n];

        for (int ind = 0; ind < n; ind++)
        {
            int maxDivLen = 1, prevDivIndex = -1;

            for (int prevInd = 0; prevInd < ind; prevInd++)
            {
                int currNum = nums[ind];
                int prevNum = nums[prevInd];

                if (currNum % prevNum == 0)
                {
                    int len = divisibleSubsetLen[prevInd];

                    maxDivLen = max(maxDivLen, len + 1);
                    prevDivIndex = (maxDivLen == len + 1) ? prevInd : prevDivIndex;
                }
            }

            divisibleSubsetLen[ind] = maxDivLen;
            prevDivisibleIndex[ind] = prevDivIndex;
        }

        int indexLDS = max_element(divisibleSubsetLen, divisibleSubsetLen + n) - divisibleSubsetLen;

        while (indexLDS != -1)
        {
            int num = nums[indexLDS];

            largestDivisibleSubset.push_back(num);
            indexLDS = prevDivisibleIndex[indexLDS];
        }

        delete[] divisibleSubsetLen;
        delete[] prevDivisibleIndex;
        return largestDivisibleSubset;
    }
};

// TC : O(N ^ 2)
// SC : O(N)

int main()
{

    return 0;
}