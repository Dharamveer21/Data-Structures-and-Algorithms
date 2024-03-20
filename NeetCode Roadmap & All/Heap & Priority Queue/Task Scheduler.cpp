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
        stack<pair<int, char>> st;
        int continuousTasksCount = n + 1;
        priority_queue<pair<int, char>> taskSortedFreq;
        int leastIntervalCount = 0, *taskFreq = new int[26]{};

        for (int ind = 0; ind < tasks.size(); ind++)
        {
            char ch = tasks[ind];
            int index = ch - 'A';

            taskFreq[index] += 1;
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int task = ch - 'A';
            int freq = taskFreq[task];

            taskSortedFreq.push({freq, task});
        }

        while (!taskSortedFreq.empty())
        {
            while (continuousTasksCount--)
            {
                pair<int, char> maxFreqTask = taskSortedFreq.top();
                taskSortedFreq.pop();

                char task = maxFreqTask.second;
                int freq = maxFreqTask.first;

                freq = freq - 1;
                leastIntervalCount++;

                if (freq != 0)
                {
                    st.push({freq, task});
                }
            }

            while (!st.empty())
            {
                pair<int, char> taskFreq = st.top();
                st.pop();

                
            }
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