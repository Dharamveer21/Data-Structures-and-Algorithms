#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Pick any pivot element & place it at its correct place
put all elements less than it on its left side & all elements greater than it on right side
now run the recursive function on leftArr & also on rightArr
*/

class Solution
{
public:
    int pivotPartition(int start, int end, vector<int> &nums)
    {
        int pivot = nums[start];
        int startInd = start;
        int endInd = end;

        while (startInd <= endInd)
        {
            if (nums[startInd] <= pivot)
            {
                startInd++;
                continue;
            }
             
            if (nums[endInd] > pivot)
            {
                endInd--;
                continue;
            }

            swap(nums[startInd], nums[endInd]);
        }
        
        swap(nums[start], nums[endInd]);
        return endInd;
    }

    void quickSort(int start, int end, vector<int> &nums)
    {
        if (start >= end)
        {
            return;
        }

        int partInd = pivotPartition(start, end, nums);
        quickSort(start, partInd - 1, nums);
        quickSort(partInd + 1, end, nums);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        quickSort(0, n - 1, nums);

        return nums;
    }
};

// TC : O(N * log N) , in worst case it becomes O(n^2) because when array is sorted & for each element we traverse whole array
// SC : O(log(N))

int main()
{

    return 0;
}