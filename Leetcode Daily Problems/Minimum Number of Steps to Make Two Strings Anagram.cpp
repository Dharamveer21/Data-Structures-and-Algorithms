#include <bits/stdc++.h>
using namespace std;

/*
Approach -- create a hash array of size 26 for count of each character
increment the count for string s & decrement the count for string t
then the count which remains positive are the count of charcters required to convert 't' into 's'
Take sum of these values
*/

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int len = s.length();
        int *characterCount = new int[26];
        fill(characterCount, characterCount + 26, 0);
        int minStepsToConvert = 0;

        for (int ind = 0; ind < len; ind++)
        {
            char ch1 = s[ind];
            char ch2 = t[ind];

            int index1 = ch1 - 'a';
            int index2 = ch2 - 'a';

            characterCount[index1]++;
            characterCount[index2]--;
        }

        for (int ind = 0; ind < 26; ind++)
        {
            cout << characterCount[ind] << endl;
            minStepsToConvert += max(0, characterCount[ind]);
        }

        delete[] characterCount;
        return minStepsToConvert;
    }
};

// TC : O(N + 26) = O(N)
// SC : O(26) = O(1)

int main()
{

    return 0;
}