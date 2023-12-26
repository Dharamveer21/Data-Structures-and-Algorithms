#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Divide & Conquer Technique
A recursive function as merge sort which will first sort leftHalf & then sort RightHalf
Finally two sorted arrays to form final sorted array
*/

class Solution
{
public:
    void merge(int startLeft, int endLeft, int startRight, int endRight, vector<int> &nums)
    {
        static const int INF = INT_MAX;
        vector<int> leftArr, rightArr;
        int leftPtr = 0, rightPtr = 0;

        for (int ind = startLeft; ind <= endLeft; ind++)
        {
            leftArr.push_back(nums[ind]);
        }

        for (int ind = startRight; ind <= endRight; ind++)
        {
            rightArr.push_back(nums[ind]);
        }

        leftArr.push_back(INF);
        rightArr.push_back(INF);

        for (int ind = startLeft; ind <= endRight; ind++)
        {
            int leftValue = leftArr[leftPtr];
            int rightValue = rightArr[rightPtr];

            if (leftValue <= rightValue)
            {
                nums[ind] = leftValue;
                leftPtr++;
            }

            else
            {
                nums[ind] = rightValue;
                rightPtr++;
            }
        }
    }

    void mergeSort(int start, int end, vector<int> &nums)
    {
        if (start == end)
        {
            return;
        }

        int mid = ((start + end) >> 1);
        mergeSort(start, mid, nums);
        mergeSort(mid + 1, end, nums);
        merge(start, mid, mid + 1, end, nums);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        mergeSort(0, n - 1, nums);

        return nums;
    }
};

// TC : O(N * log(N))
// SC : O(N + log(N)) = O(N)

int main()
{

    return 0;
}