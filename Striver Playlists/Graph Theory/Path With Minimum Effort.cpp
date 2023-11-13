#include <bits/stdc++.h>
using namespace std;

// Dijkstra algorithm using priority queue to set the mini dist -- approach 1
// use recursion is the 2nd approach

class Solution
{
public:
    bool isvalid(int &row, int &col, int &rows, int &cols)
    {
        if (row < 0 || row == rows || col < 0 || col == cols)
        {
            return false;
        }

        return true;
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        const int INF = 1e9 + 10;
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, INF));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        q.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!q.empty())
        {
            auto node = q.top();
            q.pop();

            int node_dist = node.first;
            int node_row = node.second.first;
            int node_col = node.second.second;

            if (node_row == rows - 1 && node_col == cols - 1)
            {
                return node_dist;
            }

            for (int i = 0; i < 4; i++)
            {
                int child_row = node_row + moments[i].first;
                int child_col = node_col + moments[i].second;

                if (isvalid(child_row, child_col, rows, cols))
                {
                    int new_dist = max((abs(heights[node_row][node_col] - heights[child_row][child_col])), node_dist);

                    if (new_dist < dist[child_row][child_col])
                    {
                        dist[child_row][child_col] = new_dist;
                        q.push({new_dist, {child_row, child_col}});
                    }
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }
};

int main()
{

    return 0;
}