#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    int size = q.size();
    int count = k;
    stack<int> st;

    while (count--)
    {
        int val = q.front();
        q.pop();
        st.push(val);
    }

    while (!st.empty())
    {
        int val = st.top();
        st.pop();
        q.push(val);
    }

    count = 0;

    while (count < size - k)
    {
        int val = q.front();
        q.pop();
        count++;
        q.push(val);
    }

    return q;
}

int main()
{

    return 0;
}