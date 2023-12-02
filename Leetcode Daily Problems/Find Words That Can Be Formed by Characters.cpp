#include <bits/stdc++.h>
using namespace std;

/*
Approach -- frequency of each element in chars , compare it from the frequency of words[i]
*/

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int n = words.size();
        int ansLen = 0;
        int hashChars[26] = {0};

        for (int ind = 0; ind < chars.size(); ind++)
        {
            int index = chars[ind] - 'a';
            hashChars[index]++;
        }

        for (int ind = 0; ind < n; ind++)
        {
            bool check = true;
            int hashArr[26] = {0};

            for (int j = 0; j < words[ind].size(); j++)
            {
                char ch = words[ind][j];
                int index = ch - 'a';
                hashArr[index]++;
            }

            for (int j = 0; j < 26; j++)
            {
                if (hashArr[j] > hashChars[j])
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                ansLen += words[ind].size();
            }
        }

        return ansLen;
    }
};

// n = size of chars , m = size of words , k -- average size of words[i]
// TC : O(n + M * (k + 26)) = O(n + m * k)
// SC : O(26) = O(1)

int main()
{

    return 0;
}