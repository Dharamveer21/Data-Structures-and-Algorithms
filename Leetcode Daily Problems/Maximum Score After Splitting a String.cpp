#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Take a Count1 variable to count total Number of ones in the array then we traverse the array & take count of
0 and 1 in left part upto a particular index as left0 & Left1 then Count1 - left1 is total count of 1 in the right array
take there sum & find the maxSum
*/

class Solution
{
public:
    int maxScore(string s)
    {
        int leftCnt0 = 0, leftCnt1 = 0, rightCnt1 = 0;
        int count1 = count(s.begin(), s.end(), '1');
        int maxCount = 0;

        for (int ind = 0; ind < s.length() - 1; ind++)
        {
            char ch = s[ind];
            leftCnt0 += (ch == '0');
            leftCnt1 += (ch == '1');
            rightCnt1 = count1 - leftCnt1;

            int cnt = leftCnt0 + rightCnt1;
            maxCount = max(maxCount, cnt);
        }

        return maxCount;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}