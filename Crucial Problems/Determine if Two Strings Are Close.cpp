#include <bits/stdc++.h>
using namespace std;

/*
Approach -- first of all we are not adding or removing any charcter from the string , so the length of both
strings must be equal . Now , we are swapping any two elements means their count is not changing . Also in second
operation we convert one to character to another , another to that one .
Which means we are swapping the counts of the characters but the count still remains in the charCount array
Means if sort them , they must be equal . which means the value of a particular count is fix , but conversion
is possible only on same characters means both strings also must have same type of characters
*/

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int n1 = word1.length();
        int n2 = word2.length();

        if (n1 != n2)
        {
            return false;
        }

        bool isClose = true;
        int *charCount1 = new int[26];
        int *charCount2 = new int[26];

        fill(charCount1, charCount1 + 26, 0);
        fill(charCount2, charCount2 + 26, 0);

        for (int ind = 0; ind < n1; ind++)
        {
            char ch1 = word1[ind];
            char ch2 = word2[ind];

            int index1 = ch1 - 'a';
            int index2 = ch2 - 'a';

            charCount1[index1]++;
            charCount2[index2]++;
        }

        for (int ind = 0; ind < 26; ind++)
        {
            int count1 = charCount1[ind];
            int count2 = charCount2[ind];

            if ((count1 == 0 && count2 != 0) || (count1 != 0 && count2 == 0))
            {
                isClose = false;
                break;
            }
        }

        if (!isClose)
        {
            delete[] charCount1;
            delete[] charCount2;
            return isClose;
        }

        sort(charCount1, charCount1 + 26);
        sort(charCount2, charCount2 + 26);

        for (int ind = 0; ind < 26; ind++)
        {
            int count1 = charCount1[ind];
            int count2 = charCount2[ind];

            if (count1 != count2)
            {
                isClose = false;
                break;
            }
        }

        delete[] charCount1;
        delete[] charCount2;
        return isClose;
    }
};

// TC : O(N + 26) = O(N)
// SC : O(2 * 26) = O(1)

int main()
{

    return 0;
}