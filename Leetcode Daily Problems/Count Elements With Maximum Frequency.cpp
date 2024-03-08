#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can solve this question in 1 pass , here we can do take a freq array of size 100 , as the
constraints are <= 100 . If the constraints are high then we can use a unordered_map to store the frequencies .

We will take 1 maxFreq variable to store maxFreq till now , if the maxFreq is updated then we will update
maxFreqSum to maxFreq again , if it is not updated then we will add maxFreqSum with (freq == maxFreq) .
*/

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int *freqArr = new int[101]{};
        int maxFreq = 0, maxFreqSum = 0;

        for (int num : nums)
        {
            int freq = freqArr[num] + 1;
            int isRequired = (freq == maxFreq) + (freq >= maxFreq);

            switch (isRequired)
            {
            case 1:
                maxFreq = freq;
                maxFreqSum = freq;
                break;

            case 2:
                maxFreqSum = maxFreqSum + freq;
            }

            freqArr[num] = freq;
        }

        delete[] freqArr;
        return maxFreqSum;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}