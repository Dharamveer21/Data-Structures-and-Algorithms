#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- It is a DP Problem , we can check if the given string is palindrome & we have to do it for all
possible strings. For every index "ind" as the starting index we take the ending index as (ind+1) to (n-1) .
Now , this is done using two loops . Then We apply memoisation while checking for the palindrome & tabulation.

Approach 2 -- We can use the fact that consider the s[ind] as the center of a odd Length palindrome & check
how many palindromes are possible for keeping it as center . We do it with all index .
We can also consider a s[ind] & s[ind+1] as the even length index for index "ind" & check how many such strings
are possible & count them . Finally we add both oddLen & evenLen for each index & returns the answer .
*/

// Approach 1
class Solution
{
protected:
    // memoisation
    bool isPalindromeString(int start, int end, string &str, vector<vector<int>> &isStringPalindrome)
    {
        if (start > end)
        {
            return 1;
        }

        if (isStringPalindrome[start][end] != -1)
        {
            return isStringPalindrome[start][end];
        }

        int isPalindrome = ((str[start] != str[end]) ? 0 : isPalindromeString(start + 1, end - 1, str, isStringPalindrome));
        return isStringPalindrome[start][end] = isPalindrome;
    }

public:
    int countSubstrings(string s)
    {
        int n = s.length(), palindromeCount = 0;
        vector<vector<int>> isStringPalindrome(n, vector<int>(n, -1));

        for (int start = 0; start < n; start++)
        {
            for (int end = start; end < n; end++)
            {
                palindromeCount = palindromeCount + isPalindromeString(start, end, s, isStringPalindrome);
            }
        }

        return palindromeCount;
    }

    // tabulation
    int countSubstrings(string s)
    {
        int n = s.length(), palindromeCount = 0;
        vector<vector<int>> isStringPalindrome(n, vector<int>(n, 0));

        for (int start = n - 1; start >= 0; start--)
        {
            for (int end = start; end < n; end++)
            {
                if (start == end || end - start == 1)
                {
                    isStringPalindrome[start][end] = (s[start] == s[end]);
                    palindromeCount = palindromeCount + isStringPalindrome[start][end];
                    continue;
                }

                isStringPalindrome[start][end] = ((s[start] != s[end]) ? 0 : isStringPalindrome[start + 1][end - 1]);
                palindromeCount = palindromeCount + isStringPalindrome[start][end];
            }
        }

        return palindromeCount;
    }
};

// TC : O(N^2)
// SC : O(N^2)

// Approach 2
class Solution
{
protected:
    int countPalindromeWithCenter(int start, int end, string &str)
    {
        int n = str.length(), palindromeCount = 0;

        while (start >= 0 && end < n)
        {
            if (str[start] != str[end])
            {
                break;
            }

            palindromeCount++;
            start--;
            end++;
        }

        return palindromeCount;
    }

public:
    int countSubstrings(string s)
    {
        int n = s.length(), palindromeCount = 0;

        for (int ind = 0; ind < n; ind++)
        {
            int oddPalindromeCount = countPalindromeWithCenter(ind, ind, s);
            int evenPalindromeCount = countPalindromeWithCenter(ind, ind + 1, s);

            palindromeCount = palindromeCount + oddPalindromeCount + evenPalindromeCount;
        }

        return palindromeCount;
    }
};

// TC : O(N^2)
// SC : O(1)

int main()
{

    return 0;
}