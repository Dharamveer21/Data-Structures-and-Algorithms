#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Maintain a hash map & store the count of losses by each player & find the answer
As answer must be sorted , so get the sorted the array from a map , as map is already sorted
*/

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        int n = matches.size();
        map<int, int> lossCount;
        vector<vector<int>> players(2);

        for (int ind = 0; ind < n; ind++)
        {
            int winner = matches[ind][0];
            int loser = matches[ind][1];

            lossCount[winner] += 0;
            lossCount[loser] += 1;
        }

        for (pair<int, int> it : lossCount)
        {
            int player = it.first;
            int losses = it.second;

            if (losses == 0 || losses == 1)
            {
                int index = losses;
                players[index].push_back(player);
            }
        }

        return players;
    }
};

// TC : O(N * log(N))
// SC : O(N)

int main()
{

    return 0;
}