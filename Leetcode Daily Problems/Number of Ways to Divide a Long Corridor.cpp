#include <bits/stdc++.h>
using namespace std;

/*
Approach -- it is a simple combinatorics problem
we just have to find number of partitions between each interval of 2 chairs & multiply them to find the all the ways of divisions
*/

class Solution
{
public:
    int numberOfWays(string corridor)
    {
        const int M = 1e9 + 7;
        vector<int> seatPositions;
        int numberChairs = 0;
        int n = corridor.size();
        int divisions = 1;

        for (int i = 0; i < n; i++)
        {
            char ch = corridor[i];

            if (ch == 'S')
            {
                int pos = i;
                seatPositions.push_back(i);
                numberChairs++;
            }
        }

        if ((numberChairs == 0) || (numberChairs & 1))
        {
            return 0;
        }

        for (int i = 1; i < numberChairs - 2; i += 2)
        {
            int currChairs = seatPositions[i];
            int nextChairs = seatPositions[i + 1];

            int plantsBetweenChairs = nextChairs - currChairs - 1;
            int partitions = plantsBetweenChairs + 1;

            divisions = (divisions * 1LL * partitions) % M;
        }

        return divisions;
    }
};

// TC : O(N + N/2) = O(N)
// SC : O(N)

int main()
{

    return 0;
}