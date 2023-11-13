#include <bits/stdc++.h>
using namespace std;

bool check(stack<char> &st)
{
    bool ans = true;

    while (st.top() != '(')
    {
        char ch = st.top();

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            ans = true;
        }

        st.pop();
    }

    st.pop();

    return ans;
}

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if (ch != ')')
        {
            st.push(ch);
        }

        else
        {
            if (check(st))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}