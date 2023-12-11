#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Check every two consecutive integers to get the count of each value as array is sorted
if freq > 25% it is the answer
*/

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size(), prevNum = -1;
        int freq = 0, maxFreq = n / 4;

        for (int ind = 0; ind < n; ind++)
        {
            int currNum = arr[ind];

            if (currNum != prevNum)
            {
                if (freq > maxFreq)
                {
                    return prevNum;
                }

                freq = 0;
                prevNum = currNum;
            }

            freq++;
        }

        return prevNum;
    }
};

// TC : O(N) -- traverse whole array
// TC : O(1)

int main()
{

    return 0;
}