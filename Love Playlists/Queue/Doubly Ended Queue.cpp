#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int n;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        this->n = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if (isFull())
        {
            return false;
        }

        if (isEmpty())
        {
            arr[0] = x;
            front = 0;
            rear = 0;
            return true;
        }

        if (front == 0)
        {
            front = n - 1;
            arr[front] = x;
            return true;
        }

        arr[--front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if (isFull())
        {
            return false;
        }

        if (isEmpty())
        {
            arr[0] = x;
            front = 0;
            rear = 0;
            return true;
        }

        if (rear == n - 1)
        {
            rear = 0;
            arr[rear] = x;
            return true;
        }

        arr[++rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if (isEmpty())
        {
            return -1;
        }

        if (front == rear)
        {
            int value = arr[front];
            front = -1;
            rear = -1;
            return value;
        }

        if (front == n - 1)
        {
            int value = arr[front];
            front = 0;
            return value;
        }

        int value = arr[front++];
        return value;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if (isEmpty())
        {
            return -1;
        }

        if (front == rear)
        {
            int value = arr[front];
            front = -1;
            rear = -1;
            return value;
        }

        if (rear == 0)
        {
            int value = arr[rear];
            rear = n - 1;
            return value;
        }

        int value = arr[rear--];
        return value;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if (front == -1)
        {
            return -1;
        }

        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if (rear == -1)
        {
            return -1;
        }

        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if (front == -1)
        {
            return true;
        }

        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if ((front == 0 && rear == n - 1) || (front == rear + 1))
        {
            return true;
        }

        return false;
    }
};

int main()
{
    return 0;
}