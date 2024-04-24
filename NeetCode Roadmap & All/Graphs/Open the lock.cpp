#include <bits/stdc++.h>
using namespace std;

// Breadth First Search
class Solution
{
protected:
    void fillTheNextCombinations(string &currCombination, queue<string> &queueOfAllCombinations, unordered_set<string> &visitedCombination)
    {
        for (int pos = 0; pos < 4; pos++)
        {
            char ch = currCombination[pos];

            char decreaseChar = ((ch == '0') ? '9' : ch - 1);
            char increaseChar = ((ch == '9') ? '0' : ch + 1);

            currCombination[pos] = decreaseChar;

            if (visitedCombination.find(currCombination) == visitedCombination.end())
            {
                queueOfAllCombinations.push(currCombination);
                visitedCombination.insert(currCombination);
            }

            currCombination[pos] = increaseChar;

            if (visitedCombination.find(currCombination) == visitedCombination.end())
            {
                queueOfAllCombinations.push(currCombination);
                visitedCombination.insert(currCombination);
            }

            currCombination[pos] = ch;
        }
    }

public:
    int openLock(vector<string> &deadends, string target)
    {
        int minimumTurnsToOpenLock = -1;
        string startCombination = "0000";

        queue<string> queueOfAllCombinations;
        queueOfAllCombinations.push(startCombination);

        unordered_set<string> visitedCombination(deadends.begin(), deadends.end());

        if (visitedCombination.find(startCombination) != visitedCombination.end())
            return minimumTurnsToOpenLock;

        visitedCombination.insert(startCombination);

        while (!queueOfAllCombinations.empty())
        {
            int combinationsCount = queueOfAllCombinations.size();
            minimumTurnsToOpenLock = minimumTurnsToOpenLock + 1;

            while (combinationsCount--)
            {
                string currCombination = queueOfAllCombinations.front();
                queueOfAllCombinations.pop();

                if (currCombination == target)
                    return minimumTurnsToOpenLock;

                fillTheNextCombinations(currCombination, queueOfAllCombinations, visitedCombination);
            }
        }

        minimumTurnsToOpenLock = -1;
        return minimumTurnsToOpenLock;
    }
};

// N -- number of positions = 10 (0 To 9)
// W -- number of wheels = 4 ("0000")

// TC : O(N ^ W)
// SC : O(N ^ W)

int main()
{

    return 0;
}