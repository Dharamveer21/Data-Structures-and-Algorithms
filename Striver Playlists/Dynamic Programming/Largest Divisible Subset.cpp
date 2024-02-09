#include <bits/stdc++.h>
using namespace std;

/*
sort the array & if any number is divisible by prev then it will also be divisible by all its previous of the 
subset convert subset to subsequence problem
*/

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int hash_arr[n], long_div[n];
        vector<int> ans;
        int index = -1;
        int max_sub = 1;

        for (int i = 0; i < n; i++)
        {
            int ind = -1, max_len = 0;

            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (long_div[j] >= max_len)
                    {
                        max_len = long_div[j];
                        ind = j;
                    }
                }
            }

            if (ind == -1)
            {
                hash_arr[i] = -1;
                long_div[i] = 1;

                if (max_sub <= long_div[i])
                {
                    max_sub = long_div[i];
                    index = i;
                }
            }
            
            else
            {
                hash_arr[i] = ind;
                long_div[i] = max_len + 1;

                if (max_sub <= long_div[i])
                {
                    max_sub = long_div[i];
                    index = i;
                }
            }
        }

        while (index != -1)
        {
            ans.push_back(nums[index]);
            index = hash_arr[index];
        }

        return ans;
    }
};

int main()
{

    return 0;
}