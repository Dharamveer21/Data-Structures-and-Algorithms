#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a 2-pointer approach where we just need to move prefix & suffix pointers until only 1 element
remained or the charcter at start and end differs from each other . Here , keep in mind that move start pointer
until start < end but end pointer until start <= end to cover the all posibiliy that we would not miss one
occurrence of the character which is present in the middle multiple times .
*/

class Solution
{
public:
    int minimumLength(string &s)
    {
        int n = s.length(), len = 1;
        int start = 0, end = n - 1;

        while (start < end)
        {
            if (s[start] != s[end])
            {
                break;
            }

            char ch = s[start];

            while (start < end && s[start] == ch)
            {
                start++;
            }

            while (start <= end && s[end] == ch)
            {
                end--;
            }
        }

        len = end - start + 1;
        return len;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}