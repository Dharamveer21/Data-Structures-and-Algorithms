#include <bits/stdc++.h>
using namespace std;

/*use dijkistra to find the minimum time & simuntaneously use the ways array*/
/*no of ways to reach any child is the sum of ways to reach all its parents in minimum time*/

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        const long long INF = LLONG_MAX;
        const int M = 1e9 + 7;

        vector<long long> time(n, INF);
        vector<long long> ways(n, 0);
        vector<pair<long long, long long>> graph[n];
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
   
        for (int i = 0; i < roads.size(); i++)
        {
            int ver1 = roads[i][0];
            int ver2 = roads[i][1];
            int tim = roads[i][2];

            graph[ver1].push_back({ver2, tim});
            graph[ver2].push_back({ver1, tim});
        }

        q.push({0, 0});
        ways[0] = 1;
        time[0] = 0;

        while (!q.empty())
        {
            auto val = q.top();
            q.pop();

            long long node = val.second;
            long long node_time = val.first;

            for (auto child : graph[node])
            {
                long long child_node = child.first;
                long long child_time = child.second;
                long long new_time = node_time + child_time;

                if (new_time <= time[child_node])
                {
                    if (new_time == time[child_node])
                    {
                        ways[child_node] = ((ways[child_node]) % M + (ways[node]) % M) % M;
                        continue;
                    }
 
                    time[child_node] = new_time;
                    q.push({time[child_node], child_node});
                    ways[child_node] = (ways[node]) % M;
                }
            }
        }

        return (ways[n - 1] % M);
    }
};

int main()
{

    return 0;
}