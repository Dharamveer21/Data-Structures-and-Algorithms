#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int mini_add = 0;
        stack<char> st;

        for (int i = 0; s[i] != '\0'; i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                st.push(ch);
            }

            else
            {
                if (st.empty())
                {
                    mini_add++;
                    continue;
                }

                st.pop();
            }
        }
        
        mini_add += st.size();

        return mini_add;
    }
};

int main()
{

    return 0;
}