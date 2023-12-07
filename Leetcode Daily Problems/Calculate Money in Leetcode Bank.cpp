#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Use Airthematic Progression formulaes for finding the sum mathematically
*/

class Solution
{
public:
    int totalMoney(int n)
    {
        int totalMoney = 0;
        const int weekSum = 28;
        int completeWeeksNum = (n / 7);
        int extraDays = (n % 7);
        
        totalMoney += (weekSum * completeWeeksNum);
        totalMoney += (7 * (((completeWeeksNum - 1) * (completeWeeksNum)) / 2));
        totalMoney += ((((extraDays) * (extraDays + 1)) / 2) + (extraDays * completeWeeksNum));

        return totalMoney;
    }
};

// TC : O(1)
// SC : O(1)

int main()
{

    return 0;
}