#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- sort both of them & compare them , if they are same or not
Approach 2 -- we store the frequency of each characters in a hashmap & compare them
*/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> charCount(26, 0);

        for (char &ch : s)
        {
            int ind = ch - 'a';
            charCount[ind]++;
        }

        for (char &ch : t)
        {
            int ind = ch - 'a';
            charCount[ind]--;
        }

        bool allZeros = all_of(charCount.begin(), charCount.end(), [](int element)
                               { return (element == 0); });
        return allZeros;
    }
};

// TC : O(N + 26) = O(N)
// SC : O(26) = O(1)

int main()
{

    return 0;
}