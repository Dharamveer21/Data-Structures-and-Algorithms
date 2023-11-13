#include <bits/stdc++.h>
using namespace std;

/*
Simple -- just find max_selling_price for each buying price
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int max_selling_price = prices[n - 1];
        int max_profit = 0;

        for (int ind = n - 2; ind >= 0; ind--)
        {
            int buy_price = prices[ind];
            int sell_price = max(prices[ind + 1], max_selling_price);
            int profit = sell_price - buy_price;
            max_profit = max(max_profit, profit);
            max_selling_price = sell_price;
        }

        return max_profit;
    }
};

int main()
{

    return 0;
}