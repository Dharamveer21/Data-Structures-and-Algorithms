#include <bits/stdc++.h>
using namespace std;

/*
Heap is a complete binary tree where in maxHeap the node is always greater than its children and in case of
minHeap root is always less than its children

We implement it using a array -- we start with a 1 based indexing , if anynode is at index 'i' its children will be at 2*i , 2*i + 1 indexes

and if any child is at index i -- its parent will be at i/2
*/

class heap
{
private:
    vector<int> arr;
    int size;

public:
    heap()
    {
        arr.push_back(-1);
        this->size = 0;
    }

    void insert(int val)
    {
        arr.push_back(val);

        size = size + 1;
        int index = size;

        while (index > 1)
        {
            int curr = index;
            int parent = index / 2;

            if (arr[parent] < arr[curr])
            {
                swap(arr[index / 2], arr[index]);
                index = parent;
                continue;
            }
            
            return;
        }
    }

    void deletion()
    {
        // Here we only delete the top node
        if (size == 0)
        {
            cout << "Heap is Empty";
            return;
        }

        arr[1] = arr[size];
        arr.pop_back();
        size--;

        // take root node to its correct position
        int index = 1;

        while (true)
        {
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;

            int leftValue = INT_MIN;
            int rightValue = INT_MIN;

            if (leftChild <= size)
            {
                leftValue = arr[leftChild];
            }
            
            if (rightChild <= size)
            {
                rightValue = arr[rightChild];
            }

            if (leftValue >= rightValue && arr[index] < leftValue)
            {
                swap(arr[index], arr[leftChild]);
                index = leftChild;
                continue;
            }

            else if (leftValue < rightValue && arr[index] < rightValue)
            {
                swap(arr[index], arr[rightChild]);
                index = rightChild;
                continue;
            }

            return;
        }
    }

    void printHeap()
    {
        for (int ind = 1; ind <= size; ind++)
        {
            cout << arr[ind] << " ";
        }

        cout << endl;
    }
};

// There are always n/2 non-leaf nodes in complete binary tree

void heapify(int ind, int size, vector<int> &arr)
{
    int largest = ind;
    int leftChild = 2 * ind;
    int rightChild = 2 * ind + 1;

    if (leftChild <= size && arr[leftChild] > arr[ind])
    {
        largest = max(largest, leftChild);
    }

    if (rightChild <= size && arr[rightChild] > arr[ind])
    {
        largest = max(largest, rightChild);
    }

    if (largest != ind)
    {
        swap(arr[largest], arr[ind]);
        heapify(largest, size, arr);
    }
}

int main()
{
    heap *obj = new heap;

    obj->insert(50);
    obj->insert(55);
    obj->insert(53);
    obj->insert(52);
    obj->insert(54);

    obj->printHeap();
    obj->deletion();
    obj->printHeap();

    // Heapify
    vector<int> arr = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    int nonLeftNodes = n / 2;

    for (int ind = nonLeftNodes; ind > 0; ind--)
    {
        heapify(ind, n, arr);
    }

    for (int ind = 1; ind <= n; ind++)
    {
        cout << arr[ind] << " ";
    }

    cout << endl;

    return 0;
}

/*
TC for insertion is O(log(N))
TC for deletion is O(log(N))
TC for heapify is O(N)
*/