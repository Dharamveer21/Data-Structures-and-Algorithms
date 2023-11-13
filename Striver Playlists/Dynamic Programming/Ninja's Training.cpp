#include <bits/stdc++.h>
using namespace std;

// memoisation
int max_points(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    if (day == 0)
    {
        int mx_points = 0;

        for (int act = 0; act < 3; act++)
        {
            if (act != last)
            {
                mx_points = max(mx_points, points[0][act]);
            }
        }
        
        return dp[day][last] = mx_points;
    }

    int mx_points = 0;

    for (int act = 0; act < 3; act++)
    {
        if (act != last)
        {
            int point = points[day][act];
            point += max_points(day - 1, act, points, dp);
            mx_points = max(mx_points, point);
        }
    }

    return dp[day][last] = mx_points;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int mx_points = max_points(n - 1, 3, points, dp);
    return mx_points;
}

// tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // base case -- day == 0
    for (int last = 0; last < 4; last++)
    {
        for (int act = 0; act < 3; act++)
        {
            if (act != last)
            {
                int point = points[0][act];
                dp[0][last] = max(dp[0][last], point);
            }
        }
    }

    // other days
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            for (int act = 0; act < 3; act++)
            {
                if (act != last)
                {
                    int point = points[day][act] + dp[day - 1][act];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n - 1][3];
}

// space optimization
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> curr(4), prev(4);

    // base case -- day == 0
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    // other days
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            curr[last] = 0;

            for (int act = 0; act < 3; act++)
            {
                if (act != last)
                {
                    int point = points[day][act] + prev[act];
                    curr[last] = max(curr[last], point);
                }
            }
        }

        for (int last = 0; last < 4; last++)
        {
            prev[last] = curr[last];
        }
    }

    return curr[3];
}

int main()
{

    return 0;
}