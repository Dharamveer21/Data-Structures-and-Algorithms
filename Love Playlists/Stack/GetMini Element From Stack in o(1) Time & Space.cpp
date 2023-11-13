#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
    // Define the data members.
    stack<int> st;
    int mini;
    /*----------------- Public Functions of SpecialStack -----------------*/
public:
    void push(int data)
    {
        // Implement the push() function.
        if (st.empty())
        {
            st.push(data);
            mini = data;
        }

        else
        {
            if (data < mini)
            {
                int val = 2 * data - mini;
                mini = data;
                st.push(val);
            }

            else
            {
                st.push(data);
            }
        }
    }

    int pop()
    {
        // Implement the pop() function.
        if (st.empty())
        {
            return -1;
        }

        int curr = st.top();
        st.pop();

        if (curr < mini)
        {
            int to_pop = mini;
            mini = 2 * mini - curr;
            return to_pop;
        }

        else
        {
            return curr;
        }
    }

    int top()
    {
        // Implement the top() function.
        if (st.empty())
        {
            return -1;
        }

        int curr = st.top();

        if (curr < mini)
        {
            return mini;
        }

        else
        {
            return curr;
        }
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return st.empty();
    }

    int getMin()
    {
        // Implement the getMin() function.
        if (st.empty())
        {
            return -1;
        }

        return mini;
    }
};

int main()
{

    return 0;
}