#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_area = -1;

        vector<int> histogram(cols, 0);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int height = matrix[i][j] - '0';

                if (height == 0)
                {
                    histogram[j] = 0;
                }

                else
                {
                    histogram[j] += 1;
                }
            }

            int area = largestRectangleArea(histogram);
            max_area = max(max_area, area);
        }

        return max_area;
    }
};

int main()
{

    return 0;
}