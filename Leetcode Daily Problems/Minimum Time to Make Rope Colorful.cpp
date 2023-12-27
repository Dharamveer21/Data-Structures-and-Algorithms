#include <bits/stdc++.h>
using namespace std;

/*
Approach -- use a prev & next pointer to traverse the colors array , then when we find same color ballons , then put prev at first ballon of that color
and next at last ballon of that color , left the maximum neededTime ballon & remove the rest of them

store the maximum & the total Time for that interval , time taken for that interval will be totalTime - maximum time taken ballon
do this for each interval & we get the minimum time
*/

class Solution
{
public:
    int minTimeRemoveBallons(int start, int end, vector<int> &timeTaken)
    {
        int totalTime = 0, maxTime = 0;

        for (int ind = start; ind < end; ind++)
        {
            int time = timeTaken[ind];

            maxTime = max(maxTime, time);
            totalTime += time;
        }

        int minTime = totalTime - maxTime;
        return minTime;
    }

    int minCost(string colors, vector<int> &neededTime)
    {
        int ind = 0, n = colors.size();
        int firstBallon = 0, lastBallon = 0;
        int minCostColorRope = 0;

        while (lastBallon < n)
        {
            while (lastBallon < n && colors[firstBallon] == colors[lastBallon])
            {
                lastBallon++;
            }

            int cost = minTimeRemoveBallons(firstBallon, lastBallon, neededTime);

            minCostColorRope += cost;
            firstBallon = lastBallon;
        }

        return minCostColorRope;
    }
};

//  TC : O(N)
//  SC : O(1)

int main()
{

    return 0;
}