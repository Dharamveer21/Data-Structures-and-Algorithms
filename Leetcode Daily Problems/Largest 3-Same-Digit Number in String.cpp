#include <bits/stdc++.h>
using namespace std;

/*
Approach -- iterate over it simply and take a second pointer to check if the current substring is good or not
*/

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int ind = 0, maxi = -1;
        int n = num.size() - 2;
        string ans;

        while (ind < n)
        {
            char currChar = num[ind];

            char nextChar = num[ind + 1];
            char nextTonextChar = num[ind + 2];

            if (currChar != nextChar)
            {
                ind++;
                continue;
            }

            if (currChar != nextTonextChar)
            {
                ind += 2;
                continue;
            }

            int digit = currChar - '0';
            maxi = max(maxi, digit);
            ind += 3;
        }

        if (maxi != -1)
        {
            char ch = maxi + '0';

            for (int i = 0; i < 3; i++)
            {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};

// TC : O(N) -- length of string
// SC : O(1)

int main()
{

    return 0;
}