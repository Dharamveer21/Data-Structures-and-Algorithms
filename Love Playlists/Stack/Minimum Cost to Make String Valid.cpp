#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
    if (str.size() & 1)
    {
        return -1;
    }

    int mini_cost = 0;
    stack<int> st;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (ch == '{')
        {
            st.push(ch);
        }

        else
        {
            if (st.empty())
            {
                mini_cost++;
                st.push('(');
                continue;
            }

            st.pop();
        }
    }

    mini_cost += (st.size() >> 1);
    return mini_cost;
}

int main()
{

    return 0;
}