#include <bits/stdc++.h>
using namespace std;

/*
Approach -- first of all we sort the array according to start of each interval - we can see merge intervals
We just have to check if current interval is overlapping with the last interval in sorted interval
list or not overlapping . If overlapping - we merge them , if not - we insert the interval in sorted merged
interval list . Now to check if two intervals are overlapping or not , we juts need to check if second intervals
start is <= end of first interval . For merging - start of first interval & max of end of both intervals
*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> mergedIntervals;

        sort(intervals.begin(), intervals.end());
        mergedIntervals.push_back(intervals[0]);

        for (int ind = 1; ind < n; ind++)
        {
            int lastIntervalStart = mergedIntervals.back()[0];
            int lastIntervalEnd = mergedIntervals.back()[1];

            int currIntervalStart = intervals[ind][0];
            int currIntervalEnd = intervals[ind][1];

            if (currIntervalStart <= lastIntervalEnd)
            {
                int mergedIntervalEnd = max(lastIntervalEnd, currIntervalEnd);
                mergedIntervals.back()[1] = mergedIntervalEnd;
                continue;
            }

            mergedIntervals.push_back(intervals[ind]);
        }

        return mergedIntervals;
    }
};

// TC : O(N * log(N) + N) = O(N * log(N)) -- for sorting & traversing
// SC : O(log(N) + N) = O(N) -- for sorting & storing the answer

int main()
{

    return 0;
}