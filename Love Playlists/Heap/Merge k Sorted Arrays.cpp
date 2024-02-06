#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> arrPointers(K, 0), mergedArray;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // insert first k elements
        for (int ind = 0; ind < K; ind++)
        {
            int index = arrPointers[ind];
            int val = arr[ind][index];

            minHeap.push({val, ind});
        }

        while (!minHeap.empty())
        {
            pair<int, int> numPointer = minHeap.top();
            minHeap.pop();

            int val = numPointer.first;
            int pointer = numPointer.second;

            int index = arrPointers[pointer];
            int size = arr[pointer].size();

            if ((++index) < size)
            {
                int num = arr[pointer][index];
                minHeap.push({num, pointer});
                arrPointers[pointer] = index;
            }
              
            mergedArray.push_back(val);
        }

        return mergedArray;
    }
};

int main()
{

    return 0;
}