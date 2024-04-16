#include <bits/stdc++.h>
using namespace std;

// Sum of minimum of time of a person and kth person
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int numberOfTickets = tickets.size();
        int requiredPerson = k, requiredTime = 0;

        for (int person = 0; person < numberOfTickets; person++)
        {
            int timeTakenByCurrenPerson = tickets[person];
            int timeTakenByRequiredPerson = tickets[requiredPerson];

            if (person <= requiredPerson)
                requiredTime += min(timeTakenByCurrenPerson, timeTakenByRequiredPerson);

            else
                requiredTime += min(timeTakenByCurrenPerson, timeTakenByRequiredPerson - 1);
        }

        return requiredTime;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}