#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int total_power = 0;
        int start_point = 0;
        bool check = true;
        queue<int> power;

        for (int i = 0; i < n; i++)
        {
            gas[i] = gas[i] - cost[i];
            total_power += gas[i];
            power.push(i);
        }

        if (total_power < 0)
        {
            return -1;
        }

        total_power = 0;

        // apply kadane algo in circular array
        while (check || power.front() != start_point)
        {
            int index = power.front();
            total_power += gas[index];
            power.pop();
            power.push(index);
            check = false;

            if (total_power < 0)
            {
                total_power = 0;
                start_point = power.front();
                check = true;
            }
        }

        return start_point;
    }
};

int main()
{

    return 0;
}