#include <bits/stdc++.h>
using namespace std;

/*
Approach -- First of all we will sort the given points array according to startBoundary . If any two or more
ballons overlap for some region then shooting a arrow in this common region will burst all the ballons .
Now we will keep the track of the prevInterval and whenver currInterval can be merged with prevInterval we
will update prevInterval as the common portion between them . If next interval is also going to merge with
first two for some common area then it must be overlapped with the prevInterval . If currInterval cannot be
merged with prevInterval then currInterval will become prevInterval and we update the arrow count by 1 more .
We only need to keep the track of just prevInterval due to the fact that if any interval is not overlapped with
just prev one then it is sure that it couldn't be overlapped with intevals before prevInterval as intervals are
sorted by startingBoundary . Finally return the count of the arrows required to burst all the ballons .
*/

class Solution
{
protected:
    bool canBeMerged(vector<int> &prevInterval, vector<int> &currInterval)
    {
        int prevEnd = prevInterval[1];
        int currStart = currInterval[0];

        return (prevEnd >= currStart);
    }

public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        vector<int> &prevInterval = points[0];
        int n = points.size(), countOfArrowShots = 1;

        for (int ind = 1; ind < n; ind++)
        {
            vector<int> &currInterval = points[ind];

            if (canBeMerged(prevInterval, currInterval))
            {
                int prevIntervalStart = prevInterval[0];
                int prevIntervalEnd = prevInterval[1];

                int currIntervalStart = currInterval[0];
                int currIntervalEnd = currInterval[1];

                int newIntervalStart = max(prevIntervalStart, currIntervalStart);
                int newIntervalEnd = min(prevIntervalEnd, currIntervalEnd);

                prevInterval = {newIntervalStart, newIntervalEnd};
                continue;
            }

            countOfArrowShots++;
            prevInterval = currInterval;
        }

        return countOfArrowShots;
    }
};

// TC : O(N * log(N) + N) = O(N * log(N))
// SC : O(1)

int main()
{

    return 0;
}