#include <bits/stdc++.h>
using namespace std;

/*
Approach -- 1

here we are allowed to move anywhere up down left right which means its not a dp problem
also we need not to explore all paths , we just need the shortest path

we will use a graph & apply dijkstra to find the shortest path to every node but we have to use a priority queue
because if a node is visited a by lower value of k (remaining) first & set to minimum ,then the path with higher value of k (remaining) could not be able to push its children & it may lead to a long path because the lower value of k path could generate a larger path in future traversal due to shortage of k (remaining).

the priority queue will first allow the max k nodes to traverse down & assign the min distances to nodes
*/

class Solution
{
public:
    bool is_valid(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row == rows || col < 0 || col == cols)
        {
            return false;
        }

        return true;
    }

    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        const int INF = 1e9 + 10;

        vector<pair<int, int>> moments = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        priority_queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, INF));

        q.push({k, {0, 0}});
        dist[0][0] = 0;

        while (!q.empty())
        {
            auto node = q.top();
            q.pop();

            int power = node.first;
            int row = node.second.first;
            int col = node.second.second;
            int dis = dist[row][col];

            for (auto &moment : moments)
            {
                int child_row = row + moment.first;
                int child_col = col + moment.second;

                if (is_valid(child_row, child_col, grid))
                {
                    int child_dist = dist[child_row][child_col];

                    if (child_dist > dis + 1)
                    {
                        if ((grid[child_row][child_col] == 1) && (power > 0))
                        {
                            dist[child_row][child_col] = dis + 1;
                            q.push({power - 1, {child_row, child_col}});
                        }

                        else if (grid[child_row][child_col] == 0)
                        {
                            dist[child_row][child_col] = dis + 1;
                            q.push({power, {child_row, child_col}});
                        }
                    }
                }
            }
        }

        int ans = ((dist[rows - 1][cols - 1] == INF) ? -1 : dist[rows - 1][cols - 1]);
        return ans;
    }
};

int main()
{

    return 0;
}