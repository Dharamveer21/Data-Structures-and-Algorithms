#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a dp problem we have to consider two paramaters , let func will returns us the value for minimum
Difficulty schedule for day starting with pth day and from index i to n

So, There are two parameters of the day number & the index of the array
We use MCM way in this question for any day we can do either 1 job or 2 job ... until there are remaining jobs
equal to remaning days . Now find the minimum of these schdeules as the minimum schedule

Base Case will be , when currDay is the last day then we have to do the all the remaining job on that day
Finally apply dp -- memoisation , tabulation & space optimization
*/

class Solution
{
public:
    // memoisation
    int minDifficultySchedule(int ind, int currDay, vector<int> &jobDifficulty, int &totalDays, vector<vector<int>> &scheduleHavingMinDifficulty)
    {
        int n = jobDifficulty.size();
        int daysLeft = totalDays - currDay;
        int maxDifficulty = jobDifficulty[ind];
        int minJobDifficultySchedule = 10001;

        if (scheduleHavingMinDifficulty[currDay][ind] != -1)
        {
            return scheduleHavingMinDifficulty[currDay][ind];
        }

        if (currDay == totalDays)
        {
            for (int i = ind; i < n - daysLeft; i++)
            {
                int difficulty = jobDifficulty[i];
                maxDifficulty = max(maxDifficulty, difficulty);
            }

            int jobDifficultySchedule = maxDifficulty;
            minJobDifficultySchedule = min(minJobDifficultySchedule, jobDifficultySchedule);
            return scheduleHavingMinDifficulty[currDay][ind] = minJobDifficultySchedule;
        }

        for (int i = ind; i < n - daysLeft; i++)
        {
            int difficulty = jobDifficulty[i];
            maxDifficulty = max(maxDifficulty, difficulty);

            int jobDifficultySchedule = maxDifficulty + minDifficultySchedule(i + 1, currDay + 1, jobDifficulty, totalDays, scheduleHavingMinDifficulty);
            minJobDifficultySchedule = min(minJobDifficultySchedule, jobDifficultySchedule);
        }

        return scheduleHavingMinDifficulty[currDay][ind] = minJobDifficultySchedule;
    }

    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();

        if (n < d)
        {
            return -1;
        }

        vector<vector<int>> scheduleHavingMinDifficulty(d + 1, vector<int>(n, -1));
        int scheduleWithMinimumDifficulty = minDifficultySchedule(0, 1, jobDifficulty, d, scheduleHavingMinDifficulty);
        return scheduleWithMinimumDifficulty;
    }

    // tabulation
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();

        if (n < d)
        {
            return -1;
        }

        vector<vector<int>> scheduleHavingMinDifficulty(d + 1, vector<int>(n, 0));

        for (int currDay = d; currDay >= 1; currDay--)
        {
            for (int ind = n - 1; ind >= 0; ind--)
            {
                int daysLeft = d - currDay;
                int maxDifficulty = jobDifficulty[ind];
                int minJobDifficultySchedule = 10001;

                if (currDay == d)
                {
                    for (int i = ind; i < n - daysLeft; i++)
                    {
                        int difficulty = jobDifficulty[i];
                        maxDifficulty = max(maxDifficulty, difficulty);
                    }

                    int jobDifficultySchedule = maxDifficulty;
                    minJobDifficultySchedule = min(minJobDifficultySchedule, jobDifficultySchedule);
                    scheduleHavingMinDifficulty[currDay][ind] = minJobDifficultySchedule;
                    continue;
                }

                for (int i = ind; i < n - daysLeft; i++)
                {
                    int difficulty = jobDifficulty[i];
                    maxDifficulty = max(maxDifficulty, difficulty);

                    int jobDifficultySchedule = maxDifficulty + scheduleHavingMinDifficulty[currDay + 1][i + 1];
                    minJobDifficultySchedule = min(minJobDifficultySchedule, jobDifficultySchedule);
                }

                scheduleHavingMinDifficulty[currDay][ind] = minJobDifficultySchedule;
            }
        }

        int scheduleWithMinimumDifficulty = scheduleHavingMinDifficulty[1][0];
        return scheduleWithMinimumDifficulty;
    }

    // space optimization
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();

        if (n < d)
        {
            return -1;
        }

        vector<int> currScheduleHavingMinDifficulty(n, 0);
        vector<int> nextScheduleHavingMinDifficulty(n, 0);

        for (int currDay = d; currDay >= 1; currDay--)
        {
            for (int ind = n - 1; ind >= 0; ind--)
            {
                int daysLeft = d - currDay;
                int maxDifficulty = jobDifficulty[ind];
                int minJobDifficultySchedule = 10001;

                if (currDay == d)
                {
                    for (int i = ind; i < n - daysLeft; i++)
                    {
                        int difficulty = jobDifficulty[i];
                        maxDifficulty = max(maxDifficulty, difficulty);
                    }

                    int jobDifficultySchedule = maxDifficulty;
                    minJobDifficultySchedule = min(minJobDifficultySchedule, jobDifficultySchedule);
                    currScheduleHavingMinDifficulty[ind] = minJobDifficultySchedule;
                    continue;
                }

                for (int i = ind; i < n - daysLeft; i++)
                {
                    int difficulty = jobDifficulty[i];
                    maxDifficulty = max(maxDifficulty, difficulty);

                    int jobDifficultySchedule = maxDifficulty + nextScheduleHavingMinDifficulty[i + 1];
                    minJobDifficultySchedule = min(minJobDifficultySchedule, jobDifficultySchedule);
                }

                currScheduleHavingMinDifficulty[ind] = minJobDifficultySchedule;
            }

            for (int ind = n - 1; ind >= 0; ind--)
            {
                nextScheduleHavingMinDifficulty[ind] = currScheduleHavingMinDifficulty[ind];
            }
        }

        int scheduleWithMinimumDifficulty = currScheduleHavingMinDifficulty[0];
        return scheduleWithMinimumDifficulty;
    }
};

// TC : O(D * N * N) = O(N^2 * D)
// SC : O(N)

int main()
{

    return 0;
}