#include <bits/stdc++.h>
using namespace std;

/*
In both approachs the idea is that the maxFreq tasks are done first in each round . So that these tasks don't
get accumulated for last which will keep CPU more idle . Finish high freq using other tasks by CPU not idle .

Approach 1 -- This is a simple approach , we will store the frequency of each task in a maxFreqHeap . Now , the
gap between two indentical processes should be "n" means at a time we have to do (n+1) different tasks or keep
CPU idle if there are not enough different tasks . For this we will run a while loop until the maxFreqHeap gets
empty . Now , in the while loop we will run a for loop (n+1) times for each round and pop out the maxFreq tasks
first and store there freq in a vector and when this loop is finished (means when distinct (n+1) tasks are done
or the maxFreqHeap gets empty) . we have to push back (freq - 1) in the maxHeap again for next round and we will
add (n+1) in the ans each time in the last of the loop to indicate that (n+1) times CPU runs . But in the last
round when maxFreqHeap is still empty after pushing back (freq-1) means no element is remains , so we add the
size of vector which is last performed tasks . We use maxHeap to get high Freq task first in this approach .

Approach 2 -- In this approach we focus on the arragement of the tasks , we know that there must be atleast "n"
different tasks seprating two different tasks . Means these are the idle spots we need to fill . So , we need
maxFreq task from whole tasks . The reason is that every tasks freq is <= freq of maxFreq task means that every
element can come after maxFreq task one by one and no one will get repeated , so the usage of every task is not
a problem . Means consider the tasks as : A -- 5 times , B -- 5 times , C -- 4 times , D -- 2 times , n = 2 .
We can assign in this manner --> A__A__A__A__A , here we have to fill maximum of these idle spots using given
tasks frequencies . Let We fill all the positions using some tasks --> ABCABCABCABCA even now B -- 1 , D -- 2
are left behind but this is not a problem we can put them just after every A --> ABCDABCDABCABCAB because there
the tasks between two identical tasks should be atleast n , there is no upper limit we can put any number of
different tasks between them >= n . We know that the freq of any task is <= maxFreq task then every task can be
fitted in the arrangement . So , our only task is to fill as many idle spots as possible using different tasks .
So , we will take the freq array and sort it in descending order and take maxFreq and get (n) * (maxFreq-1) idle
spots . And type of idle spots as (maxFreq - 1) . While traversing the sorted freq array need to subtract the
min(freq , typeOfIdleSpots) from the idle spots . Because all the tasks can fill maximum "typeOfIdleSpots" these
many idle spots in its turn or less than this if its frequencies if less than this . This makes sure that all
idle spots between two consecutive maxFreq task is filled with different elements . Now , if at last the count
of idleSpots remaining is <= 0 means all are filled otherwise some are left . After the traversal of the freq
array , we return (number Of Idle Spots Remaining + sum of frequencies of all the tasks which is tasks.size()) .

N -- tasks.size() , K -- number of unique characters , K <= 26
*/

// Approach 1
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int leastIntervalCount = 0;
        int *taskFreq = new int[26]{};
        priority_queue<int> maxFreqHeap;
        int continuousTasksCount = n + 1;

        for (int ind = 0; ind < tasks.size(); ind++)
        {
            char ch = tasks[ind];
            int index = ch - 'A';

            taskFreq[index] += 1;
        }

        for (int task = 0; task < 26; task++)
        {
            int freq = taskFreq[task];

            if (freq > 0)
                maxFreqHeap.push(freq);
        }

        while (!maxFreqHeap.empty())
        {
            vector<int> taskCompletedInThisRound;

            for (int task = 1; task <= continuousTasksCount; task++)
            {
                if (maxFreqHeap.empty())
                    break;

                int maxFreq = maxFreqHeap.top();
                maxFreqHeap.pop();

                maxFreq = maxFreq - 1;
                taskCompletedInThisRound.push_back(maxFreq);
            }

            for (int task = 0; task < taskCompletedInThisRound.size(); task++)
            {
                int freq = taskCompletedInThisRound[task];

                if (freq > 0)
                    maxFreqHeap.push(freq);
            }

            if (maxFreqHeap.empty())
                leastIntervalCount += taskCompletedInThisRound.size();

            else
                leastIntervalCount += continuousTasksCount;
        }

        delete[] taskFreq;
        return leastIntervalCount;
    }
};

// TC : O(N * log(K))
// SC : O(K)

// Approach 2
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> taskFreq(26, 0);
        int minTasksBetweenIdenticalTasks = n;

        for (int ind = 0; ind < tasks.size(); ind++)
        {
            char task = tasks[ind];
            int index = task - 'A';

            taskFreq[index] += 1;
        }

        sort(taskFreq.begin(), taskFreq.end(), greater<int>());

        int maxFreq = taskFreq[0], typeOfIdleSpots = maxFreq - 1, freqSum = tasks.size();
        int countOfIdleSpots = (typeOfIdleSpots * minTasksBetweenIdenticalTasks);

        for (int task = 1; task < taskFreq.size(); task++)
        {
            int freq = taskFreq[task];
            int countOfIdleSpotsCanBeFilled = min(typeOfIdleSpots, freq);
            countOfIdleSpots = countOfIdleSpots - countOfIdleSpotsCanBeFilled;
        }

        countOfIdleSpots = ((countOfIdleSpots <= 0) ? 0 : countOfIdleSpots);
        int leastIntervalCount = freqSum + countOfIdleSpots;

        return leastIntervalCount;
    }
};

// TC : O(N + K * log(K))
// SC : O(K)

int main()
{

    return 0;
}