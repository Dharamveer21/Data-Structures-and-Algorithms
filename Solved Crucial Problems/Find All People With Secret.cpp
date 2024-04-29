#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a simple BFS question . We will start with person - 0 & firstPerson and we will take an array
timeOfSecret which will store the time at which the person got the secret . Whenever we pop out any person from
queue we traverse over its children and check simple logic that if the meeting time of child is after the time
at which person got the secret and meeting time is also less than time of secret of child then we will update
timeOfSecret of child as the meeting time & push it into the queue .

The reason for this is simple ,child will only get the secret if meeting is done after the person got secret
*/

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        const int INF = 1e9 + 10;
        int *timeOfSecret = new int[n];
        fill(timeOfSecret, timeOfSecret + n, INF);

        queue<int> q;
        vector<int> peopleWhoKnowsSecret;
        vector<vector<pair<int, int>>> scheduler(n);

        for (vector<int> &meeting : meetings)
        {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            scheduler[person1].push_back({person2, time});
            scheduler[person2].push_back({person1, time});
        }

        q.push(0);
        q.push(firstPerson);

        timeOfSecret[0] = 0;
        timeOfSecret[firstPerson] = 0;

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                int person = q.front();
                q.pop();

                for (pair<int, int> childSchedule : scheduler[person])
                {
                    int child = childSchedule.first;
                    int meetingTime = childSchedule.second;
                    int secretTimeForPerson = timeOfSecret[person];

                    if (secretTimeForPerson <= meetingTime && meetingTime < timeOfSecret[child])
                    {
                        timeOfSecret[child] = meetingTime;
                        q.push(child);
                    }
                }
            }
        }

        for (int person = 0; person < n; person++)
        {
            int time = timeOfSecret[person];
            bool doesPersonKnowSecret = (time != INF);

            if (doesPersonKnowSecret)
            {
                peopleWhoKnowsSecret.push_back(person);
            }
        }

        delete[] timeOfSecret;
        return peopleWhoKnowsSecret;
    }
};

// N -- number of people & M -- number of meetings
// TC : O(N + M)
// SC : O(N + M)

int main()
{

    return 0;
}