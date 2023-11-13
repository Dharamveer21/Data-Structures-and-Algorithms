#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int mini_cost_tickets(int day, vector<int> &days, vector<int> &costs, vector<int> &passes, vector<int> &min_costs)
    {
        if (min_costs[day] != -1)
        {
            return min_costs[day];
        }

        int min_cost = 366000;

        for (int i = 0; i < 3; i++)
        {
            int pass = passes[i];
            int cost = costs[i];

            auto it = lower_bound(days.begin(), days.end(), (day + pass));
            int final_day = it - days.begin();

            int rest_cost = cost + ((final_day != days.size()) ? (mini_cost_tickets(days[final_day], days, costs, passes, min_costs)) : (0));
            min_cost = min(min_cost, rest_cost);
        }

        return min_costs[day] = min_cost;
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> passes = {1, 7, 30};
        vector<int> min_costs(days[days.size() - 1] + 1, -1);
        return mini_cost_tickets(days[0], days, costs, passes, min_costs);
    }
    
    // tabulation
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> passes = {1, 7, 30};
        vector<int> min_costs(days[days.size() - 1] + 1, -1);

        for (int day = days[days.size() - 1]; day >= days[0]; day--)
        {
            int min_cost = 366000;

            for (int i = 0; i < 3; i++)
            {
                int pass = passes[i];
                int cost = costs[i];

                auto it = lower_bound(days.begin(), days.end(), (day + pass));
                int final_day = it - days.begin();

                int rest_cost = cost + ((final_day != days.size()) ? (min_costs[days[final_day]]) : (0));
                min_cost = min(min_cost, rest_cost);
            }

            min_costs[day] = min_cost;
        }

        return min_costs[days[0]];
    }
};

int main()
{

    return 0;
}