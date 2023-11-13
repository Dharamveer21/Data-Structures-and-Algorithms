#include <bits/stdc++.h>
using namespace std;

/*
using binary_search
here we generate all increasing subsequences in a hyper space

if next element is smaller than the existing subsequence -- it will not increase the seq length but just replce a value
else it will increase the length

this method can't be use to print lis
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> subseq;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            auto it = lower_bound(subseq.begin(), subseq.end(), num);

            if (it == subseq.end())
            {
                subseq.push_back(num);
            }

            else
            {
                int ind = it - subseq.begin();
                subseq[ind] = num;
            }
        }

        return subseq.size();
    }
};

int main()
{

    return 0;
}