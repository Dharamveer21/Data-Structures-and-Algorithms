#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        // Implement the Constructor
        size = 100001;
        int *arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if(qfront == rear)
        {
            return true;
        }

        return false;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }

        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (qfront == rear)
        {
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;

        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }

        return ans;
    }

    int front()
    {
        // Implement the front() function
        if(qfront == rear)
        {
            return -1;
        }

        return arr[qfront];
    }
};

int main()
{
    queue<int> q;

    q.push(11);
    q.push(13);
    q.push(14);

    cout << q.size() << endl;
    q.pop();
    cout << q.size() << endl;
    cout << q.empty() << endl;
    cout << q.front() << endl;

    return 0;
}