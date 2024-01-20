#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here we use the concept of nextSmaller & prevSmaller Element for a particular element of stack
Consider each element as the minimum element & check in how many arrays it will behave as min element
It will remain minimum in range of its prevSmaller & it nextSmaller . Then calculate the number of subarrays
in its range containing it will be using the formula in the function . Multiply the element with the subarray
& calculate its sum , similarly for all elements .

If we have equal elements then we can have reapeating subarrays -- so use any one prevSmaller or nextSmaller
as consider the equal element smaller than it . It will take its count only 1 time .
*/

class Solution
{
private:
    static const int M = 1e9 + 7;

protected:
    vector<int> prevSmaller(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            while (!st.empty() && arr[st.top()] >= arr[ind])
            {
                int index = st.top();
                pse[index] = ind;
                st.pop();
            }

            st.push(ind);
        }

        return pse;
    }

    vector<int> nextSmaller(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;

        for (int ind = 0; ind < n; ind++)
        {
            while (!st.empty() && arr[st.top()] > arr[ind])
            {
                int index = st.top();
                nse[index] = ind;
                st.pop();
            }

            st.push(ind);
        }

        return nse;
    }

    int subarrayCount(int start, int end, int ind)
    {
        int startPoints = (ind - start + 1);
        int endPoints = (end - ind + 1);

        int cnt = (startPoints * 1LL * endPoints) % M;
        return cnt;
    }

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size(), subarrMinSum = 0;
        vector<int> prev = prevSmaller(arr);
        vector<int> next = nextSmaller(arr);

        for (int ind = 0; ind < n; ind++)
        {
            int num = arr[ind];
            int start = prev[ind] + 1;
            int end = next[ind] - 1;

            int cntSubarr = subarrayCount(start, end, ind);
            int subarrSum = (cntSubarr * 1LL * num) % M;

            subarrMinSum = (subarrMinSum + 0LL + subarrSum) % M;
        }

        return subarrMinSum;
    }
};

// TC : O(N + N + N) = O(N)
// SC : O(N + N + N) = O(N)

int main()
{

    return 0;
}