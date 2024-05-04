#include <bits/stdc++.h>
using namespace std;

// Recursion & Memoisation
class Solution
{
protected:
    bool isStringPalindromic(int start, int end, string &str, vector<vector<int>> &palindrome)
    {
        if (start >= end)
            return true;

        if (palindrome[start][end] != -1)
            return palindrome[start][end];

        if (str[start] != str[end])
            return false;

        bool isPalindrome = isStringPalindromic(start + 1, end - 1, str, palindrome);
        return palindrome[start][end] = isPalindrome;
    }

public:
    string longestPalindrome(string &s)
    {
        int strLen = s.length(), startIndex = 0, maxLenPalindrome = 0;
        vector<vector<int>> palindrome(strLen, vector<int>(strLen, -1));

        for (int start = 0; start < strLen; start++)
        {
            for (int end = 0; end < strLen; end++)
            {
                if (isStringPalindromic(start, end, s, palindrome))
                {
                    int len = end - start + 1;

                    if (len > maxLenPalindrome)
                    {
                        startIndex = start;
                        maxLenPalindrome = len;
                    }
                }
            }
        }

        string longestPalindromicSubstring = s.substr(startIndex, maxLenPalindrome);
        return longestPalindromicSubstring;
    }
};

// TC : O(N * N)
// SC : O(N * N)

// Tabulation
class Solution
{
public:
    string longestPalindrome(string &s)
    {
        int strLen = s.length(), startIndex = 0, maxLenPalindrome = 0;
        vector<vector<bool>> palindrome(strLen, vector<bool>(strLen, false));

        for (int start = strLen - 1; start >= 0; start--)
        {
            for (int end = start; end < strLen; end++)
            {
                if (start == end || end - start == 1)
                    palindrome[start][end] = (s[start] == s[end]);

                else
                    palindrome[start][end] = ((s[start] != s[end]) ? false : palindrome[start + 1][end - 1]);

                if (palindrome[start][end])
                {
                    int len = end - start + 1;

                    if (len > maxLenPalindrome)
                    {
                        maxLenPalindrome = len;
                        startIndex = start;
                    }
                }
            }
        }

        string longestPalindromicSubstring = s.substr(startIndex, maxLenPalindrome);
        return longestPalindromicSubstring;
    }
};

// TC : O(N * N)
// SC : O(N * N)

// Expand from Centers
class Solution
{
public:
    string expand(int start, int end, string &str)
    {
        while (start >= 0 && end < str.length() && str[start] == str[end])
            start = start - 1, end = end + 1;

        return str.substr(start + 1, end - start - 1);
    }

    string longestPalindrome(string s)
    {
        string longestPalindromicSubstring;

        for (int ind = 0; ind < s.length(); ind++)
        {
            string odd = expand(ind, ind, s);
            string even = expand(ind, ind + 1, s);

            if (odd.size() > longestPalindromicSubstring.size())
                longestPalindromicSubstring = odd;

            if (even.size() > longestPalindromicSubstring.size())
                longestPalindromicSubstring = even;
        }

        return longestPalindromicSubstring;
    }
};

// TC : O(N * N)
// SC : O(1)

int main()
{

    return 0;
}