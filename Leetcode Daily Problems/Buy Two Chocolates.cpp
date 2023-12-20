#include <bits/stdc++.h>
using namespace std;

/*
Approch 1 -- using sorting , check the sum of first two values is less than or greater than money or not

Approach 2 -- we find firstMin & SecondMin using traversal then check its sum with value
*/

class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int firstMinPrice = INT_MAX;
        int secondMinPrice = INT_MAX;

        for (int &price : prices)
        {
            if (price < firstMinPrice)
            {
                secondMinPrice = firstMinPrice;
                firstMinPrice = price;
            }

            else
            {
                secondMinPrice = min(secondMinPrice, price);
            }
        }

        int totalPrice = firstMinPrice + secondMinPrice;
        int moneyLeft = money - totalPrice;
        return ((moneyLeft >= 0) ? moneyLeft : money);
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}