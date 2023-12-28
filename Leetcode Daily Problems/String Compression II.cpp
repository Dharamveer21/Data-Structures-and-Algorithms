#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a dp problem , we need to check all possibilities by deleting a particular character or not deleting it .

There are the things we need to keep track off -
1. The len of the run length encoding string
2. The previous character
3. Count of previous character
4. Num of characters we can remove
5. Index of the curr character

These are the possible cases :
If we are deleting the element at index "ind" then our string will concatenate , the last charcter for new call will be the character come as last charcter from previous call & its count
now the last character can be different or same as current character

If we do not delete the curr charcter then this character will become last character for the new call
Its count will be the count of the last charcter
now the last character can be different or same as current character

If the last character is different from curr character then curr Character count will be 1
and length of the string will be increased by 1

if the last character is same as current character then curr character count will be increased by 1
and length of the string will change only in these cases
if(currCount == 2 || currCount == 10 || currCount == 100) , len will be increased by 1

Finally we apply memoisation as dp
*/

int minRunLengthEncoding[101][101][27][101];

class Solution
{
public:
    int minLengthOfCompression(int ind, int canRemoveCount, int prevChar, int prevCharCount, string &str)
    {
        int n = str.length();

        if (canRemoveCount < 0)
        {
            return n;
        }

        if (ind == n)
        {
            return 0;
        }

        if (minRunLengthEncoding[ind][canRemoveCount][prevChar][prevCharCount] != -1)
        {
            return minRunLengthEncoding[ind][canRemoveCount][prevChar][prevCharCount];
        }

        int lenWithoutRemove = 0, lenWithRemove = 0;
        int currChar = str[ind] - 'a', currCharCount = 1;

        if (currChar == prevChar)
        {
            currCharCount += prevCharCount;
        }

        if (currCharCount == 1 || currCharCount == 2 || currCharCount == 10 || currCharCount == 100)
        {
            lenWithoutRemove++;
        }

        lenWithRemove = minLengthOfCompression(ind + 1, canRemoveCount - 1, prevChar, prevCharCount, str);
        lenWithoutRemove += minLengthOfCompression(ind + 1, canRemoveCount, currChar, currCharCount, str);

        int minLength = min(lenWithRemove, lenWithoutRemove);
        return minRunLengthEncoding[ind][canRemoveCount][prevChar][prevCharCount] = minLength;
    }

    int getLengthOfOptimalCompression(string s, int k)
    {
        memset(minRunLengthEncoding, -1, sizeof(minRunLengthEncoding));
        int minLength = minLengthOfCompression(0, k, 26, 0, s);
        return minLength;
    }
};

// TC : O(n * k * 26 * n) = O(n^2 * k)
// SC : O(n * k * 26 * n) = O(n^2 * k)

int main()
{

    return 0;
}