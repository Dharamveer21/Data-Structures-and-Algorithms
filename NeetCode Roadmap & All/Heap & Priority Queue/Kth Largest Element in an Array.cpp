#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we can use a mean heap , we put first k elements in the heap and its top will be minimum
now when we traverse the next elements upto last . We first check if the element is greater than the minimum
value we replace the value of minimum with this element & repeat this with other elements

Finally the heap will contain the largest "K" elements & the topmost element is Kth largest element
*/

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size(), KthLargestElement = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int ind = 0; ind < k; ind++)
        {
            int num = nums[ind];
            minHeap.push(num);
        }

        for (int ind = k; ind < n; ind++)
        {
            int num = nums[ind];
            int topElement = minHeap.top();

            if (topElement < num)
            {
                minHeap.pop();
                minHeap.push(num);
            }
        }

        KthLargestElement = minHeap.top();
        return KthLargestElement;
    }
};

// TC : O(N * log(K))
// SC : O(K)

int main()
{

    return 0;
}