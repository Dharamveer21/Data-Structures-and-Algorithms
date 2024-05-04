#include <bits/stdc++.h>
using namespace std;

// Two Pointers
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int rightPointer = people.size() - 1;
        int minNumOfBoats = 0, leftPointer = 0;

        while (leftPointer <= rightPointer)
        {
            int lightWeight = people[leftPointer];
            int heavyWeight = people[rightPointer];

            if ((lightWeight + heavyWeight) <= limit)
                leftPointer++;

            rightPointer--;
            minNumOfBoats++;
        }

        return minNumOfBoats;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}