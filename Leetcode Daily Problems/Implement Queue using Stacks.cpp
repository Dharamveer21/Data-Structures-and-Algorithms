#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We need two stack one for input & other for output .We also use a peek element variable

1. push operation -- we push the element into the input stack
2. pop operation -- we push the whole input stack into the output stack & remove top element of output stack
3. peek operation -- if output stack is empty we return value of peek else we return top element of output stack
4. empty operation -- we check if both of the stacks are empty or not
*/

class MyQueue
{
private:
    int peekElement;
    stack<int> input, output;

protected:
    void transfer()
    {
        while (!this->input.empty())
        {
            int element = this->input.top();
            this->input.pop();

            this->output.push(element);
        }
    }

public:
    MyQueue()
    {
        peekElement = -1;
    }

    void push(int x)
    {
        if (this->input.empty())
        {
            peekElement = x;
        }

        this->input.push(x);
    }

    int pop()
    {
        if (this->output.empty())
        {
            transfer();
        }

        int front = this->output.top();
        this->output.pop();

        return front;
    }

    int peek()
    {
        if (this->output.empty())
        {
            return this->peekElement;
        }

        int front = this->output.top();
        return front;
    }

    bool empty()
    {
        return (input.empty() && output.empty());
    }
};

// amotised means performing n operations will take overall O(n) time even if one of those operations may take longer.
// TC : O(1) -- it is amortized O(1)
// SC : O(2 * N + 1) = O(N)

int main()
{

    return 0;
}