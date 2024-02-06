#include <bits/stdc++.h>
using namespace std;

/*
Approach -- create a maxHeap from the given array using the heapify function from index = n/2 - 1 to 0 .
then the heap will contain maxElement on its top . We swap it with last element & decrease the size of heap
Then again we apply heapify to get maxElement on top in newHeap . Again repeat the above steps .
*/

class Solution
{
protected:
    void heapify(int ind, int size, vector<int> &arr)
    {
        int largest = ind , index = ind;

        while (index < size)
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            if (leftChild < size && arr[leftChild] > arr[index])
            {
                largest = leftChild;
            }
            
            if (rightChild < size && arr[rightChild] > arr[largest])
            {
                largest = rightChild;
            }

            if (largest != index)
            {
                swap(arr[largest], arr[index]);
                index = largest;
                continue;
            }

            return;
        }
    }

    void heapSort(int size, vector<int> &arr)
    {
        for (int ind = size - 1; ind >= 0; ind--)
        {
            swap(arr[0], arr[ind]);
            heapify(0, ind, arr);
        }
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        int nonLeafNodes = n / 2;

        // build the heap
        for (int ind = nonLeafNodes - 1; ind >= 0; ind--)
        {
            heapify(ind, n, nums);
        }

        // apply heapSort
        heapSort(n, nums);
        return nums;
    }
};

// TC : O(N * log(N))
// SC : O(1)

int main()
{

    return 0;
}