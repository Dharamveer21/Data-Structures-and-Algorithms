#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 --


Approach 2 --


K -- number of unique characters , K <= 26
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

// TC : O()
// SC : O()

// Approach 2
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
    }
};

// TC : O()
// SC : O()

int main()
{

    return 0;
}