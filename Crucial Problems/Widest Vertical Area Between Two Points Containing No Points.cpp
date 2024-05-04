#include <bits/stdc++.h>
using namespace std;

/*
Approach -- the vertical width is equal to difference in x coordinates of the given points
so sort the array according to x coordinates and find the max difference
*/

class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        int n = points.size();
        int maxWidth = 0;
        sort(points.begin(), points.end());

        for (int ind = 0; ind < n - 1; ind++)
        {
            int currX = points[ind][0];
            int nextX = points[ind + 1][0];

            int width = nextX - currX;
            maxWidth = max(width, maxWidth);
        }

        return maxWidth;
    }
};

// TC : O(N * log(N))
// SC : O(1)

int main()
{

    return 0;
}