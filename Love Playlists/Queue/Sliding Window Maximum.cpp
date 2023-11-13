#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> maxi;
        vector<int> ans;
        int to_remove = 0;

        for (int i = 0; i < k; i++)
        {
            while (!maxi.empty() && nums[maxi.back()] < nums[i])
            {
                maxi.pop_back();
            }

            maxi.push_back(i);
        }

        ans.push_back(nums[maxi.front()]);

        for (int i = k; i < n; i++)
        {
            if (maxi.front() == to_remove)
            {
                maxi.pop_front();
            }
            
            while (!maxi.empty() && nums[maxi.back()] < nums[i])
            {
                maxi.pop_back();
            }

            maxi.push_back(i);
            to_remove++;
            ans.push_back(nums[maxi.front()]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}