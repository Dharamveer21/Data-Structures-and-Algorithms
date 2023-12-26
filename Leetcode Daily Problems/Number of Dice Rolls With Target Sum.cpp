#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is again a dp problem , the brute force solution will be try all ways & use memoization
After that we can optimise it into tabulation & space optimization

Need a func function which will give us the output , lets say
if first dice roll a number "p" (1 <= p <= k) then answer will be number of ways of obtaining (target-p) sum
now for all possible "p" from 1 to k we have to sum the ways to get total ways
*/

class Solution
{
    static const int M = 1e9 + 7;

public:
    // memoisation
    int numWaysTargetSum(int numDice, int &diceValue, int targetSum, vector<vector<int>> &ways)
    {
        int totalWays = 0;

        if (targetSum < 0)
        {
            return totalWays;
        }

        if (ways[numDice][targetSum] != -1)
        {
            return ways[numDice][targetSum];
        }

        for (int dice = 1; dice <= diceValue; dice++)
        {
            totalWays = (totalWays + 0LL + numWaysTargetSum(numDice - 1, diceValue, targetSum - dice, ways)) % M;
        }

        return ways[numDice][targetSum] = totalWays;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> ways(n + 1, vector<int>(target + 1, -1));

        for (int sum = 0; sum <= target; sum++)
        {
            ways[0][sum] = ((sum == 0) ? 1 : 0);
        }

        int totalWays = numWaysTargetSum(n, k, target, ways);
        return totalWays;
    }

    // tabulation
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> ways(n + 1, vector<int>(target + 1, 0));
        ways[0][0] = 1;

        for (int numDice = 1; numDice <= n; numDice++)
        {
            for (int targetSum = 0; targetSum <= target; targetSum++)
            {
                int totalWays = 0;

                for (int dice = 1; dice <= k; dice++)
                {
                    totalWays = (totalWays + 0LL + ((targetSum - dice < 0) ? 0 : ways[numDice - 1][targetSum - dice])) % M;
                }

                ways[numDice][targetSum] = totalWays;
            }
        }

        int allPossibleWays = ways[n][target];
        return allPossibleWays;
    }

    // space optimization
    int numRollsToTarget(int n, int k, int target)
    {
        vector<int> prevDice(target + 1, 0), currDice(target + 1, 0);
        prevDice[0] = 1;

        for (int numDice = 1; numDice <= n; numDice++)
        {
            for (int targetSum = 0; targetSum <= target; targetSum++)
            {
                int totalWays = 0;

                for (int dice = 1; dice <= k; dice++)
                {
                    totalWays = (totalWays + 0LL + ((targetSum - dice < 0) ? 0 : prevDice[targetSum - dice])) % M;
                }

                currDice[targetSum] = totalWays;
            }

            for (int targetSum = 0; targetSum <= target; targetSum++)
            {
                prevDice[targetSum] = currDice[targetSum];
            }
        }

        int allPossibleWays = currDice[target];
        return allPossibleWays;
    }
};

//  TC : O(n * target * k)
//  SC : O(target)

int main()
{

    return 0;
}