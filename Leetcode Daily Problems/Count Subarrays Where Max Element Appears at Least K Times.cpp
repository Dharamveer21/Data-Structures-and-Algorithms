#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- We can apply sliding window in this problem , here we will just check if the curr window is valid
or not , in each iteration we just add a element from right side in the array and if the element is equal to max
element we update countMax , now after this we check if the current window is valid or not , if the current
window is a valid window we add the subarrays starting at leftPointer and ending at right pointer or greater
than it . We run a while loop to update the left pointer until the window remains valid we change the starting
index of the subarrays and add their count . While updating the left we also decrease the countMax when needed .

Approach 2 -- We can solve this problem by storing the indexes of the max element and whenever we got countMax
is equal to the maxElement we find the last occurrence of maxElement under which the countMax is equal to k
and we add the subarrays ending at the currIndex and starting before or last occurrence of maxElement index .
*/

// Approach 1
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size(), leftPointer = 0, rightPointer = 0;
        int maxElement = *max_element(nums.begin(), nums.end());
        long long countSubarraysWithMaxElement = 0, countMax = 0;

        while (rightPointer < n)
        {
            int num = nums[rightPointer++];
            countMax = countMax + ((num == maxElement) ? 1 : 0);

            while (countMax >= k)
            {
                long long subarraysWithMaxElement = n - rightPointer + 1;
                countSubarraysWithMaxElement += subarraysWithMaxElement;

                int leftMostElement = nums[leftPointer++];
                countMax = countMax - ((leftMostElement == maxElement) ? 1 : 0);
            }
        }

        return countSubarraysWithMaxElement;
    }
};

// TC : O(N)
// SC : O(1)

// Approach 2
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        vector<int> indexOfMaxElement;
        int maxElement = *max_element(nums.begin(), nums.end());
        long long n = nums.size(), countSubarraysWithMaxElement = 0;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];

            if (num == maxElement)
                indexOfMaxElement.push_back(ind);

            int countOfMaxElements = indexOfMaxElement.size();
            int indexOfLastStartingIndexOfSubarray = countOfMaxElements - k;
            int lastStartingIndexOfSubarray = ((indexOfLastStartingIndexOfSubarray < 0) ? -1 : indexOfMaxElement[indexOfLastStartingIndexOfSubarray]);

            int countOfSubarrayEndingAtNum = lastStartingIndexOfSubarray + 1;
            countSubarraysWithMaxElement = countSubarraysWithMaxElement + countOfSubarrayEndingAtNum;
        }

        return countSubarraysWithMaxElement;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}