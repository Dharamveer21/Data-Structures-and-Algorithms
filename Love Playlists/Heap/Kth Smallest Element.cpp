#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq;

        // push first k elements in heap
        for (int ind = l; ind < k + l; ind++)
        {
            int num = arr[ind];
            pq.push(num);
        }

        // maintain the top element of heap as minimum as possible
        for (int ind = k + l; ind <= r; ind++)
        {
            int num = arr[ind];
            int maxheapTop = pq.top();

            if (maxheapTop > num)
            {
                pq.pop();
                pq.push(num);
            }
        }

        int kthSmall = pq.top();
        return kthSmall;
    }
};

// TC : O(N * log(K))
// SC : O(K)

int main()
{

    return 0;
}