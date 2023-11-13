#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int mod = 1e9 + 7;
    int all_ways(int ind, int target, vector<vector<int>> &types, vector<vector<int>> &total_ways)
    {
        if (ind < 0)
        {
            return ((target == 0) ? 1 : 0);
        }

        if (total_ways[ind][target] != -1)
        {
            return total_ways[ind][target];
        }

        // don't take ind type of ques
        int sum = 0;
        int ways = (all_ways(ind - 1, target, types, total_ways) % mod);

        // take ind type of ques
        for (int i = 0; i < types[ind][0]; i++)
        {
            sum += types[ind][1];

            if (target - sum < 0)
            {
                break;
            }

            ways = ((ways % mod) + (all_ways(ind - 1, target - sum, types, total_ways) % mod));
        }

        return (total_ways[ind][target] = (ways % mod));
    }

    int waysToReachTarget(int target, vector<vector<int>> &types)
    {
        int n = types.size();
        vector<vector<int>> total_ways(n, vector<int>(target + 1, -1));
        return all_ways(n - 1, target, types, total_ways);
    }

    // tabulation
    int waysToReachTarget(int target, vector<vector<int>> &types)
    {
        int n = types.size();
        int mod = 1e9 + 7;
        vector<vector<int>> total_ways(n, vector<int>(target + 1));

        for (int ind = 0; ind < n; ind++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                int ques = types[ind][0];
                int marks = types[ind][1];

                if (ind == 0)
                {
                    int ways = (((tar % marks == 0) && (tar <= (ques * marks))) ? 1 : 0);
                    total_ways[ind][tar] = ways;
                    continue;
                }

                // don't take ind type of ques
                int sum = 0;
                int ways = (total_ways[ind - 1][tar] % mod);

                // take ind type of ques
                for (int i = 0; i < ques; i++)
                {
                    sum += marks;

                    if (tar - sum < 0)
                    {
                        break;
                    }

                    ways = ((ways % mod) + (total_ways[ind - 1][tar - sum] % mod));
                }

                total_ways[ind][tar] = (ways % mod);
            }
        }

        return total_ways[n - 1][target];
    }

    // space optimization
    int waysToReachTarget(int target, vector<vector<int>> &types)
    {
        int n = types.size();
        int mod = 1e9 + 7;
        vector<int> curr_ways(target + 1);
        vector<int> prev_ways(target + 1);

        for (int ind = 0; ind < n; ind++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                int ques = types[ind][0];
                int marks = types[ind][1];

                if (ind == 0)
                {
                    int ways = (((tar % marks == 0) && (tar <= (ques * marks))) ? 1 : 0);
                    curr_ways[tar] = ways;
                    continue;
                }

                // don't take ind type of ques
                int sum = 0;
                int ways = (prev_ways[tar] % mod);

                // take ind type of ques
                for (int i = 0; i < ques; i++)
                {
                    sum += marks;

                    if (tar - sum < 0)
                    {
                        break;
                    }

                    ways = ((ways % mod) + (prev_ways[tar - sum] % mod));
                }

                curr_ways[tar] = (ways % mod);
            }

            for (int tar = 0; tar <= target; tar++)
            {
                prev_ways[tar] = curr_ways[tar];
            }
        }

        return curr_ways[target];
    }
};

int main()
{

    return 0;
}