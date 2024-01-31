#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we just need the index of next greater element & store the difference of index of nge & its index
*/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        int n = temperatures.size();
        vector<int> greaterTemperatures(n, 0);

        for (int ind = 0; ind < n; ind++)
        {
            while (!st.empty() && temperatures[st.top()] < temperatures[ind])
            {
                int index = st.top();
                st.pop();

                int daysToWait = ind - index;
                greaterTemperatures[index] = daysToWait;
            }

            st.push(ind);
        }

        return greaterTemperatures;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}