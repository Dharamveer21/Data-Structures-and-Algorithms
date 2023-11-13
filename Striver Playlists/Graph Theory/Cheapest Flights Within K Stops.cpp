#include <bits/stdc++.h>
using namespace std;

/*prioritise on the basis of stops -- first evalute the cost for p no. of stops then for p+1 no. of stops if cost can be reduced*/

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        const int INF = 1e9 + 10;
        vector<pair<int, int>> graph[n];

        for (int i = 0; i < flights.size(); i++)
        {
            int par = flights[i][0];
            int child = flights[i][1];
            int cost = flights[i][2];

            graph[par].push_back({child, cost});
        }

        vector<int> flight_cost(n, INF);
        queue<pair<pair<int, int>, int>> q;
        flight_cost[src] = 0;
        q.push({{0, 0}, src});

        while (!q.empty())
        {
            auto node_val = q.front();
            q.pop();

            int stops = node_val.first.first;
            int cost = node_val.first.second;
            int node = node_val.second;

            if (stops > k)
            {
                continue;
            }

            for (auto child : graph[node])
            {
                int child_node = child.first;
                int child_cost = child.second;

                if (flight_cost[child_node] > cost + child_cost)
                {
                    flight_cost[child_node] = cost + child_cost;
                    q.push({{stops + 1, cost + child_cost}, child_node});
                }
            }
        }

        if (flight_cost[dst] == INF)
        {
            return -1;
        }

        return flight_cost[dst];
    }
};

int main()
{

    return 0;
}