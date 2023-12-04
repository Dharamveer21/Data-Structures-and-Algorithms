#include <bits/stdc++.h>
using namespace std;

/*
Approach -- to find minimum time between any two points
we first cover the minimum of x-distance or y-distance with root-2 distance
while the remaining distance with straight motion each block in each sec
hence total time is equal to maxDistance of x-distance & y-distance
*/

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int minTime = 0;
        int currX = points[0][0];
        int currY = points[0][1];

        for (int ind = 1; ind < points.size(); ind++)
        {
            int nextX = points[ind][0];
            int nextY = points[ind][1];

            int distX = abs(nextX - currX);
            int distY = abs(nextY - currY);

            int time = max(distX, distY);
            minTime += time;

            currX = nextX;
            currY = nextY;
        }

        return minTime;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}