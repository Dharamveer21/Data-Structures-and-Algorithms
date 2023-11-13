#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tabulation
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<vector<int>> intitial_health(rows, vector<int>(cols));

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                int health = dungeon[i][j];
                int req_right, req_down, req;

                if (i == rows - 1 && j == cols - 1)
                {
                    intitial_health[i][j] = max(1, 1 - health);
                    continue;
                }

                if (i == rows - 1)
                {
                    req_right = intitial_health[i][j + 1];
                    intitial_health[i][j] = max(1, req_right - health);
                    continue;
                }

                if (j == cols - 1)
                {
                    req_down = intitial_health[i + 1][j];
                    intitial_health[i][j] = max(1, req_down - health);
                    continue;
                }

                req_right = intitial_health[i][j + 1];
                req_down = intitial_health[i + 1][j];
                req = min(req_right, req_down);

                intitial_health[i][j] = max(1, req - health);
            }
        }

        return intitial_health[0][0];
    }

    // space optimization
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<int> curr_intitial_health(cols);
        vector<int> next_intitial_health(cols);

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                int health = dungeon[i][j];
                int req_right, req_down, req;

                if (i == rows - 1 && j == cols - 1)
                {
                    curr_intitial_health[j] = max(1, 1 - health);
                    continue;
                }

                if (i == rows - 1)
                {
                    req_right = curr_intitial_health[j + 1];
                    curr_intitial_health[j] = max(1, req_right - health);
                    continue;
                }

                if (j == cols - 1)
                {
                    req_down = next_intitial_health[j];
                    curr_intitial_health[j] = max(1, req_down - health);
                    continue;
                }

                req_right = curr_intitial_health[j + 1];
                req_down = next_intitial_health[j];
                req = min(req_right, req_down);

                curr_intitial_health[j] = max(1, req - health);
            }

            for (int j = cols - 1; j >= 0; j--)
            {
                next_intitial_health[j] = curr_intitial_health[j];
            }
        }

        return curr_intitial_health[0];
    }
};

int main()
{

    return 0;
}