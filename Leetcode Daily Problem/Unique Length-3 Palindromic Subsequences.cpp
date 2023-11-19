#include <bits/stdc++.h>
using namespace std;

// we only need to find palindrome of length 3 , that means last two elements must be equal , middle only can be any element
// we need to find the farthest locations of each alphabet in both left & right side . Then the number of unique elements present between these positions
// store the leftmost & rightmost loactions of each alphabet in two arrays
// Find the number of unique elements between any two indices by traversing for each alphabet

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.size();
        vector<int> lowest_pos(26, -1), highest_pos(26, -1);
        set<char> distinct;
        int palindrome_Cnt = 0;

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            int alphabet = ch - 'a';

            highest_pos[alphabet] = i;

            if (lowest_pos[alphabet] == -1)
            {
                lowest_pos[alphabet] = i;
            }
        }

        for (int ind = 0; ind < 26; ind++)
        {
            int lo = lowest_pos[ind] + 1;
            int hi = highest_pos[ind] - 1;
            distinct.clear();

            for (int i = lo; i <= hi; i++)
            {
                char ch = s[i];
                distinct.insert(ch);
            }

            int num_distinct_char = distinct.size();
            palindrome_Cnt += num_distinct_char;
        }

        return palindrome_Cnt;
    }
};

// TC : O(N + 26 * N) = O(N)
// SC : O(26 * 2) + O(26) = O(1)

int main()
{

    return 0;
}