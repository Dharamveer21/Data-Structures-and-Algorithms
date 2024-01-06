#include <bits/stdc++.h>
using namespace std;

/*
Approach -- it is a dynamic programming program
first we have make a vector of pair<pair<int,int>,int> and sort it according to the starting time
once the vector is sorted then we try all cases . We either select a job or not select it

if we not select a job then we find maxProfit for (ind+1)
if we choose the current job then we find the next job from which we can choose
It will be the job whose starting time is greater than or equal to end time of current job
as the vector is sorted it will be the lower bound of endtime of the current job

The base case will be when there is no job left then profit = 0

Finally apply memoisation & tabulation
*/

class Solution
{
    static bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
    {
        if (a.first.first == b.first.first)
        {
            return (a.first.second < b.first.second);
        }

        return (a.first.first < b.first.first);
    }

public:
    // memoisation
    int nextPossibleJob(int num, int ind, vector<pair<pair<int, int>, int>> &arr)
    {
        int n = arr.size();
        int lo = ind, hi = n - 1;

        if (ind == n)
        {
            return n;
        }

        while (hi - lo > 1)
        {
            int mid = ((lo + hi) >> 1);
            int val = arr[mid].first.first;

            if (val < num)
            {
                lo = mid + 1;
            }

            else
            {
                hi = mid;
            }
        }

        int value1 = arr[lo].first.first;
        int value2 = arr[hi].first.first;

        if (value1 >= num || value2 >= num)
        {
            if (value1 >= num)
            {
                return lo;
            }

            return hi;
        }

        return n;
    }

    int maximumProfitSchedule(int ind, vector<pair<pair<int, int>, int>> &jobs, vector<int> &maxProfit)
    {
        int n = jobs.size();

        if (ind == n)
        {
            return 0;
        }

        if (maxProfit[ind] != -1)
        {
            return maxProfit[ind];
        }

        int startTime = jobs[ind].first.first;
        int endTime = jobs[ind].first.second;
        int profit = jobs[ind].second;

        int nextInd = nextPossibleJob(endTime, ind + 1, jobs);

        int maxProfitWithoutSelecting = maximumProfitSchedule(ind + 1, jobs, maxProfit);
        int maxProfitWithSelecting = profit + maximumProfitSchedule(nextInd, jobs, maxProfit);

        int maximumProfit = max(maxProfitWithoutSelecting, maxProfitWithSelecting);
        return maxProfit[ind] = maximumProfit;
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<pair<pair<int, int>, int>> jobs;
        vector<int> maxProfit(n, -1);

        for (int ind = 0; ind < n; ind++)
        {
            pair<pair<int, int>, int> job;

            job.first.first = startTime[ind];
            job.first.second = endTime[ind];
            job.second = profit[ind];

            jobs.push_back(job);
        }

        sort(jobs.begin(), jobs.end(), cmp);

        int maxScheduleProfit = maximumProfitSchedule(0, jobs, maxProfit);
        return maxScheduleProfit;
    }

    // tabulation
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<pair<pair<int, int>, int>> jobs;
        vector<int> maxProfit(n + 1, 0);

        for (int ind = 0; ind < n; ind++)
        {
            pair<pair<int, int>, int> job;

            job.first.first = startTime[ind];
            job.first.second = endTime[ind];
            job.second = profit[ind];

            jobs.push_back(job);
        }

        sort(jobs.begin(), jobs.end(), cmp);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int startTime = jobs[ind].first.first;
            int endTime = jobs[ind].first.second;
            int profit = jobs[ind].second;

            int nextInd = nextPossibleJob(endTime, ind + 1, jobs);

            int maxProfitWithoutSelecting = maxProfit[ind + 1];
            int maxProfitWithSelecting = profit + maxProfit[nextInd];

            int maximumProfit = max(maxProfitWithoutSelecting, maxProfitWithSelecting);
            maxProfit[ind] = maximumProfit;
        }

        int maxScheduleProfit = maxProfit[0];
        return maxScheduleProfit;
    }
};

// TC : O(N * log(N))
// SC : O(N)

int main()
{

    return 0;
}