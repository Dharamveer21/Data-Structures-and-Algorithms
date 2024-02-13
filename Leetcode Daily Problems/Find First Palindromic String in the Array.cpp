#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can use two pointers to check palindrome also we can reverse the string & compare with original
these are easy approaches & simple ones but we can also use STL equal function for comparing the first half &
last half of the string directly in one line .

In STL -- s.begin() -- from starting of the string , here if we do ++ on iterator it moves forward
but STL -- s.rbegin() -- from ending of the string , here if we do ++ on iterator it moves backward
*/

class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        int n = words.size();

        for (string &word : words)
        {
            int compareLen = word.length() / 2;
            bool isPalindrome = equal(word.begin(), word.begin() + compareLen, word.rbegin());

            if (isPalindrome)
            {
                return word;
            }
        }

        return "";
    }
};

// N -- is length of words array & K -- average size of sting inside words
// TC : O(N * K)
// SC : O(1)

int main()
{
    return 0;
}