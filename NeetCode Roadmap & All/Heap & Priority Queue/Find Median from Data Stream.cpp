#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we can use a simple idea that the elements on left side of median are smaller than median & elements
on the right side of median are greater than it . We can use two heaps -- 1 maxHeap for leftSide elements , here
we use maxHeap because we need maximum element among leftSide elements to find median & 1 minHeap for rightSide
elements , here we use minHeap because we need minimum element from rightSide elements to find median .

We will always make the two heaps either equal or maxHeap having exactly 1 more element than minHeap .
So, in case of oddNumber of elements the top of maxHeap is answer else in case of even number of elements
The mean of top elements of maxHeap & minHeap is the median . Actually its like maintianing leftHalf of array
in maxHeap & rightHalf in the minHeap . Where leftSide.size >= rightSide.size .

We always compare the new element with top of maxHeap , So we need one additional Function -- balance heaps .
In this function we always maintain maxHeap.size == minHeap.size + 1 or maxHeap.size == minHeap.size
*/

class MedianFinder
{
private:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

protected:
    bool isOddNumberElements()
    {
        int leftSize = leftMaxHeap.size();
        int rightSize = rightMinHeap.size();

        return (leftSize > rightSize);
    }

    void balanceHeaps()
    {
        int leftSize = leftMaxHeap.size();
        int rightSize = rightMinHeap.size();

        if (leftSize > rightSize + 1)
        {
            int num = leftMaxHeap.top();
            leftMaxHeap.pop();

            rightMinHeap.push(num);
        }

        else if (rightSize > leftSize)
        {
            int num = rightMinHeap.top();
            rightMinHeap.pop();

            leftMaxHeap.push(num);
        }
    }

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (leftMaxHeap.empty())
        {
            leftMaxHeap.push(num);
            return;
        }

        int val = leftMaxHeap.top();
        int isTrue = (val <= num);

        switch (isTrue)
        {
        case 0:
            leftMaxHeap.push(num);
            break;

        case 1:
            rightMinHeap.push(num);
            break;
        }

        balanceHeaps();
    }

    double findMedian()
    {
        double median = 0;
        bool oddElements = isOddNumberElements();

        if (oddElements)
        {
            median = (double)leftMaxHeap.top();
            return median;
        }

        double left = (double)leftMaxHeap.top();
        double right = (double)rightMinHeap.top();

        median = (left + right) / 2;
        return median;
    }
};

// Number of elements in the stream = N
// TC : O(N * log(N))
// SC : O(N)

int main()
{

    return 0;
}