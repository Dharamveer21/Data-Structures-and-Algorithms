#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- It is a dp problem , we need to check all possibilities by deleting a particular character or not deleting it .
Here the func will return the minimum value of RLE string from a index "ind" to last .

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

In this approach , the number of calls will automatically keeping track of the length using prev Character
Finally we apply memoisation as dp which is 4D Dp

Approach 2 -- It can also be solved in 2D Dp , here the func will return the minimum value of RLE string from a index "ind" to last .
Here we use the concept that either we delete a character at index ind & calls for ind+1
or we keep the character at index ind and check its impacts on all the characters it can make , means upto
which character it can behave like a previous character , means upto its streak with amount of deletions

Find the minimum among them & check it with delete ind case & get the minimum ans
Finally use Dp but this time 2D Dp with only two dimensions , index & canRemoveCount

A special Base Case : If canRemoveCount >= remaining charcters in the string from ind to n , then we will
delete everyone & answer will be zero
*/

int minRunLengthEncoding[101][101][27][101];

class Solution
{
public:
    //  using 4D Dynamic Programming
    int minLengthOfCompression(int ind, int canRemoveCount, int prevChar, int prevCharCount, string &str)
    {
        int n = str.length();

        if (canRemoveCount < 0)
        {
            return n;
        }

        if (ind == n || (n - ind) <= canRemoveCount)
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

class Solution
{
public:
    // Using 2D Dynamic Programming
    int
    minLengthOfCompression(int ind, int canRemoveCount, string &str, vector<vector<int>> &minRunLengthEncoding)
    {
        int n = str.length();

        if (canRemoveCount < 0)
        {
            return n;
        }

        if (ind == n || (n - ind) <= canRemoveCount)
        {
            return 0;
        }

        if (minRunLengthEncoding[ind][canRemoveCount] != -1)
        {
            return minRunLengthEncoding[ind][canRemoveCount];
        }

        int lenWithRemove = 0, lenWithoutRemove = n;
        int currChar = str[ind] - 'a', currCharCount = 0;
        int charAdded = 0, charDeleted = 0;

        lenWithRemove = minLengthOfCompression(ind + 1, canRemoveCount - 1, str, minRunLengthEncoding);

        for (int i = ind; i < n && charDeleted <= canRemoveCount; i++)
        {
            int ch = str[i] - 'a';

            if (ch == currChar)
            {
                currCharCount++;

                if (currCharCount == 1 || currCharCount == 2 || currCharCount == 10 || currCharCount == 100)
                {
                    charAdded++;
                }
            }

            else
            {
                charDeleted++;
            }

            int len = charAdded + minLengthOfCompression(i + 1, canRemoveCount - charDeleted, str, minRunLengthEncoding);
            lenWithoutRemove = min(lenWithoutRemove, len);
        }

        int minLength = min(lenWithRemove, lenWithoutRemove);
        return minRunLengthEncoding[ind][canRemoveCount] = minLength;
    }

    int getLengthOfOptimalCompression(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> minRunLengthEncoding(n, vector<int>(k + 1, -1));

        int minLength = minLengthOfCompression(0, k, s, minRunLengthEncoding);
        return minLength;
    }
};

// TC : O(N^2 * K)
// SC : O(N * K)

int main()
{

    return 0;
}