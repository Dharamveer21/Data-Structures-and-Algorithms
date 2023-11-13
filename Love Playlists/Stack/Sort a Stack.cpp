#include <bits/stdc++.h>
using namespace std;

void insert_at_right_place(stack<int> &stack, int &element)
{
    if (stack.empty() || stack.top() <= element)
    {
        stack.push(element);
    }

    int num = stack.top();
    stack.pop();
    insert_at_right_place(stack, element);
    stack.push(num);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();
    sortStack(stack);
    insert_at_right_place(stack, num);
}

int main()
{

    return 0;
}