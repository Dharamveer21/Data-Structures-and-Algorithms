#include <bits/stdc++.h>
using namespace std;

/*Partition dp try all cuts*/

class Solution
{
public:
    // memoisation
    int mini_cost_stick(int lo, int hi, vector<int> &cuts, vector<vector<int>> &mini_cost)
    {
        if (mini_cost[lo][hi] != -1)
        {
            return mini_cost[lo][hi];
        }

        int min_cost = 1e8 + 1;

        for (int cut = lo + 1; cut < hi; cut++)
        {
            int cost = cuts[hi] - cuts[lo];
            cost += mini_cost_stick(lo, cut, cuts, mini_cost);
            cost += mini_cost_stick(cut, hi, cuts, mini_cost);
            min_cost = min(min_cost, cost);
        }

        return mini_cost[lo][hi] = min_cost;
    }

    int minCost(int n, vector<int> &cuts)
    {
        vector<vector<int>> mini_cost(cuts.size() + 2, vector<int>(cuts.size() + 2, -1));

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        for (int i = 0; i < cuts.size() - 1; i++)
        {
            mini_cost[i][i + 1] = 0;
        }

        return mini_cost_stick(0, cuts.size() - 1, cuts, mini_cost);
    }

    // tabulation
    int minCost(int n, vector<int> &cuts)
    {
        int mini_cost[cuts.size() + 2][cuts.size() + 2];

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        for (int lo = cuts.size() - 1; lo >= 0; lo--)
        {
            for (int hi = lo + 1; hi < cuts.size(); hi++)
            {
                if (abs(hi - lo) == 1)
                {
                    mini_cost[lo][hi] = 0;
                    continue;
                }

                int min_cost = 1e8 + 10;

                for (int cut = lo + 1; cut < hi; cut++)
                {
                    int cost = cuts[hi] - cuts[lo];
                    cost += mini_cost[lo][cut];
                    cost += mini_cost[cut][hi];
                    min_cost = min(min_cost, cost);
                }

                mini_cost[lo][hi] = min_cost;
            }
        }

        return mini_cost[0][cuts.size() - 1];
    }
};

int main()
{

    return 0;
}