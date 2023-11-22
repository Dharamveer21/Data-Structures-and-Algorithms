#include <bits/stdc++.h>
using namespace std;

/*
Approach1 -- it is a graph problem for shortest path
here we can choose each route as the node of a graph & if any two routes have common stop then they are connected
by an edge -- this is the graph
there is no weights given , we will use bfs to find the shortest root from source (route) to destination (route)
*/

class Solution
{
private:
    static const int N = 1e5 + 10;
    vector<int> graph[N];
    int busRouteNo[N];

public:
    // to find common stops
    bool haveCommonStops(vector<int> &routes1, vector<int> &routes2)
    {
        int INF = 1e6 + 10;
        routes1.push_back(INF);
        routes2.push_back(INF);

        bool isCommon = false;
        int ind1 = 0, ind2 = 0;
        int n1 = routes1.size(), n2 = routes2.size();

        while (ind1 < n1 && ind2 < n2)
        {
            if (routes1[ind1] == routes2[ind2])
            {
                isCommon = true;

                if (routes1[ind1] == INF)
                {
                    isCommon = false;
                }

                break;
            }

            if (routes1[ind1] < routes2[ind2])
            {
                ind1++;
                continue;
            }

            if (routes1[ind1] > routes2[ind2])
            {
                ind2++;
            }
        }

        routes1.pop_back();
        routes2.pop_back();

        return isCommon;
    }

    // to find if particular stop exists on a given route
    bool isStopExists(vector<int> &route, int node)
    {
        int lo = 0, hi = route.size() - 1;

        while (hi - lo > 1)
        {
            int mid = ((lo + hi) >> 1);

            if (route[mid] < node)
            {
                lo = mid + 1;
                continue;
            }

            hi = mid;
        }

        return ((route[lo] == node || route[hi] == node));
    }

    // to add source routes in the queue which contains source as stop
    void addSourceRoutes(queue<int> &map, vector<vector<int>> &routes, int source)
    {
        for (int node = 0; node < routes.size(); node++)
        {
            if (isStopExists(routes[node], source))
            {
                busRouteNo[node] = 1;
                map.push(node);
            }
        }
    }

    // check if target stop exists on a particular route & its route number
    int CheckTargetStop(vector<int> &route, int node, int target)
    {
        if (!isStopExists(route, target))
        {
            return 0;
        }

        return busRouteNo[node];
    }

    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        int INF = 1e5 + 10;

        if (source == target)
        {
            return 0;
        }

        for (int ind = 0; ind < routes.size(); ind++)
        {
            busRouteNo[ind] = INF;
            sort(routes[ind].begin(), routes[ind].end());
        }

        for (int ind1 = 0; ind1 < routes.size(); ind1++)
        {
            for (int ind2 = ind1 + 1; ind2 < routes.size(); ind2++)
            {
                int node1 = ind1;
                int node2 = ind2;

                if (haveCommonStops(routes[node1], routes[node2]))
                {
                    graph[node1].push_back(node2);
                    graph[node2].push_back(node1);
                }
            }
        }

        queue<int> map;
        addSourceRoutes(map, routes, source);

        while (!map.empty())
        {
            int node = map.front();
            map.pop();

            int busStopNo = CheckTargetStop(routes[node], node, target);

            if (busStopNo)
            {
                return busStopNo;
            }

            for (int child : graph[node])
            {
                if (busRouteNo[child] > busRouteNo[node] + 1)
                {
                    busRouteNo[child] = busRouteNo[node] + 1;
                    map.push(child);
                }
            }
        }

        return -1;
    }
};

/*
Here, M is the size of routes, and K is the maximum size of routes[i].

TC : O(M^2 * K + M * K * log(K))
he createGraph method will iterate over every pair of M routes and for each iterate over the K stops to check if there is a common stop, this step will take O(M^2 * K) .
The addSourceRoutes method will iterate over all the M routes and check if the route has source in it, this step will take O(M * K).
In BFS, we iterate over each of the M routes, and for each route, we iterate over the adjacent route which could be M again, so the time it takes is O(M^2).
Sorting each routes[i] takes K * log⁡K time.

SC : O(M^2 + log(K))
The map adjList will store the routes for each route, thus the space it takes is O(M^2). The queue q and the set visited store the routes and hence can take O(M) space.
Some extra space is used when we sort routes[i] in place. The space complexity of the sorting algorithm depends on the programming language.
In C++, the sort() function is implemented as a hybrid of Quick Sort, Heap Sort, and Insertion Sort, with a worse-case space complexity of O(log⁡(K))
*/

/*
Approach2 -- here we can choose every stop as the node of the graph , we will create a graph by putting all the
routes as its children which involves the stop in it , we will not store the stops because its too memory taking
we will start a bfs from source routes (routes which contain source node) & vis all nodes in its routes & we put the
unvisited routes of these nodes in the queue
if we found the target we will return the busCount otherwise will continue
we also have to use a visited array to keep the tracked of the visited nodes ,after popout of a level of nodes we increase busCount
*/

class Solution
{
private:
    static const int N = 1e6 + 10;
    vector<int> graph[N];
    bool visRoute[N];
    int busCount = 0;

public:
    void AddSourceRoutes(queue<int> &map, int source)
    {
        for (int route : graph[source])
        {
            map.push(route);
            visRoute[route] = true;
        }
    }

    int checkTargetStop(vector<vector<int>> &routes, int node, int target)
    {
        for (int ind = 0; ind < routes[node].size(); ind++)
        {
            int stop = routes[node][ind];

            if (stop == target)
            {
                return busCount;
            }
        }

        return 0;
    }

    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
        {
            return 0;
        }

        for (int row = 0; row < routes.size(); row++)
        {
            int routeNumber = row;
            visRoute[routeNumber] = false;

            for (int col = 0; col < routes[row].size(); col++)
            {
                int stop = routes[row][col];
                graph[stop].push_back(routeNumber);
            }
        }

        queue<int> map;
        AddSourceRoutes(map, source);
        busCount = 1;

        while (!map.empty())
        {
            int size = map.size();

            for (int i = 0; i < size; i++)
            {
                int node = map.front();
                map.pop();

                int busRouteNo = checkTargetStop(routes, node, target);

                if (busRouteNo)
                {
                    return busRouteNo;
                }

                for (int ind = 0; ind < routes[node].size(); ind++)
                {
                    int stop = routes[node][ind];

                    for (int route : graph[stop])
                    {
                        if (!visRoute[route])
                        {
                            visRoute[route] = true;
                            map.push(route);
                        }
                    }
                }
            }

            busCount++;
        }

        return -1;
    }
};

/*
Here, M is the size of routes, and K is the maximum size of routes[i].

TC : O(M*K + M*K*M) == O(M^2 * K)
To store the routes for each stop we iterate over each route and for each route, we iterate over each stop, hence this step will take O(M*K) time. In the BFS, we iterate over each route in the queue. For each route we popped, we will iterate over its stop, and for each stop, we will iterate over the connected routes in the map adjList, hence the time required will be O(M * K * M)

Space complexity: O(M * K)
The map adjList will store the routes for each stop. There can be M * K number of stops in routes in the worst case (each of the M routes can have K stops), possibly with duplicates. When represented using adjList, each of the mentioned stops appears exactly once. Therefore, adjList contains an equal number of stop-route element pairs.
*/

int main()
{

    return 0;
}
