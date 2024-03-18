#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- As the start & end time are sorted we can find the left & right Portion of the intervals which is
safe from newInterval . And in case of the portion which is going to merge with interval we can find the lower
& upper values & then merge it . Finally append all in the answers array .

Approach 2 -- We can traverse the intervals & find if the current interval is less then newInterval then append
it in the answer if we find the interval which is going to merge with newInterval , we merged them & then update
the newInterval as merged interval continue , until we get and interval which is greater than newInterval . We
break the loop and append the updated newInterval & all other intervals greater than it in answer array .
*/

// Approach 1
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
            return -1;

        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;

            if (times[mid] < time)
                lo = mid;

            else
                hi = mid - 1;
        }

        if (isIndexValid(hi, n) && times[hi] < time)
            return hi;

        if (isIndexValid(lo, n) && times[lo] < time)
            return lo;

        return -1;
    }

    int justGreaterNumber(vector<int> &times, int start, int end, int time)
    {
        int n = times.size();
        int lo = start, hi = end;

        if (lo > hi)
            return n;

        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;

            if (times[mid] <= time)
                lo = mid + 1;

            else
                hi = mid;
        }

        if (isIndexValid(lo, n) && times[lo] > time)
            return lo;

        if (isIndexValid(hi, n) && times[hi] > time)
            return hi;

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

        int newStart = newInterval[0], newEnd = newInterval[1];

        int leftSideSafeIntervalsIndex = justSmallerNumber(endTimes, 0, n - 1, newStart);
        int rightSideSafeIntervalsIndex = justGreaterNumber(startTimes, 0, n - 1, newEnd);

        int newUpdatedStartTimeIndex = justSmallerNumber(startTimes, leftSideSafeIntervalsIndex + 1, rightSideSafeIntervalsIndex - 1, newStart);
        int newUpdatedEndTimeIndex = justGreaterNumber(endTimes, leftSideSafeIntervalsIndex + 1, rightSideSafeIntervalsIndex - 1, newEnd);

        int newUpdatedStartTime = ((newUpdatedStartTimeIndex == -1) ? (newStart) : (startTimes[newUpdatedStartTimeIndex]));
        int newUpdatedEndTime = ((newUpdatedEndTimeIndex == n) ? (newEnd) : (endTimes[newUpdatedEndTimeIndex]));

        newUpdatedInterval[0] = newUpdatedStartTime;
        newUpdatedInterval[1] = newUpdatedEndTime;

        for (int ind = 0; ind <= leftSideSafeIntervalsIndex; ind++)
            finalIntervals.push_back(intervals[ind]);

        finalIntervals.push_back(newUpdatedInterval);

        for (int ind = rightSideSafeIntervalsIndex; ind < n; ind++)
            finalIntervals.push_back(intervals[ind]);

        return finalIntervals;
    }
};

// TC : O(N * log(N))
// SC : O(N)

// Approach 2
class Solution
{
protected:
    int isIntervalSmallerGreaterOrCanBeMerged(vector<int> &interval, vector<int> &newInterval)
    {
        int currStart = interval[0], currEnd = interval[1];
        int newStart = newInterval[0], newEnd = newInterval[1];

        if (currEnd < newStart)
            return -1;

        if (currStart > newEnd)
            return 1;

        return 0;
    }

public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> finalIntervals;
        int n = intervals.size(), index = n;
        bool doesAnyMergingIntervalsLeft = true;

        for (int ind = 0; ind < n; ind++)
        {
            vector<int> &currInterval = intervals[ind];
            int relationOfIntervals = isIntervalSmallerGreaterOrCanBeMerged(currInterval, newInterval);

            switch (relationOfIntervals)
            {
            case -1:
                finalIntervals.push_back(currInterval);
                break;

            case 0:
                newInterval[0] = min(newInterval[0], currInterval[0]);
                newInterval[1] = max(newInterval[1], currInterval[1]);
                break;

            case 1:
                index = ind;
                doesAnyMergingIntervalsLeft = false;
            }

            if (!doesAnyMergingIntervalsLeft)
                break;
        }

        finalIntervals.push_back(newInterval);

        while (index < n)
        {
            vector<int> &interval = intervals[index];
            finalIntervals.push_back(interval);
            index++;
        }

        return finalIntervals;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}