#include <bits/stdc++.h>
using namespace std;

/*
Approach -- The simple approach would be using BFS . We have to solve the problem by finding the lowest price
to reach a particular node from source using BFS , the only modification is that we can only traverse the
graph upto a particular level - k . because only that many number of stops are allowed .

Then we can finally return the updated price value of destination . But the main point to understand here is
we have to use a queue<pair<int,int>> rather than a queue<int> here . The reason is whenever we have two or more nodes in the queue , the ambiguity will come when the first node we pop out update the distance of the
coming nodes in the queue . Now, if we use price array & queue<int> then it will use the updated value and
gives the wrong answer . So we have to keep the last value to reach the node from its above level .

Hence we will use a queue<node, price> to get the last price to reach that node from its previous level &
use it to update the new level within the range of k stops .
*/

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> routes(n);
        int stopNum = 0, maxStopsAllowed = k, *price = new int[n];

        const int INF = 1e9 + 10;
        fill(price, price + n, INF);

        for (vector<int> &flight : flights)
        {
            int startStation = flight[0];
            int endStation = flight[1];
            int requiredPrice = flight[2];

            routes[startStation].push_back({endStation, requiredPrice});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        price[src] = 0;

        while (!q.empty() && stopNum <= maxStopsAllowed)
        {
            int size = q.size();

            while (size--)
            {
                pair<int, int> node = q.front();
                q.pop();

                int station = node.first;
                int priceToReachStation = node.second;

                for (pair<int, int> child : routes[station])
                {
                    int childStation = child.first;
                    int priceFromStationToChild = child.second;

                    int oldPriceFromSourceToChild = price[childStation];
                    int newPriceFromSourceToChild = priceToReachStation + priceFromStationToChild;

                    if (newPriceFromSourceToChild < oldPriceFromSourceToChild)
                    {
                        price[childStation] = newPriceFromSourceToChild;
                        q.push({childStation, newPriceFromSourceToChild});
                    }
                }
            }

            stopNum++;
        }

        int cheapestPrice = ((price[dst] == INF) ? -1 : price[dst]);

        delete[] price;
        return cheapestPrice;
    }
};

// N -- number of vertices , E -- number of edges
// TC : O(2 * E) = O(E)
// SC : O(N)

int main()
{

    return 0;
}