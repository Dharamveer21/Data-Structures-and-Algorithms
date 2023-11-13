#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
class NQueue
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;

public:
    // Initialize your data structure.
    NQueue(int n, int s)
    {
        // Write your code here.
        front = new int[n];
        rear = new int[n];
        next = new int[s];
        arr = new int[s];

        for (int i = 0; i < n; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < s - 1; i++)
        {

            next[i] = i + 1;
        }

        next[s - 1] = -1;
        freespot = 0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }

        // Write your code here.

        int index = freespot;
        freespot = next[index];

        if (rear[m - 1] == -1)
        {
            // first element is pushed
            arr[index] = x;
            front[m - 1] = index;
            rear[m - 1] = index;
            next[index] = -1;
        }

        else
        {
            arr[index] = x;
            next[rear[m - 1]] = index;
            rear[m - 1] = index;
            next[index] = -1;
        }

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m)
    {
        // Write your code here.
        int value = -1;

        if (front[m - 1] == -1)
        {
            return value;
        }

        if (front[m - 1] == rear[m - 1])
        {
            value = arr[front[m - 1]];
            next[front[m - 1]] = freespot;
            freespot = front[m - 1];
            front[m - 1] = -1;
            rear[m - 1] = -1;
        }

        else
        {
            int index = front[m - 1];
            value = arr[index];
            front[m - 1] = next[index];
            next[index] = freespot;
            freespot = index;
        }

        return value;
    }
};

int main()
{

    return 0;
}