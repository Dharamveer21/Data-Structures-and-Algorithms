#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we have to pick all garbage , hence count the all occurences of G M & P
then add the values is the total time to pick ,
now to find the travel time for each truck . We just need to find the last occurence of M , P & G
which will decide the start (at house 0) & stop point for that respective truck
we will find its time in O(1) using prefix sum
*/

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        vector<int> stopPoint(3, -1);
        unordered_map<char, int> names = {{'G', 0}, {'M', 1}, {'P', 2}};
        int garbageCount = 0, totalTime = 0;

        for (int ind = 0; ind < garbage.size(); ind++)
        {
            for (int gar = 0; gar < garbage[ind].size(); gar++)
            {
                char garbageType = garbage[ind][gar];
                int index = names[garbageType];

                stopPoint[index] = ind;
                garbageCount++;
            }
        }

        totalTime += garbageCount;

        for (int ind = 1; ind < travel.size(); ind++)
        {
            travel[ind] += travel[ind - 1];
        }

        for (int ind = 0; ind < 3; ind++)
        {
            int stop = stopPoint[ind] - 1;

            if (stop > -1)
            {
                int timeTaken = travel[stop];
                totalTime += timeTaken;
            }
        }

        return totalTime;
    }
};

int main()
{

    return 0;
}