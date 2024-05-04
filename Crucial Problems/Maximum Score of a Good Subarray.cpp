#include <bits/stdc++.h>
using namespace std;

/*
Approach -- imagine the array as the heights of buildings , then consider each building as the minimum height & find buildings greater
than it on both sides to find the maxArea considering it as minimum
It is like a rectangle with maximum Area , we will use monotonic stack to calculate next smaller element on both side for each element
finally we calculate the maxArea for each rectangle but only consider those one which consists index 'k' element in it
*/

class Solution
{
public:
    void prevSmaller(vector<int> &nums, vector<int> &ans)
    {
        int n = nums.size();
        stack<int> st;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int num = nums[ind];

            while (!st.empty() && nums[st.top()] > num)
            {
                int Elementindex = st.top();
                int smallIndex = ind;

                ans[Elementindex] = smallIndex;
                st.pop();
            }

            st.push(ind);
        }
    }

    void nextSmaller(vector<int> &nums, vector<int> &ans)
    {
        int n = nums.size();
        stack<int> st;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];

            while (!st.empty() && nums[st.top()] > num)
            {
                int Elementindex = st.top();
                int smallIndex = ind;

                ans[Elementindex] = smallIndex;
                st.pop();
            }

            st.push(ind);
        }
    }

    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size(), maxScore = 0;
        vector<int> prevSmallerElement(n, -1);
        vector<int> nextSmallerElement(n, n);

        prevSmaller(nums, prevSmallerElement);
        nextSmaller(nums, nextSmallerElement);

        for (int ind = 0; ind < n; ind++)
        {
            int leftBoundary = prevSmallerElement[ind] + 1;
            int rightBoundary = nextSmallerElement[ind] - 1;

            int height = nums[ind];
            int length = rightBoundary - leftBoundary + 1;

            if (leftBoundary <= k && k <= rightBoundary)
            {
                int score = (height * length);
                maxScore = max(maxScore, score);
            }
        }

        return maxScore;
    }
};

// TC : O(N + N + N) = O(N)
// SC : O (N + N) = O(N)

int main()
{

    return 0;
}