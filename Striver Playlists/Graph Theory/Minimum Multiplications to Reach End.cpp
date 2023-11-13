#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        const int N = 100000;
        const int INF = 1e9 + 10;

        vector<int> steps(N, INF);
        queue<pair<int, int>> q;

        q.push({0, start});
        steps[start] = 0;

        while (!q.empty())
        {
            auto node_val = q.front();
            q.pop();

            int step = node_val.first;
            int node = node_val.second;

            for (int i = 0; i < arr.size(); i++)
            {
                int child = (node * 1LL * arr[i]) % N;

                if (steps[child] > step + 1)
                {
                    steps[child] = step + 1;
                    q.push({steps[child], child});
                }
            }
        }

        if (steps[end] == INF)
        {
            return -1;
        }

        return steps[end];
    }
};

int main()
{

    return 0;
}