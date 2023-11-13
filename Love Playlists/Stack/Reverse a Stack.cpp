#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insert_at_bottom(stack<int> &st, int num)
    {
        if (st.empty())
        {
            st.push(num);
            return;
        }

        int n = st.top();
        st.pop();
        insert_at_bottom(st, num);
        st.push(n);
    }

    void Reverse(stack<int> &St)
    {
        if (St.empty())
        {
            return;
        }
        
        int num = St.top();
        St.pop();
        Reverse(St);
        insert_at_bottom(St, num);
    }
};

int main()
{

    return 0;
}