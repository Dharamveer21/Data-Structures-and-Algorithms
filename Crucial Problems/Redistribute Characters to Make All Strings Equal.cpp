#include <bits/stdc++.h>
using namespace std;

/*
Approach -- find the frequencies of each character & it should be completely divisible by length of the vector
words , so that it will be present equally in each word

Take an array of size 26 to store the count of each character
*/

class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        vector<int> charCount(26, 0);

        for (int ind = 0; ind < n; ind++)
        {
            for (char &ch : words[ind])
            {
                int index = ch - 'a';
                charCount[index]++;
            }
        }

        for (int ind = 0; ind < 26; ind++)
        {
            int count = charCount[ind];

            if (count % n != 0)
            {
                return false;
            }
        }

        return true;
    }
};

// TC : O(N + 26) = O(N)
// SC : O(26) = O(1)

int main()
{

    return 0;
}