#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> nex_small_ele(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            nex_small_ele[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    while (!st.empty())
    {
        nex_small_ele[st.top()] = -1;
        st.pop();
    }

    return nex_small_ele;
}

int main()
{

    return 0;
}