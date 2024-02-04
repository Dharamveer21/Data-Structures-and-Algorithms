#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Use sliding window method in this problem , consider a left pointer for starting value of the
window & right pointer for end of the window . We also use a unordered_map to find the count of each character
of the string "t" . We will also maintian the countRequired variable to get to know if current window is valid
or not . Whenever we move right pointer & if countRequired changed means we check if we can move left pointer
or not . If we can move it we will update the len & if currLen is less then prevLen means ans is changed

we have to do for things :-
1. update the right pointer & include new element
2. check if current window is valid or not using countRequired
3. move the left Pointer until the countRequired == 0
4. find newLen of window & if it is smaller then prevLen update ans
*/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        string minWindowString = "";
        unordered_map<char, int> charCount;
        int len = INT_MAX, countRequried = 0;
        int leftPtr = 0, rightPtr = -1, n = s.size();

        // store count of all elements of string t
        for (char ch : t)
        {
            charCount[ch]++;
            countRequried++;
        }

        for (int ind = 0; ind < n; ind++)
        {
            char currChar = s[ind];

            // add new character & update right pointer
            if (charCount.find(currChar) != charCount.end())
            {
                int currCount = charCount[currChar];

                if (currCount > 0)
                {
                    countRequried--;
                }

                charCount[currChar]--;
            }

            rightPtr++;

            // check if the given subarray is ans or not
            if (countRequried == 0)
            {
                // move leftPointer until the window is valid
                while (true)
                {
                    char currChar = s[leftPtr];

                    if (charCount.find(currChar) != charCount.end())
                    {
                        int currCount = charCount[currChar];

                        if (currCount == 0)
                        {
                            break;
                        }

                        charCount[currChar]++;
                    }

                    leftPtr++;
                }

                int newLen = rightPtr - leftPtr + 1;

                // check if current ans is smaller then prev or not & update it
                if (newLen < len)
                {
                    len = newLen;
                    minWindowString.clear();

                    for (int i = leftPtr; i <= rightPtr; i++)
                    {
                        char ch = s[i];
                        minWindowString.push_back(ch);
                    }
                }
            }
        }

        return minWindowString;
    }
};

// TC : O(M + N)
// SC : O(M + N)

int main()
{

    return 0;
}