#include <bits/stdc++.h>
using namespace std;

class Solution
{
protected:
    void heapify(int ind, vector<int> &arr)
    {
        int size = arr.size();
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

    void mergeArrays(vector<int> &arr1, vector<int> &arr2, vector<int> &mergedArr)
    {
        int n1 = arr1.size(), n2 = arr2.size();

        for (int ind = 0; ind < n1; ind++)
        {
            int num = arr1[ind];
            mergedArr.push_back(num);
        }

        for (int ind = 0; ind < n2; ind++)
        {
            int num = arr2[ind];
            mergedArr.push_back(num);
        }
    }

public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        vector<int> mergedHeap;
        mergeArrays(a, b, mergedHeap);

        int size = mergedHeap.size();
        int nonLeafNodes = size / 2;
        
        for (int ind = nonLeafNodes - 1; ind >= 0; ind--)
        {
            heapify(ind, mergedHeap);
        }

        return mergedHeap;
    }
};

int main()
{

    return 0;
}