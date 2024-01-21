#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a dp problem where we can choose to rob in a particular house or not .
But there is also a constraint , if we have robbed a particular house we can't rob the next house

Hence when we consider dp[ind] as the amount we got when we start at index 'ind' , its value is equal
to max(dp[ind+1] , val[ind] + dp[ind+2])
*/

class Solution
{
public:
    // tabulation
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> maxMoneyFromRobbery(n + 2, 0);

        for (int house = n - 1; house >= 0; house--)
        {
            int MoneyWithRobbingHouse = nums[house] + maxMoneyFromRobbery[house + 2];
            int MoneyWithoutRobbingHouse = maxMoneyFromRobbery[house + 1];

            maxMoneyFromRobbery[house] = max(MoneyWithRobbingHouse, MoneyWithoutRobbingHouse);
        }

        int maxAmountFromRobbery = maxMoneyFromRobbery[0];
        return maxAmountFromRobbery;
    }

    // space optimisation
    int rob(vector<int> &nums)
    {
        int n = nums.size(), maxMoneyCurrHouse = 0;
        int maxMoneyNextHouse1 = 0, maxMoneyNextHouse2 = 0;

        for (int house = n - 1; house >= 0; house--)
        {
            int MoneyWithRobbingHouse = nums[house] + maxMoneyNextHouse2;
            int MoneyWithoutRobbingHouse = maxMoneyNextHouse1;

            maxMoneyCurrHouse = max(MoneyWithRobbingHouse, MoneyWithoutRobbingHouse);

            maxMoneyNextHouse2 = maxMoneyNextHouse1;
            maxMoneyNextHouse1 = maxMoneyCurrHouse;
        }

        int maxAmountFromRobbery = maxMoneyCurrHouse;
        return maxAmountFromRobbery;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}