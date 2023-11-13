#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // appraoch 1 we calculate max area for each element seprately
    // which basically means upto which position it is minimum index
    // which means the next smaller element of it on both right and left side
    // it is O(n2) approach as for each element we have to calculate left and right next smaller for which we have to traverse whole array
    // we can optimise it by calculating each and every case before by using stack in O(n) and can use it directly in solution in O(1) time
    // TC for optimised approach is O(n)

    vector<int> next_smaller_element(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> next_smaller(n, n);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                next_smaller[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        return next_smaller;
    }

    vector<int> prev_smaller_element(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> prev_smaller(n, -1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                prev_smaller[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        return prev_smaller;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int max_area = -1;

        vector<int> next_smaller = next_smaller_element(heights);
        vector<int> prev_smaller = prev_smaller_element(heights);

        for (int i = 0; i < n; i++)
        {
            int length = heights[i];
            int breadth = (next_smaller[i] - prev_smaller[i] - 1);

            int area = length * breadth;
            max_area = max(area, max_area);
        }

        return max_area;
    }
};

int main()
{

    return 0;
}