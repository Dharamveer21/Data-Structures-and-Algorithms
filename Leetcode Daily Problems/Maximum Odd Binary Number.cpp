#include <bits/stdc++.h>
using namespace std;

/*
Approach -- swap the '0's at beginning with the '1's at the end in one pass
Finally swap the last one from beginning with 0 at end of the string
*/

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int n = s.length();
        int start = 0, end = n - 1;

        while (start <= end)
        {
            if (s[start] == '1')
            {
                start++;
                continue;
            }

            if (s[end] == '0')
            {
                end--;
                continue;
            }

            swap(s[start], s[end]);
            start++;
            end--;
        }

        swap(s[start - 1], s[n - 1]);
        return s;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}