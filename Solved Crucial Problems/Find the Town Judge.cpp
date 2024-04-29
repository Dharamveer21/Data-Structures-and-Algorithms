#include <bits/stdc++.h>
using namespace std;

/*
Approach --  here we can use a simple approach by taking an array to calculate the number of people trust the
given person (person will be treated as index) . Now we know that if someone trusts anyone then it can't be
town judge so we can put -1 in the array for that person . The second person in trust array will be the person
who will be trusted & we can increase its value in array then finally check if anyone has (n-1) value or not
Everyone will trust town judge means town judge should have (n-1) .

Here getting value as (n-1) makes it sure that all knows the town judge but how we will sure that town judge
knows no one . It is due to the fact that if town judge knows someone then we will make its value -1 . After
this even if everyone else knows it . Its value won't reach (n-1) ever .
*/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        int townJudge = -1, *numberOfPeopleTrusts = new int[n + 1]{};

        for (vector<int> &trustPair : trust)
        {
            int person1 = trustPair[0];
            int person2 = trustPair[1];

            numberOfPeopleTrusts[person1] = -1;
            numberOfPeopleTrusts[person2] += 1;
        }

        for (int person = 1; person <= n; person++)
        {
            int numberOfPeopleTrustPerson = numberOfPeopleTrusts[person];
            townJudge = (numberOfPeopleTrustPerson == n - 1) ? person : townJudge;
        }

        return townJudge;
    }
};

// TC : O(M + N) , M -- size of trust array , N -- number of people
// SC : O(N)

int main()
{

    return 0;
}