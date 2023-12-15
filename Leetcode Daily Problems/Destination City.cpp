#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- using hashmap , where we store the outgoing degree of each city
and the city having outgoing degree 0 is the answer

Approach 2 -- using hashset , where we store the first city of every path in the set
& then check the second city in the set . The last city which will not be present in set
will be the answer
*/

class Solution
{
public:
    // Approach 1
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> outDegreeCount;
        string ans;

        for (int ind = 0; ind < paths.size(); ind++)
        {
            string &firstCity = paths[ind][0];
            outDegreeCount[firstCity]++;
        }

        for (int ind = 0; ind < paths.size(); ind++)
        {
            string &secondCity = paths[ind][1];
            int outDegree = outDegreeCount[secondCity];

            if (outDegree == 0)
            {
                ans = secondCity;
                break;
            }
        }

        return ans;
    }

    // Approach 2
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> cityHavingOutDegree;
        string ans;

        for (int ind = 0; ind < paths.size(); ind++)
        {
            string &firstCity = paths[ind][0];
            cityHavingOutDegree.insert(firstCity);
        }

        for (int ind = 0; ind < paths.size(); ind++)
        {
            string &secondCity = paths[ind][1];

            if (cityHavingOutDegree.find(secondCity) == cityHavingOutDegree.end())
            {
                ans = secondCity;
                break;
            }
        }

        return ans;
    }
};

// TC : O(2 * N) = O(N) -- traversing whole paths array
// SC : O(2 * N) = O(N) -- storing each city

int main()
{

    return 0;
}