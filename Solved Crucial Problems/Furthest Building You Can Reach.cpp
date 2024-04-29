#include <bits/stdc++.h>
using namespace std;

/*
Approach -- This is a greedy problem , in this problem we can first reach the furthest point using the ladders
only . Now when we move next we first see the gap & put the gap in the minHeap of gaps . Now we will takes out
the smallest gap from the minHeap & replace it with bricks . If the smallest gap is the current one we will move
further by putting bricks otherwise if it was an previously occurred gap . We will put replace its ladder with
bricks & use that ladder to move further . In this way we use bricks for the shortest gaps & ladder for the
largest gaps . This optimal strategy will helps us to reach the furthest point in the ladder .
*/

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size(), furthestPoint = 0;
        int furthestPointWithOnlyLadders = n - 1;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // use all ladders first
        for (int building = 0; building < n - 1; building++)
        {
            int currHeight = heights[building];
            int nextHeight = heights[building + 1];
            int gap = nextHeight - currHeight;

            if (gap <= 0)
            {
                furthestPointWithOnlyLadders = building + 1;
                continue;
            }

            if (ladders == 0)
            {
                furthestPointWithOnlyLadders = building;
                break;
            }

            minHeap.push(gap);
            furthestPointWithOnlyLadders = building + 1;
            ladders--;
        }

        furthestPoint = furthestPointWithOnlyLadders;

        // check the nextGap & compare with prevMinimum gaps to replace ladder with bricks at that gap
        for (int building = furthestPointWithOnlyLadders; building < n - 1; building++)
        {
            int currHeight = heights[building];
            int nextHeight = heights[building + 1];
            int gap = nextHeight - currHeight;

            if (gap <= 0)
            {
                furthestPoint = building + 1;
                continue;
            }

            minHeap.push(gap);

            int shortestGap = minHeap.top();
            minHeap.pop();

            if (bricks < shortestGap)
            {
                furthestPoint = building;
                break;
            }

            bricks -= shortestGap;
            furthestPoint = building + 1;
        }

        return furthestPoint;
    }
};

// L -- number of ladders , N -- number of buildings
// TC : O(N * log(L))
// SC : O(L)

int main()
{

    return 0;
}