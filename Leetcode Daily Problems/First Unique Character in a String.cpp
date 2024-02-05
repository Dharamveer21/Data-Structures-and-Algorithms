#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- create a arrCount array to store the count of each character & at last the element which is present
only 1 time is the required element who is non repeating in the array .
There may be more than one non repeating characters , so we start traversing from last & element that updated
last value of uniqueChar is the required character index which is first non repeating
*/

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int *arrCount = new int[26];
        int n = s.size(), uniqueChar = -1;
        fill(arrCount, arrCount + 26, 0);

        for (int ind = 0; ind < n; ind++)
        {
            char ch = s[ind];
            int index = ch - 'a';

            arrCount[index]++;
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            char ch = s[ind];
            int index = ch - 'a';

            int count = arrCount[index];
            uniqueChar = ((count == 1) ? ind : uniqueChar);
        }

        delete[] arrCount;
        return uniqueChar;
    }
};

// TC : O(N + N) = O(N)
// SC : O(26) = O(1)

int main()
{

    return 0;
}