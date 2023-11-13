#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;

        for (int i = 0; s[i] != '\0'; i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                st.push(i);
            }

            if (ch == ')')
            {
                if (st.empty())
                {
                    s[i] = '*';
                    continue;
                }

                st.pop();
            }
        }

        while (!st.empty())
        {
            int index = st.top();
            s[index] = '*';
            st.pop();
        }

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '*')
            {
                s.erase(s.begin() + i);
                i--;
            }
        }

        //s.erase(remove(s.begin(), s.end(), '*'), s.end());

        return s;
    }
};

int main()
{

    return 0;
}