#include <bits/stdc++.h>
using namespace std;

// Stack & Dynamic Programming
class Solution
{
protected:
    vector<int> nextSmallerElement(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        vector<int> nextSmaller(n, n);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                nextSmaller[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        return nextSmaller;
    }

    vector<int> prevSmallerElement(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        vector<int> prevSmaller(n, -1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                prevSmaller[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        return prevSmaller;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = -1;
        int n = heights.size();

        vector<int> nextSmaller = nextSmallerElement(heights);
        vector<int> prevSmaller = prevSmallerElement(heights);

        for (int i = 0; i < n; i++)
        {
            int length = heights[i];
            int breadth = (nextSmaller[i] - prevSmaller[i] - 1);

            int area = length * breadth;
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int maxArea = -1;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> histogram(cols, 0);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int height = matrix[i][j] - '0';

                if (height == 0)
                    histogram[j] = 0;

                else
                    histogram[j] += 1;
            }

            int area = largestRectangleArea(histogram);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}