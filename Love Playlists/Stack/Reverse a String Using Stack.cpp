#include <bits/stdc++.h>
using namespace std;

char *reverse(char *S, int len)
{
    stack<char> st;
    int ind = 0;

    for (int i = 0; i < len; i++)
    {
        st.push(S[i]);
    }

    while (!st.empty())
    {
        S[ind] = st.top();
        ind++;
        st.pop();
    }

    return S;
}

int main()
{

    return 0;
}