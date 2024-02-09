#include <bits/stdc++.h>
using namespace std;

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