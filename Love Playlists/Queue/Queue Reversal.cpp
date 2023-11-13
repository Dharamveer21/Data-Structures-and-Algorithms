#include <bits/stdc++.h>
using namespace std;

void to_rev(queue<int> &q)
{
    if (q.size() == 0)
    {
        return;
    }

    int val = q.front();
    q.pop();
    to_rev(q);
    q.push(val);
}

queue<int> rev(queue<int> q)
{
    // add code here.
    to_rev(q);
    return q;
}

int main()
{

    return 0;
}