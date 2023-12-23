#include <bits/stdc++.h>
using namespace std;

/*
Approach -- store the mapping of moments direction vs their coordinate position
then start from origin & find the new position while traversing the array
find the new position , store it in the set , at each new postion check if this
position is present in the set or not
*/

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        unordered_set<string> visited;
        unordered_map<char, pair<int, int>> moments;
        moments['N'] = {0, 1};
        moments['E'] = {1, 0};
        moments['W'] = {-1, 0};
        moments['S'] = {0, -1};

        int initialX = 0, initialY = 0;
        visited.insert({"0 0"});

        for (int i = 0; i < path.size(); i++)
        {
            char direction = path[i];
            int momentX = moments[direction].first;
            int momentY = moments[direction].second;

            int finalX = initialX + momentX;
            int finalY = initialY + momentY;

            string position = to_string(finalX) + " " + to_string(finalY);

            if (visited.find(position) != visited.end())
            {
                return true;
            }

            initialX = finalX;
            initialY = finalY;
            visited.insert(position);
        }

        return false;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}