#include <bits/stdc++.h>
using namespace std;

// Approach 1 -- Two Pointers
class Solution
{
    void getLeftMaxArray(int leftMaxArray[], vector<int> &heights)
    {
        int leftMaxHeight = 0, countOfBars = heights.size();

        for (int bar = 1; bar < countOfBars; bar++)
        {
            int prevBarHeight = heights[bar - 1];
            leftMaxHeight = max(leftMaxHeight, prevBarHeight);

            leftMaxArray[bar] = leftMaxHeight;
        }
    }

    void getRightMaxArray(int rightMaxArray[], vector<int> &heights)
    {
        int rightMaxHeight = 0, countOfBars = heights.size();

        for (int bar = countOfBars - 2; bar >= 0; bar--)
        {
            int nextBarHeight = heights[bar + 1];
            rightMaxHeight = max(rightMaxHeight, nextBarHeight);

            rightMaxArray[bar] = rightMaxHeight;
        }
    }

public:
    int trap(vector<int> &height)
    {
        int countOfBars = height.size();
        int totalWaterStoredOnAllBars = 0;

        int *leftMaxArray = new int[countOfBars];
        int *rightMaxArray = new int[countOfBars];

        getLeftMaxArray(leftMaxArray, height);
        getRightMaxArray(rightMaxArray, height);

        for (int bar = 1; bar < countOfBars - 1; bar++)
        {
            int barHeight = height[bar];
            int leftMaxBarHeight = leftMaxArray[bar];
            int rightMaxBarHeight = rightMaxArray[bar];

            int heightUptoWhichWaterStoredOnCurrentBar = min(leftMaxBarHeight, rightMaxBarHeight);
            int waterStoredOnCurrentBar = max(0, heightUptoWhichWaterStoredOnCurrentBar - barHeight);

            totalWaterStoredOnAllBars = totalWaterStoredOnAllBars + waterStoredOnCurrentBar;
        }

        delete[] leftMaxArray, rightMaxArray;
        return totalWaterStoredOnAllBars;
    }
};

// TC : O(N)
// SC : O(N)

// Approach 2 -- Two Pointers Space Optimised
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int totalWaterStoredOnAllBars = 0, leftPointer = 0, leftMaxHeight = height[leftPointer];
        int rightPointer = height.size() - 1, rightMaxHeight = height[rightPointer];

        while (leftPointer < rightPointer)
        {
            int waterCurrentBlockCanHold = 0;

            if (leftMaxHeight <= rightMaxHeight)
            {
                int currBarHeight = height[leftPointer];
                waterCurrentBlockCanHold = leftMaxHeight - currBarHeight;

                leftPointer = leftPointer + 1;
                leftMaxHeight = max(leftMaxHeight, height[leftPointer]);
            }

            else
            {
                int currBarHeight = height[rightPointer];
                waterCurrentBlockCanHold = rightMaxHeight - currBarHeight;

                rightPointer = rightPointer - 1;
                rightMaxHeight = max(rightMaxHeight, height[rightPointer]);
            }

            totalWaterStoredOnAllBars += waterCurrentBlockCanHold;
        }

        return totalWaterStoredOnAllBars;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}