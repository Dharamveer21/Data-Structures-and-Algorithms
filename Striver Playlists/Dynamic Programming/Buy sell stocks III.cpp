#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoisation
    int maximum_profit(int day, int has_stock, int tran_cnt, vector<int> &prices, vector<vector<vector<int>>> &max_profit)
    {
        if (tran_cnt == 0)
        {
            return 0;
        }

        if (day == prices.size())
        {
            if (has_stock)
            {
                return -1e8;
            }

            return 0;
        }

        if (max_profit[day][has_stock][tran_cnt] != -1)
        {
            return max_profit[day][has_stock][tran_cnt];
        }

        if (has_stock)
        {
            int sell_profit = prices[day] + maximum_profit(day + 1, 0, tran_cnt - 1, prices, max_profit);
            int not_sell_profit = maximum_profit(day + 1, 1, tran_cnt, prices, max_profit);

            return max_profit[day][has_stock][tran_cnt] = max(sell_profit, not_sell_profit);
        }

        int buy_profit = -1 * prices[day] + maximum_profit(day + 1, 1, tran_cnt, prices, max_profit);
        int not_buy_profit = maximum_profit(day + 1, 0, tran_cnt, prices, max_profit);

        return max_profit[day][has_stock][tran_cnt] = max(buy_profit, not_buy_profit);
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> max_profit(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return maximum_profit(0, 0, 2, prices, max_profit);
    }

    // tabulation
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int max_profit[prices.size()][2][3];

        for (int day = n - 1; day >= 0; day--)
        {
            for (int has_stock = 1; has_stock >= 0; has_stock--)
            {
                for (int tran_cnt = 0; tran_cnt < 3; tran_cnt++)
                {
                    if (has_stock)
                    {
                        int sell_profit = prices[day] + ((tran_cnt == 0) ? -1e8 : ((day == n - 1) ? 0 : max_profit[day + 1][0][tran_cnt - 1]));
                        int not_sell_profit = ((day == n - 1) ? INT_MIN : max_profit[day + 1][1][tran_cnt]);

                        max_profit[day][has_stock][tran_cnt] = max(sell_profit, not_sell_profit);
                    }

                    else
                    {
                        int buy_profit = -1 * prices[day] + ((day == n - 1) ? 0 : max_profit[day + 1][1][tran_cnt]);
                        int not_buy_profit = ((day == n - 1) ? 0 : max_profit[day + 1][0][tran_cnt]);

                        max_profit[day][has_stock][tran_cnt] = max(buy_profit, not_buy_profit);
                    }
                }
            }
        }

        return max_profit[0][0][2];
    }

    // space optimization
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int curr_max_profit[2][3];
        int next_max_profit[2][3];

        for (int day = n - 1; day >= 0; day--)
        {
            for (int has_stock = 1; has_stock >= 0; has_stock--)
            {
                for (int tran_cnt = 0; tran_cnt < 3; tran_cnt++)
                {
                    if (has_stock)
                    {
                        int sell_profit = prices[day] + ((tran_cnt == 0) ? -1e8 : ((day == n - 1) ? 0 : next_max_profit[0][tran_cnt - 1]));
                        int not_sell_profit = ((day == n - 1) ? INT_MIN : next_max_profit[1][tran_cnt]);

                        curr_max_profit[has_stock][tran_cnt] = max(sell_profit, not_sell_profit);
                    }

                    else
                    {
                        int buy_profit = -1 * prices[day] + ((day == n - 1) ? 0 : next_max_profit[1][tran_cnt]);
                        int not_buy_profit = ((day == n - 1) ? 0 : next_max_profit[0][tran_cnt]);

                        curr_max_profit[has_stock][tran_cnt] = max(buy_profit, not_buy_profit);
                    }
                }
            }

            for (int has_stock = 1; has_stock >= 0; has_stock--)
            {
                for (int tran_cnt = 0; tran_cnt < 3; tran_cnt++)
                {
                    next_max_profit[has_stock][tran_cnt] = curr_max_profit[has_stock][tran_cnt];
                }
            }
        }

        return curr_max_profit[0][2];
    }
};

int main()
{

    return 0;
}