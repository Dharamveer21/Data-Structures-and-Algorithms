#include <bits/stdc++.h>
using namespace std;

// Breadth First Search
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        int minimumTurnsToOpenLock = 0;
        queue<string> queueOfAllCombinations;
        unordered_map<string, bool> visitedCombination;

        queueOfAllCombinations.push("0000");
        visitedCombination["0000"] = true;

        while (!queueOfAllCombinations.empty())
        {
            int combinationsCount = queueOfAllCombinations.size();
            minimumTurnsToOpenLock = minimumTurnsToOpenLock + 1;

            while (combinationsCount--)
            {
            }
        }

        return minimumTurnsToOpenLock;
    }
};

// TC : O()
// SC : O()

int main()
{

    return 0;
}