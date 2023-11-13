#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to delete middle element of a stack using recursion
    void deleteMiddle(stack<int> &s, int &size, int count)
    {
        if (count == size / 2)
        {
            s.pop();
            return;
        }
        
        int num = s.top();
        s.pop();
        deleteMiddle(s, size, count + 1);
        s.push(num);
    }
    
    void deleteMid(stack<int> &s, int sizeofStack)
    {
        int count = 0, size = sizeofStack;
        deleteMiddle(s, size, count);
    }

    // Function to delete middle element of a stack using a new stack approach
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        int to_remove = sizeOfStack / 2;
        stack<int> st;

        while (to_remove--)
        {
            st.push(s.top());
            s.pop();
        }

        s.pop();

        to_remove = sizeOfStack / 2;

        while (to_remove--)
        {
            s.push(st.top());
            st.pop();
        }
    }
};

int main()
{

    return 0;
}