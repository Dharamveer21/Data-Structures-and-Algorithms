#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // using stack
    bool isvalid(unordered_map<char, int> &val, string &s)
    {
        stack<int> st;
        int i = 0;

        while (s[i] != '\0')
        {
            char ch = s[i];

            if (val[ch] < 0)
            {
                st.push(val[ch]);
            }

            else
            {
                if (val[ch] + st.top() != 0)
                {
                    return false;
                }

                st.pop();
            }

            i++;
        }

        return (st.empty() == 1);
    }

    bool isValid(string s)
    {
        unordered_map<char, int> val;

        val['('] = -1;
        val[')'] = 1;
        val['{'] = -2;
        val['}'] = 2;
        val['['] = -3;
        val[']'] = 3;

        return (isvalid(val, s));
    }
};

int main()
{

    return 0;
}