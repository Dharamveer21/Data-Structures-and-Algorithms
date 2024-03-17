#include <bits/stdc++.h>
using namespace std;

/*
Approach --
*/

class Solution
{
protected:
    bool isIndexValid(int index, int sizeOfVector)
    {
        return (index > -1 && index < sizeOfVector);
    }

    int justSmallerNumber(vector<int> &times, int start, int end, int time)
    {
        int n = times.size();
        int lo = start, hi = end;

        if (lo > hi)
        {
            return -1;
        }

        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;

            if (times[mid] < time)
            {
                lo = mid;
            }

            else
            {
                hi = mid - 1;
            }
        }

        if (isIndexValid(hi, n) && times[hi] < time)
        {
            return hi;
        }

        if (isIndexValid(lo, n) && times[lo] < time)
        {
            return lo;
        }

        return -1;
    }

    int justGreaterNumber(vector<int> &times, int start, int end, int time)
    {
        int n = times.size();
        int lo = start, hi = end;

        if (lo > hi)
        {
            return n;
        }

        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;

            if (times[mid] <= time)
            {
                lo = mid + 1;
            }

            else
            {
                hi = mid;
            }
        }

        if (isIndexValid(lo, n) && times[lo] > time)
        {
            return lo;
        }

        if (isIndexValid(hi, n) && times[hi] > time)
        {
            return hi;
        }

        return n;
    }

public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<int> startTimes, endTimes;
        vector<int> newUpdatedInterval(2);
        vector<vector<int>> finalIntervals;

        for (int ind = 0; ind < n; ind++)
        {
            int startTime = intervals[ind][0];
            int endTime = intervals[ind][1];

            startTimes.push_back(startTime);
            endTimes.push_back(endTime);
        }

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        int leftSideSafeIntervalsIndex = justSmallerNumber(endTimes, 0, n - 1, newStart);
        int rightSideSafeIntervalsIndex = justGreaterNumber(startTimes, 0, n - 1, newEnd);

        int newUpdatedStartTimeIndex = justSmallerNumber(startTimes, leftSideSafeIntervalsIndex + 1, rightSideSafeIntervalsIndex - 1, newStart);
        int newUpdatedEndTimeIndex = justGreaterNumber(endTimes, leftSideSafeIntervalsIndex + 1, rightSideSafeIntervalsIndex - 1, newEnd);

        int newUpdatedStartTime = ((newUpdatedStartTimeIndex == -1) ? (newStart) : (startTimes[newUpdatedStartTimeIndex]));
        int newUpdatedEndTime = ((newUpdatedEndTimeIndex == n) ? (newEnd) : (endTimes[newUpdatedEndTimeIndex]));

        newUpdatedInterval[0] = newUpdatedStartTime;
        newUpdatedInterval[1] = newUpdatedEndTime;

        for (int ind = 0; ind <= leftSideSafeIntervalsIndex; ind++)
        {
            finalIntervals.push_back(intervals[ind]);
        }

        finalIntervals.push_back(newUpdatedInterval);

        for (int ind = rightSideSafeIntervalsIndex; ind < n; ind++)
        {
            finalIntervals.push_back(intervals[ind]);
        }
        
        return finalIntervals;
    }
};

// TC : O()
// SC : O()

int main()
{

    return 0;
}