#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int max_profits(int day, int has_stock, vector<int> &prices, vector<vector<int>> &maxi_profit)
    {
        if (day == prices.size())
        {
            if (has_stock)
            {
                return -1e8;
            }

            return 0;
        }

        if (maxi_profit[day][has_stock] != -1)
        {
            return maxi_profit[day][has_stock];
        }

        // have stock
        if (has_stock)
        {
            // sell it
            int sell_profit = prices[day] + max_profits(day + 1, 0, prices, maxi_profit);

            // don't sell it
            int not_sell_profit = max_profits(day + 1, 1, prices, maxi_profit);

            return maxi_profit[day][has_stock] = max(sell_profit, not_sell_profit);
        }

        // don't have stock

        // buy it
        int buy_profit = (-1) * prices[day] + max_profits(day + 1, 1, prices, maxi_profit);

        // don't buy it
        int not_buy_profit = max_profits(day + 1, 0, prices, maxi_profit);

        return maxi_profit[day][has_stock] = max(buy_profit, not_buy_profit);
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> maxi_profit(n, vector<int>(2, -1));
        return max_profits(0, 0, prices, maxi_profit);
    }

    // tabulation
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxi_profit[n][2];

        for (int day = n - 1; day >= 0; day--)
        {
            for (int has_stock = 0; has_stock < 2; has_stock++)
            {
                // have stock
                if (day != 0 && has_stock)
                {
                    // sell it
                    int sell_profit = (day == n - 1) ? prices[day] : prices[day] + maxi_profit[day + 1][0];

                    // don't sell it
                    int not_sell_profit = (day == n - 1) ? INT_MIN : maxi_profit[day + 1][1];

                    maxi_profit[day][has_stock] = max(sell_profit, not_sell_profit);
                    continue;
                }

                // don't have stock

                // buy it
                int buy_profit = (day == n - 1) ? 0 : (-1) * prices[day] + maxi_profit[day + 1][1];

                // don't buy it
                int not_buy_profit = (day == n - 1) ? 0 : maxi_profit[day + 1][0];

                maxi_profit[day][has_stock] = max(buy_profit, not_buy_profit);
            }
        }

        return maxi_profit[0][0];
    }

    // space optimization
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int next_maxi_profit[2];
        int curr_maxi_profit[2];

        for (int day = n - 1; day >= 0; day--)
        {
            for (int has_stock = 0; has_stock < 2; has_stock++)
            {
                // have stock
                if (day != 0 && has_stock)
                {
                    // sell it
                    int sell_profit = (day == n - 1) ? prices[day] : prices[day] + next_maxi_profit[0];

                    // don't sell it
                    int not_sell_profit = (day == n - 1) ? INT_MIN : next_maxi_profit[1];

                    curr_maxi_profit[has_stock] = max(sell_profit, not_sell_profit);
                    continue;
                }

                // don't have stock

                // buy it
                int buy_profit = (day == n - 1) ? 0 : (-1) * prices[day] + next_maxi_profit[1];

                // don't buy it
                int not_buy_profit = (day == n - 1) ? 0 : next_maxi_profit[0];

                curr_maxi_profit[has_stock] = max(buy_profit, not_buy_profit);
            }

            for (int has_stock = 0; has_stock < 2; has_stock++)
            {
                next_maxi_profit[has_stock] = curr_maxi_profit[has_stock];
            }
        }

        return curr_maxi_profit[0];
    }
};

int main()
{

    return 0;
}