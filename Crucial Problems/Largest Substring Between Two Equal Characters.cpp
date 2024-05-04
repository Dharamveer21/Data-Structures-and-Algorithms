#include <bits/stdc++.h>
using namespace std;

/*
Find the first & last occurence of each character in the string & get the maximum value of (difference of
first & last position - 1) , the maximum value is the answer
The character having maximum difference is the answer
*/

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int n = s.length(), maxSubStringLength = -1;
        vector<pair<int, int>> charOccurrence(26, {-1, -1});

        for (int ind = 0; ind < n; ind++)
        {
            char ch = s[ind];
            int index = ch - 'a';

            int firstOccurrence = charOccurrence[index].first;
            int secondOccurrence = charOccurrence[index].second;

            if (firstOccurrence == -1)
            {
                firstOccurrence = ind;
            }

            secondOccurrence = max(secondOccurrence, ind);

            charOccurrence[index].first = firstOccurrence;
            charOccurrence[index].second = secondOccurrence;
        }

        for (int ind = 0; ind < 26; ind++)
        {
            int firstOccurrence = charOccurrence[ind].first;
            int secondOccurrence = charOccurrence[ind].second;

            int subStringLength = (secondOccurrence - firstOccurrence - 1);
            maxSubStringLength = max(maxSubStringLength, subStringLength);
        }

        return maxSubStringLength;
    }
};

// TC : O(N + 26) = O(N)
// SC : O(26) = O(1)

int main()
{

    return 0;
}